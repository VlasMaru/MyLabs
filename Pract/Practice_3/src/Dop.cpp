#include <Dop.hpp>
#include <iostream>
#include <fstream>
#include <string>

namespace vm
{
	int WordCounter()
	{
		int l = 0;
		std::string temp;
		std::ifstream in("input.txt", std::ios::in);
		while (!in.eof())
		{
			in >> temp;
			l += 1;
		}
		return (l);
	};

	void MostPopular(int* num_of_letters,std::string text[],std::string* pop_let,int x)
	{
		char let_ru[] = {'à', 'á', 'â', 'ã', 'ä', 'å', '¸', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'ü', 'û', 'ú', 'ý', 'þ', 'ÿ'};
		for (int h = 0; h < x; h++) // x - amount of words
		{
			for (int b = 0; b < text[h].length(); b++)
				for (int p = 0; p < 33; p++)
				{
					if (text[h][b] == let_ru[p]) 
					{ num_of_letters[p] += 1;
					  pop_let[p][0] = let_ru[p];
					
					}
				}

		}
	}
	void MasSorterDawnward(int* num_of_letters, std::string* pop_let)
	{
		for (int y =0; y<32;y++)
			for (int t = y + 1; t < 33; t++)
			{
				if (num_of_letters[y] < num_of_letters[t])
				{
					std::swap(num_of_letters[y], num_of_letters[t]);
					std::swap(pop_let[y], pop_let[t]);
				}
			}
	}

	std::string Rus_Upper(std::string slovo)
	{
		for (int u = 0; u < slovo.length(); u++)
		{
			if ((int(slovo[u]) >= (-32)) && (int(slovo[u]) <0))
			{
				slovo[u] = char(int(slovo[u]) - 32);
			}
		}
		return slovo;
	}

	std::string Rus_Lower(std::string slovo)
	{
		for (int u = 0; u < slovo.length(); u++)
		{
			if ((int(slovo[u]) < (-32)) && (int(slovo[u]) < 0))
			{
				slovo[u] = char(int(slovo[u]) + 32);
			}
		}
		return slovo;
	}

	std::string ProofNForm(std::string* top_let, std::string* out_words, std::string* text, int x, int* mas, std::string* text_j)
	{
		int proof_flag, counter, mini_counter;
		std::string C;
		proof_flag = counter = mini_counter = 0;
		std::string work_letter[5];
		for (int l = 0; l < 5; l++) { work_letter[l] = "";}
		for (int p = 0; p < x; p++) // slova
		{
			for (int j = 0; j <  text[p].length(); j++) // bykvi
			{
				for (int h = 0; h < 5; h++) 
				{
					if ((text[p][j] == top_let[h][0]) && (top_let[h][0] != work_letter[0][0]) && (top_let[h][0] != work_letter[1][0]) && (top_let[h][0] != work_letter[2][0]) && (top_let[h][0] != work_letter[3][0]) && (top_let[h][0] != work_letter[4][0]))
					{ proof_flag += 1;
					  work_letter[mini_counter] = top_let[h];
					  mini_counter += 1;
					}
				}

			}

			if (proof_flag>=4)
			{
				out_words[counter] = vm::Rus_Upper(text[p]) + "(" + work_letter[0] + ", " + work_letter[1] + ", " + work_letter[2] + ", " + work_letter[3] + ", " + work_letter[4] + ")";
				mas[counter] = p;
				counter+= 1;
			}
			mini_counter = 0;
			for (int l = 0; l < 5; l++) { work_letter[l] = ""; };
			proof_flag = 0;
		}

		for (int a = 0; a < x; a++)
		{
			text_j[mas[a]] = out_words[a];
		}

		C = "";
		for (int p = 0; p < x; p++) { C += text_j[p] + " "; }
		return C;
	}
		



};

//Plan
// 1) MostPopular
// 2) MasSorterDawnward