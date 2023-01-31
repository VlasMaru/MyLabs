#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>
#include <iostream>
#include <thread>
#include <math.h>
#include "class.hpp"
#include <stdlib.h>

/*int WordCounter(std::string start_string)
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

 int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 400), "SFML works!");

	std::string my_string;
	std::getline(std::cin, my_string);
	int duration;
	std::cin >> duration;

	//
	sf::Text tex;
	sf::Font font;
	font.loadFromFile("font/impact.ttf");
	tex.setFont(font);
	tex.setFillColor(sf::Color::Magenta);
	tex.setStyle(sf::Text::Italic);
	tex.setCharacterSize(24);

	//

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		
		std::string cur_string = "";
		int n = WordCounter(my_string);
		std::string* words = new std::string[n];
		StringSlayer(words, my_string);
		float sm_duration = round((float(duration) / (my_string.length())) * 1000000000) / 1000000000;
		//std::cout << round((float(duration) / (my_string.length()))*1000)/1000 << std::endl;

		for (int x = 0; x < WordCounter(my_string); x++)
		{
			int i = 0;
			int len = (words[x].length());

			while (i < len)
			{
				
				cur_string += words[x][i];
				tex.setString(cur_string);
				window.clear();
				window.draw(tex);
				window.display(); 
				std::this_thread::sleep_for(std::chrono::nanoseconds(int(sm_duration*1000000000)));
				i += 1;
			}

			cur_string += " ";
		}

        
        
		delete[] words;
		window.clear(sf::Color::Blue);
		window.display();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
	
    return 0;
}
//*/



int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 400), "SFML works!");

	//

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//
		ClassAnimatedText::AnimatedText texty("Hello, world!", 13);

		for (int x = 0; x < WordCounter(my_string); x++)
		{
			int i = 0;
			int len = (words[x].length());

			while (texty.Get_I() < len)
			{

				window.clear();
				window.draw(texty.GetFrame(texty.;
				window.display();
				std::this_thread::sleep_for(std::chrono::nanoseconds(int(sm_duration * 1000000000)));
				i += 1;
			}

			cur_string += " ";
		}

		//
		window.clear(sf::Color::Blue);
		window.display();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	return 0;
}