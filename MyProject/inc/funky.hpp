#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <thread>
#include <chrono>
#include "funky.hpp"
#include <SFML/Window.hpp>
namespace vm
{
	setlocale(LC_ALL, "Rus");
	

	class Kometa
	{
		
	private:
		float pi = 3.1416;
		float g = 9.78;

		float m_x = 0;
		float m_y = 0; // начальная координата 
		float m_x_ace = 165; //ускорение по оси oy
		float m_y_ace = 10; //ускорение по оси ox

		float m_a = 60; //угол в градусах
		float m_v_o = std::sqrt(m_x_ace * m_x_ace + m_y_ace * m_y_ace); 
		float m_rotat = -35;
		float m_plus_rotat = 0.15;
		float m_time = 0;
		sf::Texture* m_texture = nullptr;
		sf::Sprite* m_sprite = nullptr;
		float rotation_cycle = (m_time / 0.02); //0.02 - ход времени

	public:
		    Kometa(float x, float y);
			~Kometa();
			//сеттеры
			bool SetUpKom(const std::string& name, float scale_x, float scale_y);
			void SetKometAce(float xo, float yo);
			void SetPlusRotation(int xr);
			void SetStartRotation(float x);
			void SetAngle(float x);
			void SetTime(float t);
			//геттеры
			void GetOnCurrentPosition();
		
		///////float GetSpriteX();
		///////float GetSpriteY(); - доп функции
			sf::Sprite* GetSprite();
	};

	class Spaceship
	{
	private:
		float m_x = 0; //
		float m_y = 0; // начальные координаты
		float m_a = 60; //угол в градусах
		float m_rotat = -35;
		float m_time = 0;
		float m_ace = 1;
		sf::Texture* m_texture = nullptr;
		sf::Sprite* m_sprite = nullptr;
	public:
		Spaceship(float x, float y);
		~Spaceship();

		//сеттеры
		void SetShipAce(float acceleration);
		void SetTime(float time);
		void SetRotation(float rotation);
		bool SetUpShip(const std::string& name, float scale_x, float scale_y);
		//геттеры
		void GetOnCurrentPosition();
		sf::Sprite* GetSprite();
		float GetSpriteX();
		float GetSpriteY();
	};

	class GasStation
	{
	private:
		float m_x = 0;
		float m_y = 0;
		float m_scale_x = 1;
		float m_scale_y = 1;
		float m_rotation = 0;
		float m_time = 0;
		sf::Texture* m_texture = nullptr;
		sf::Sprite* m_sprite = nullptr;
		int tiker = 0;
	public:
		GasStation(float x, float y);
		~GasStation();
		//сеттеры
		bool SetUpGas(const std::string& name, float scale_x, float scale_y);
		void SetRotation(float a);
		void SetTime(float time);
		//геттеры
		void GetOnCurrentPosition();
		sf::Sprite* GetSprite();

	};



}

