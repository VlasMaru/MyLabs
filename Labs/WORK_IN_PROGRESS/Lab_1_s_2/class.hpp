#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>
#include <iostream>
#include <thread>
#include <math.h>
#include <stdlib.h>

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
		float m_sm_duration = round((float(m_duration) / (m_my_string.length())) * 1000000000) / 1000000000;
		int n = WordCounter(m_my_string);
		std::string* m_words = new std::string[n];
		int m_i = 0;

		


		void Error(int x) { exit(x); }

	public:

		AnimatedText(std::string my_string, int duration)
		{
			m_my_string = my_string;
			m_duration = duration;
			sf::Text* m_tex = nullptr;
			sf::Font* m_font = nullptr;
		}
		~AnimatedText()
		{
			delete[] m_words;
		};


		bool SetFont(sf::Text tex, sf::Font font ,const std::string& font_name, sf::Color color, char style, int size)
		{
			m_tex = new sf::Text;
			font.loadFromFile(font_name);
			tex.setFont(font);
			tex.setFillColor(color);
			if (style == 'i') { tex.setStyle(sf::Text::Italic); }
			if (style == 'b') { tex.setStyle(sf::Text::Bold); }
			if (style == 'u') { tex.setStyle(sf::Text::Underlined);}
			tex.setCharacterSize(size);
		}
	
		sf::Text GetFrame(sf::Text tex, sf::Font font)
		{
			for (int x = 0; x < WordCounter(m_my_string); x++)
			{
				int len = (m_words[x].length());

				while (m_i < len)
				{

					m_cur_string += m_words[x][m_i];
					tex.setString(m_cur_string);
					return tex;
					//std::this_thread::sleep_for(std::chrono::nanoseconds(int(m_sm_duration * 1000000000)));
					m_i += 1;
				}

				m_cur_string += " ";
			}
		}
		int Get_I()
		{
			return m_i;
		}

		
	};
 


}