#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>
#include <iostream>
#include <thread>
#include <math.h>
#include "class.hpp"
#include <stdlib.h>

namespace addfun
{
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
			buk = StartString[i];
		}
		wordlist[n] = wordy;

	}
}

namespace
{

}