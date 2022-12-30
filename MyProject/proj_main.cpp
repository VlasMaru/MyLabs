#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "funky.hpp"
int main()
{
    setlocale(LC_ALL, "Rus");
    double t = 0;
    sf::RenderWindow window(sf::VideoMode(1250, 800), "My first animation!");
    // backWork
    sf::Image i_background;
    i_background.loadFromFile("baack.png");
    sf::Texture t_background;
    t_background.loadFromImage(i_background);
    sf::Sprite background;
    background.setTexture(t_background);
    //
    int kadr = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        t += 0.02;

        vm::Spaceship ship1(1200, 50);
        vm::Kometa kom1(0, 900);
        vm::Kometa kom2(50, 790);
        vm::GasStation gas1(200, 300);
        int f = kadr % 3;

        if (f == 0) { kom1.SetUpKom("kom_3.png", 1, 1); };
        if (f == 1) { kom1.SetUpKom("kom_4.png", 1, 1); };
        if (f == 2) { kom1.SetUpKom("kom_5.png", 1, 1); };

        if (f == 0) { kom2.SetUpKom("kom_4.png", 0.5, 0.5); };
        if (f == 1) { kom2.SetUpKom("kom_3.png", 0.5, 0.5); };
        if (f == 2) { kom2.SetUpKom("kom_5.png", 0.5, 0.5); };

        ship1.SetUpShip("ship_2.png",1.5,1.5);
        gas1.SetUpGas("gas.png", 1, 1);
        ship1.SetShipAce(150);
        gas1.SetRotation(-35);
        kadr += 1;
        
        kom1.SetTime(t);
        kom2.SetTime(t);
        ship1.SetTime(t);
        gas1.SetTime(t);
        
        kom1.GetOnCurrentPosition();
        kom2.GetOnCurrentPosition();
        ship1.GetOnCurrentPosition();
        gas1.GetOnCurrentPosition();

        background.setScale(1.32, 1.5);

        sf::RectangleShape line(sf::Vector2f(600, 10));
        line.setPosition(ship1.GetSpriteX()+100, ship1.GetSpriteY()+20);
        line.setFillColor(sf::Color(30,255,0,25));
        
    
        window.clear(sf::Color::Blue);
        window.draw(background);
        window.draw(*gas1.GetSprite());
        window.draw(*kom1.GetSprite());
        window.draw(*kom2.GetSprite());
        window.draw(line);
        window.draw(*ship1.GetSprite());
       
      
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));

    }

    return 0;
}