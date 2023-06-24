/*В системе «Умный дом» используется управляющий компьютер, который взаимодействует с различными приборами.
	Приборы подразделяются на несколько категорий:
1.	Счетчики электрической энергии
a.	Меркурий 230
b.	Нева МТ314
c.	Энергомера CE308

2.	Блоки ввода дискретных сигналов:
a.	Reallab NL-16HV
b.	Приборэлектро PRE-16
c.	Энергосервис ЭНМВ-1-24

3.	Блоки управления отоплением
a.	Ouman S203
b.	Овен ТРМ232

Получить данные от каждого прибора можно через метод

void poll() {
	std::cout << “Device name” << std::endl;
// Некоторая реализация получения данных, которую вам делать
// не нужно.
}

Для реализации конкретного проекта умного дома проектировщики могут выбрать, как правило, по одному прибору каждого типа. Тем не менее, программа должна поддерживать их все.

Предложите реализацию программы, которая могла бы считывать из файла названия приборов и формировать конфигурацию с учетом конкретного проекта.
Продемонстрируйте, как вы будете вызывать метод poll.

Пишите программу с учетом того, что в будущем количество прибором может возрасти.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Device
{
protected:

    std::string m_name;

public:

    Device(const std::string& name) : m_name(name) {}
    virtual ~Device() = default;

    virtual void Poll() 
    {
        std::cout << m_name << std::endl;
    }

    std::string Get_Name() const
    {
        return m_name;
    }
};
std::vector<Device> el_counters_vec = { Device("Меркурий 230"), Device("Нева МТ314"), Device("Энергомера CE308") };
std::vector<Device> input_vec = { Device("Reallab NL-16HV"), Device("Приборэлектро PRE-16"), Device("Энергосервис ЭНМВ-1-24") };
std::vector<Device> heat_contr_vec = { Device("Ouman S203"), Device("Овен ТРМ232") };
 //можно добавить любые устройства посредством добавления в вектор


class El_Counter : public Device
{
public:
    El_Counter(const std::string& name) : Device(name) {}
    virtual ~El_Counter() = default;

    virtual void Poll() override
    {
        std::cout << m_name << " EL " << std::endl;
    }
};

class Input_Unit : public Device
{
public:
    Input_Unit(const std::string& name) : Device(name) {}
    virtual ~Input_Unit() = default;
    virtual void Poll()  override
    {
        std::cout << m_name << " INP " << std::endl;
    }
};

class Heat_Contr_Unit : public Device
{
public:
    Heat_Contr_Unit(const std::string& name) : Device(name) {}
    virtual ~Heat_Contr_Unit() = default;
    virtual void Poll()  override
    {
        std::cout << m_name << " HEAT " << std::endl;
    }
};



int Dev_Set(const std::string& name, std::vector<Device>& final_set) //заполняет вектор конечной сборки
{
    for (int i = 0; i < el_counters_vec.size(); i++)
    {
        if (el_counters_vec[i].Get_Name() == name)
        {
            El_Counter pre_set(name);
            final_set.push_back(pre_set);
            pre_set.~El_Counter();
            return 1;
        }
    }

    for (int i = 0; i < input_vec.size(); i++)
    {
        if (input_vec[i].Get_Name() == name)
        {
            Input_Unit pre_set(name);
            final_set.push_back(pre_set);
            pre_set.~Input_Unit();
            return 2;
        }
    }

    for (int i = 0; i < heat_contr_vec.size(); i++)
    {
        if (heat_contr_vec[i].Get_Name() == name)
        {
            Heat_Contr_Unit pre_set(name);
            final_set.push_back(pre_set);
            pre_set.~Heat_Contr_Unit();
            return 3;
        }
    }

    return 0;
}



int main()
{
    std::vector<Device> Final_Set;
    setlocale(LC_ALL, "ru");
    std::ifstream dev_list;
    dev_list.open("set.txt");
    std::string cur_string;
    int counter = 0;

    // пустые пре-сетты
    El_Counter pres1("F");
    Input_Unit pres2("F");
    Heat_Contr_Unit pres3("F");
    //

    heat_contr_vec.push_back(Device("Ranger 500"));


    while (getline(dev_list, cur_string)) {
        int flag = Dev_Set(cur_string, Final_Set);
        if (flag != 0) 
        {
            switch (flag)
            {
            case(1):
                pres1 = (static_cast<El_Counter&>(Final_Set[counter]));
                pres1.Poll();
                break;

            case(2):
                pres2 = (static_cast<Input_Unit&>(Final_Set[counter]));
                pres2.Poll();
                break;

            case(3):
                pres3 = (static_cast<Heat_Contr_Unit&>(Final_Set[counter]));
                pres3.Poll();
                break;
            }
            counter++;
        }

        else 
        {
            std::cout << "Устройство:  " << cur_string << " не найдено." << std::endl;
        }
    }
}

