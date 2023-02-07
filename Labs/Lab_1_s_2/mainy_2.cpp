#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>
#include <iostream>
#include <thread>
#include <math.h>
#include "class2.hpp"
#include <stdlib.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 400), "SFML works!");

	//

	ClassAnimatedText::AnimatedText texty("Hello, world!", 1);
	texty.GetDur();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//+ creating (SFML/other lib) text and font object
		
		sf::Text m_tex;
		sf::Font m_font;

		
		m_font.loadFromFile("impact.ttf");
		m_tex.setFont(m_font);
	    m_tex.setFillColor(sf::Color::Green);
	    m_tex.setStyle(sf::Text::Italic);
		m_tex.setCharacterSize(29);

		m_tex.setFont(m_font);
		//+

	    
		m_tex.setString(texty.GetText());
		window.draw(m_tex); 
		window.display();
		//std::cout << texty.GetText() << std::endl;
		texty.SleepMode();
		window.clear(sf::Color::Black);

		//*/
	
		
		//Console mode!

	    /*
		std::cout << texty.GetText() << std::endl;
		texty.SleepMode();




        //*/

	}

		return 0;
}

