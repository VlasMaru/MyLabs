#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "funky.hpp"

namespace vm
{
	setlocale(LC_ALL, "Rus");


	// ƒвижение кометы описано с помощью формулы движени€ тела, брошенного под углом к горизонту с определЄнным ускорением пл
	Kometa::Kometa(float x, float y)
	{
		m_x = x;
		m_y = y;
	};

	Kometa::~Kometa()
	{
		if (m_texture != nullptr)
			delete m_texture;
		if (m_sprite != nullptr)
			delete m_sprite;
	};

	//создаЄт спрайт и скейлит его
	bool Kometa::SetUpKom(const std::string& name, float scale_x, float scale_y)
	{
		m_texture = new sf::Texture;
		if (!m_texture->loadFromFile(name))
		{
			std::cout << "Loading error! File not found:" << name << std::endl;
			return false;
		}
		m_sprite = new sf::Sprite;
		m_sprite->setTexture(*m_texture);
		m_sprite->setScale(scale_x, scale_y);
		return true;
	}
	//—еттеры ускорени€, вращени€,начального поворота спрайта, угла "броска"
	void Kometa::SetKometAce(float xo, float yo)
	{
		m_x_ace = xo; //ускорение по оси oy
		m_y_ace = yo; //ускорение по оси ox
	}
	void Kometa::SetPlusRotation(int xr)
	{
		m_plus_rotat = xr;
	}
	void Kometa::SetStartRotation(float x)
	{
		m_rotat = x;
	}
	void Kometa::SetAngle(float x)
	{
		m_a = x;
	}
	void Kometa::SetTime(float t)
	{
		m_time = t;
	}

	void Kometa::GetOnCurrentPosition()
	{
		float m_Alpha = ((pi / 180) * m_a);
		m_rotat = m_rotat + (m_plus_rotat * (m_time / 0.02));
		m_sprite->setPosition((m_x + m_v_o * m_time * cos(m_Alpha)), (m_y - (sin(m_Alpha) * m_v_o - g * m_time) * m_time));
		m_sprite->setRotation(m_rotat);
		// выводим в консоль координаты и рисуем, но не выводим
		std::cout << (m_x + m_v_o * m_time * cos(m_Alpha)) << " ";
		std::cout << (m_y - (sin(m_Alpha) * m_v_o - g * m_time) * m_time) << " ";
		std::cout << m_time << std::endl;

	}
	///////float Kometa::GetSpriteX() { return m_sprite->getPosition().x; }
	///////float Kometa::GetSpriteY() { return m_sprite->getPosition().y; }
    sf::Sprite* Kometa::GetSprite() { return m_sprite; }

	
	

	    Spaceship::Spaceship(float x, float y)
		{
			m_x = x;
			m_y = y;
		}
	    Spaceship::~Spaceship()
		{
			if (m_texture != nullptr)
				delete m_texture;
			if (m_sprite != nullptr)
				delete m_sprite;
		}

		void Spaceship::SetShipAce(float acceleration)
		{
			m_a = acceleration;
		}

		void Spaceship::SetTime(float time)
		{
			m_time = time;
		}
		void Spaceship::SetRotation(float rotation)
		{
			m_rotat = rotation;
		}

		bool Spaceship::SetUpShip(const std::string& name, float scale_x, float scale_y)
		{
			m_texture = new sf::Texture;
			if (!m_texture->loadFromFile(name))
			{
				std::cout << "Loading error! File not found:" << name << std::endl;
				return false;
			}
			m_sprite = new sf::Sprite;
			m_sprite->setTexture(*m_texture);
			m_sprite->setScale(scale_x, scale_y);
			return true;
		}
		void Spaceship::GetOnCurrentPosition()
		{

			m_sprite->setPosition(m_x + m_a * m_time * (-1), m_y);
			m_sprite->setRotation(m_rotat);

		}
		sf::Sprite* Spaceship::GetSprite() { return m_sprite; }
		float Spaceship::GetSpriteX() { return m_sprite->getPosition().x; }
		float Spaceship::GetSpriteY() { return m_sprite->getPosition().y; }


	
		/// 
	
		GasStation::GasStation(float x, float y)
		{
			m_x = x;
			m_y = y;
		}
		GasStation::~GasStation()
		{
			if (m_texture != nullptr)
				delete m_texture;
			if (m_sprite != nullptr)
				delete m_sprite;
		}

	    //setters
		bool GasStation::SetUpGas(const std::string& name, float scale_x, float scale_y)
		{
				m_texture = new sf::Texture;
				if (!m_texture->loadFromFile(name))
				{
					std::cout << "Loading error! File not found:" << name << std::endl;
					return false;
				}
				m_sprite = new sf::Sprite;
				m_sprite->setTexture(*m_texture);
				m_sprite->setScale(scale_x, scale_y);
				return true;
	    }
		void GasStation::SetTime(float time)
		{
			m_time = time;
		}

		void GasStation::SetRotation(float a)
		{
			m_rotation = a;
		}
		void GasStation::GetOnCurrentPosition()
		{
			tiker = (int(m_time / 0.09))%10;
			if ( 0.1 * tiker >= 5) { m_sprite->setPosition(m_x, m_y - 0.0090 * tiker); }
			m_sprite->setPosition(m_x,m_y+2*tiker);
			m_sprite->setRotation(m_rotation);
		}
		sf::Sprite* GasStation::GetSprite() { return m_sprite;}
}
