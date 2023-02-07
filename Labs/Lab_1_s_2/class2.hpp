#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>
#include <iostream>
#include <thread>
#include <math.h>
#include <stdlib.h>
#include <iomanip>

namespace addfun
{
	int WordCounter(std::string start_string);
	void StringSlayer(std::string* wordlist, std::string StartString);
}
namespace ClassAnimatedText
{
	class AnimatedText
	{
	private:

		std::string m_cur_string = "";
		std::string m_my_string = "";
		int m_duration = 0;
		float m_sm_duration;
		int m_i = 0;

		void Error(int x) { exit(x); }

	public:

		AnimatedText(std::string my_string, int duration)
		{
			m_my_string = my_string;
			m_duration = duration;
			m_sm_duration = round((float(m_duration) / (m_my_string.length())) * 1000000000) / 1000000000;

		}
		~AnimatedText()
		{
			std::cout << "ITS ME, DIO!";
		};

		std::string GetMyString() { return m_my_string; }


		int Get_I()
		{
			return m_i;
		}



		std::string GetText()
		{
			m_cur_string += m_my_string[m_i];
			m_i += 1;
			if (m_i > m_my_string.length()) { Error(0); }
			return m_cur_string;
		}
		void GetDur()
		{
			std::cout << m_sm_duration << std::endl;
		}

		void SleepMode()
		{
			std::this_thread::sleep_for(std::chrono::nanoseconds(int(m_sm_duration * 1000000000)));
		}
	};



}