#include "Header.hpp"
#include <iostream>
#include <string>
namespace addfunc
{
	int Fibi(unsigned int num)
	{
		int vpast = 1;
		int past = 2;
		int cur;
		if (num == 1) { return 1; }
		if (num == 2) { return 2; }
		num -= 2;
		for (int i = 0; i < num; i++)
		{
			cur = vpast + past;
			vpast = past;
			past = cur;
		}
		return cur;
	};
	int WordCounter(std::string start_string)
	{
		char buk = 'w';
		int i = 0;
		int count = 1;

		while (buk != '\0')
		{
			buk = start_string[i];
			i += 1;
			if (buk == ' ') { count += 1; }
		}
		return count;
	};

	void StringSlayer(std::string* wordlist, std::string StartString)
	{
		std::string wordy = "";
		char buk = 'w';
		int i = 0;
		int n = 0;
		while (buk != '\0')
		{
			buk = StartString[i];
			if (buk != ' ') { wordy = wordy + buk; }
			if (buk == ' ')
			{
				wordlist[n] = wordy;
				n += 1;
				wordy = "";
			}
			i += 1;
		}
		wordlist[n] = wordy;
	}
}