#include <Dop.hpp>
#include <iostream>
#include <fstream>
#include <string>

int main()
{

	setlocale(LC_ALL, "Rus");

	std::ifstream in("input.txt", std::ios::in);
	std::ofstream out("output.txt", std::ios::out);
	int AmountWords = vm::WordCounter();
    std::string* text = new std::string[AmountWords];
	std::string* dup_text = new std::string[AmountWords];
	std::string* out_words = new std::string[AmountWords];
	int* mas = new int[AmountWords];
	int l = 0;
	while (!in.eof())
	{
		in >> text[l];
		l += 1;
	};

	for (int h = 0; h < AmountWords; h++)
		dup_text[h] = vm::Rus_Lower(text[h]);
	//

	std::string slova[100];
	int num_of_letters[33] = {0};
	std::string pop_let [33];
	std::string top_let[5];
	for (int s = 0; s < 33; s++) { pop_let[s] = " "; }


	vm::MostPopular(num_of_letters, dup_text, pop_let, AmountWords);
	vm::MasSorterDawnward(num_of_letters,pop_let);
	for (int t = 0; t < 5; t++) { top_let[t] = pop_let[t]; }
	for (int t = 0; t < AmountWords; t++) { mas[t] = -1;}

	/*for (int s = 0; s < 33; s++) { std::cout << pop_let[s] << " "; };

	std::cout << "" << std::endl;

	for (int s = 0; s < 33; s++) { std::cout << num_of_letters[s] << " "; };

	std::cout << "" << std::endl; */

	std::string C;
	C = vm::ProofNForm(top_let, out_words, dup_text, AmountWords, mas,text);

	/*for (int i = 0; i < AmountWords; i++)
	{
		std::cout << text[i] << "";

	}
	//std::cout << "" << std::endl;

	for (int i = 0; i < AmountWords; i++)
	{
		std::cout << mas[i] << " ";
	}*/

	std::cout << C << std::endl;
	out << C;
	delete[]out_words; // замененые слова
	delete[] mas; // номера заменяемых слов
	//delete[] text; (!)
}
/*Вариант 1
В текстовом файле input.txt записан русский текст.
Найти в тексте слова, содержащие не менее четырех из пяти наиболее часто встречающихся букв текста,
записать их заглавными буквами и указать после каждого такого слова в скобках найденные буквы.
Полученный текст записать в файл output.txt. 
Весь текст, кроме найденных слов, должен остаться неизменным, включая и знаки препинания.
std::ifstream in("inp.txt", std::ios::in);
std::+
*/ 

// Полезные вещи:
/*for (int s = 0; s < words; s++) { std::cout << "text [" << s << "] = " << text[s] << std::endl; }
	std::cout << words;*/ 
//proverka texta v massive
//	for (int s = 0; s < 32; s++) { std::cout << Letters[s] << std::endl; }
