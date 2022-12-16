#include <iostream>
#include <vector>

void SeeMyVect(std::vector <int> ExemVect)
{
    std::cout << "Содержимое вектора:" << std::endl;
    for (int i = 0; i < ExemVect.size(); i++)
    {
        std::cout << ExemVect[i] << std::endl;
    }
    std::cout << " " << std::endl;
}

int main()
{
    /* ТЗ
    Изучите основные операции над вектором и продемонстрируйте их работу:

     1.	push_back, erase, insert
     2.	emplace_back
     3.	resize, reserve, shrink_to_fit, capacity
     4.	clear
     5.	оператор присваивания и []

     Узнайте размер вектора и будьте готовы объяснить, почему именно так.
    */

    setlocale(LC_ALL, "Russian");

    //  1.	push_back, erase, insert
    //
    //
    //
    std::vector <int> ExemVec = { 11, 28,36,16,666 };
    SeeMyVect(ExemVec);
    // push_back - копирует вводимое значение, после чего "заталкивает" его в конец вектора
    ExemVec.push_back(33);
    SeeMyVect(ExemVec);
    //
    //
    // 
    // Для начала  - итератор это некое подобие указателя на вектор (можно выбрать на что именно он будет указывать, например через .begin() или .end()
    // Для использования erase и insert требуется создавать итератор!
    // erase - удаляет элемент по указанному итератору и смещает все остальные элементы
    std::vector<int>::iterator iter_f = ExemVec.begin(); //удалим первый элемент
    ExemVec.erase(iter_f);
    SeeMyVect(ExemVec);
    //
    // 
    //insert - заменяет элемент вектора, указанный по его итератору на введённый 
    std::vector<int>::iterator iter_f1 = ExemVec.begin();
    ExemVec.insert(iter_f1, 82);
    SeeMyVect(ExemVec);
    //
    //
    //
    // 2.	emplace_back
    //emplace_back - добавляет элемент в конец вектора БЕЗ КОПИРОВАНИЯ, поэтому работает быстрее
    ExemVec.emplace_back(2);
    SeeMyVect(ExemVec);
    // 3.	resize, reserve, shrink_to_fit, capacity
    //
    // 
    // resize - ручное переопределение раземерности вектора, если  оно больше нынешнего - добавляет память, если меньше - срезает значения до указанного индекса
    ExemVec.resize(3);
    SeeMyVect(ExemVec);

    // capacity - выводит ёмкость, максимальное количество элементов, которые можно вместить без вызова к памяти
    std::cout << "Капасити равен: "<< ExemVec.capacity() << std::endl;

    // reserve - резервирует n ячеек пямяти для вектора (работает только если n > нынешнего капасити)
    ExemVec.reserve(9);
    std::cout << "После ресерв капасити равен: " << ExemVec.capacity() << std::endl;
    // shrink_to_fit - освобождает все зарезервированные (неиспользованные) ячейки памяти
    ExemVec.shrink_to_fit();
    std::cout << "После shrink капасити равен: " << ExemVec.capacity() << std::endl; 

    //4. clear
    // clear - очищает вектор (удаляет ВСЕ элементы из вектора), 
    ExemVec.clear();
    SeeMyVect(ExemVec);

    //  5.	оператор присваивания и []
    //присваивание, мы можем присвоить содержимое одного вектора другому (заменить все значения и изменить его размерность)

    ExemVec = { 36, 28, 36, 28, 666 };
    std::vector <int> ExemVec_jun = { 12,45};
    ExemVec = ExemVec_jun;
    SeeMyVect(ExemVec);

    // [] - присваивание для отдельных элементов (элементу другого вектора по индексу или иному объекту)
    ExemVec[0] = 12121212;
    ExemVec_jun[0] = ExemVec[0];
    SeeMyVect(ExemVec_jun);

    ExemVec = { 36, 28, 36, 28, 666, 56456, 4352436, 2345236, 567354, 43535 };
    std::cout << " ///////" << std::endl;
    std::cout << sizeof(ExemVec)/8 << " Байта";
    // Насколько я понимаю, это связано с тем, что вектор - это по сути  указатель на первый элемент, а указатель на инт занимает как раз 4 байта
}