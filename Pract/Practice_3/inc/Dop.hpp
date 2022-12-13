#pragma once
#include <fstream>
#include <string>

namespace vm
{
	int WordCounter();
	void MostPopular(int* num_of_letters, std::string text[], std::string* pop_let, int x);
	void MasSorterDawnward(int* num_of_letters, std::string* pop_let);
	std::string ProofNForm(std::string* top_let, std::string* out_words, std::string* text, int x, int* mas, std::string* text_j);
	std::string Rus_Upper(std::string slovo);
	std::string Rus_Lower(std::string slovo);
};
