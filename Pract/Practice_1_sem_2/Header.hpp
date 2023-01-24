#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

namespace addfunc
{
	// for unambiguous decoding, we take the beginning of the sequence 1, the second value 2, etc.
	int Fibi(unsigned int num);
	int WordCounter(std::string start_string);
	void StringSlayer(std::string* wordlist, std::string StartString);
}

namespace FIBICyClass
{
	class Cypher
	{
	private:
		std::string m_list_slova[30];
		int m_list_fibi[30];

		std::string m_string = "";

		int m_NumOfWords = 0;
		int m_key[30];
		int m_new_key[30];
		int m_correct_fibi[30];

		void Stopper(int x)
		{
			exit(x);
		}

	public:
		Cypher(std::string string)
		{
			m_string = string;
			m_NumOfWords = addfunc::WordCounter(m_string);
			for (int i = 0; i < m_NumOfWords; i++)
			{
				m_list_fibi[i] = addfunc::Fibi(i + 1);
				m_key[i] = addfunc::Fibi(i + 1);
				m_correct_fibi[i] = addfunc::Fibi(i + 1);
			}
			addfunc::StringSlayer(m_list_slova, string);

		}
		~Cypher()
		{
			std::cout << "End of program!";
		}


		void Encode() // It's also decoder, if you don't have orig. text as an object ( if you have only coded text and key)
		{
			int max = addfunc::Fibi(m_NumOfWords);
			int lil_flag = 0;
			std::cout << "Enter the new key:" << std::endl;
			for (int i = 0; i < m_NumOfWords; i++)
			{
				std::cin >> m_key[i];

				for (int y = 1; y < m_NumOfWords+1;y++)
				{
					if (addfunc::Fibi(y) == m_key[i]) { lil_flag += 1; }
				}

				if ((m_key[i] > max) || (lil_flag == 0))
				{
					std::cout << "Entery error!";
					Stopper(0);
				}
			}

			for (int u = 0; u < m_NumOfWords; u++)
			{
				for (int h = 0; h < m_NumOfWords; h++)
				{
					if (m_key[u] == m_list_fibi[h])
					{
						std::swap(m_list_slova[h], m_list_slova[u]);
						std::swap(m_list_fibi[h], m_list_fibi[u]);

					}
				}
			}
		}

		void Decode()
		{
			int flag = 0;

			std::cout << "Enter the current key:" << std::endl;

			for (int i = 0; i < m_NumOfWords; i++)
			{
				std::cin >> m_new_key[i];
			}


			for (int u = 0; u < m_NumOfWords; u++)
			{
				if (m_new_key[u] != m_key[u]) { flag += 1; }
			}


			if (flag == 0)
			{
				for (int u = 0; u < m_NumOfWords; u++)
				{
					for (int h = 0; h < m_NumOfWords; h++)
					{
						if (m_correct_fibi[u] == m_key[h])
						{
							swap(m_list_slova[h], m_list_slova[u]);
							std::swap(m_key[h], m_key[u]);

						}
					}
				}
			}

			if (flag != 0)
			{
				std::cout << "There are " << flag << "  mistakes in your key!" << std::endl;
			}
		};

		/// some kind of getters
		void ShowText()
		{
			std::string str = "";
			for (int i = 0; i < m_NumOfWords; i++)
			{
				str = str + m_list_slova[i] + " ";
			}
			std::cout << str << std::endl;
		}
		void ShowCurrentKey()
		{
			for (int p = 0; p < m_NumOfWords; p++) { std::cout << m_key[p] << " "; }
			std::cout << "" << std::endl;
		}

	};
}

