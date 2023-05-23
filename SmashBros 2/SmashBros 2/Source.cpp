#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personnage.h"
#include "Mario.h"
#include "Luigi.h"
bool CheckCollisionWithPlatformmario(Mario* x, const sf::RectangleShape& platform);
bool CheckCollisionWithPlatformluigi(Luigi* x, const sf::RectangleShape& platform);
int main()
{
	int screenw = 1920;
	int screenh = 1080;
	sf::RenderWindow window(sf::VideoMode(screenw, screenh), "Smash Wish Bros");
	window.setFramerateLimit(60);
	
	bool moveU = false;
	bool moveD = false;
	bool moveL = false;
	bool moveR = false;
	bool moveZ = false;
	bool moveD2 = false;
	bool moveQ = false;
	bool moveS = false;
	 bool isUpPressed = false;
	
	sf::Clock clock;
	sf::Time dureeIteration = sf::Time::Zero;
	Mario* mario = new Mario();
	Luigi* luigi = new Luigi();
	// arene
	sf::RectangleShape platform(sf::Vector2f(1000, 50));
	sf::RectangleShape platform1(sf::Vector2f(200, 25));
	sf::RectangleShape platform2(sf::Vector2f(200, 25));
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("backgroundDBZ.png")) {
		std::cout << "Erreur lors du chargement de l'image background.png" << std::endl;
		return 1;
	}
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0, 0);
	platform.setPosition(460, 700);
	platform.setFillColor(sf::Color::White);
	platform1.setPosition(500, 500);
	platform1.setFillColor(sf::Color::White);
	platform2.setPosition(1200, 500);
	platform2.setFillColor(sf::Color::White);

	while (window.isOpen())
	{
		dureeIteration = clock.restart();
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::EventType::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					moveR = true;
					
					break;
				case sf::Keyboard::Left:
					moveL = true;
					break;
				case sf::Keyboard::Up:
					
						moveU = true;
						
					
					break;
				case sf::Keyboard::S:
					moveS = true;
					break;
				case sf::Keyboard::D:
					moveD2 = true;

					break;
				case sf::Keyboard::Q:
					moveQ = true;
					break;
				case sf::Keyboard::Z:

					moveZ = true;


					break;
				case sf::Keyboard::Down:
					moveD = true;
					break;
			
				}
				break;
			case sf::Event::EventType::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					moveR = false;
					break;
				case sf::Keyboard::Left:
					moveL = false;
					break;
				case sf::Keyboard::Up:
					moveU = false;
					
					break;
				case sf::Keyboard::Down:
					moveD = false;
					break;
				case sf::Keyboard::S:
					moveS = false;
					break;
				case sf::Keyboard::D:
					moveD2 = false;

					break;
				case sf::Keyboard::Q:
					moveQ = false;
					break;
				case sf::Keyboard::Z:

					moveZ = false;


					break;
				

				}


			}
		}
		
		mario->pesanteur();
		luigi->pesanteur();
		
		mario->changement_vitesse(moveU, moveD, moveR, moveL, dureeIteration);
		luigi->changement_vitesse(moveZ, moveS, moveD2, moveQ, dureeIteration);

		if (CheckCollisionWithPlatformmario(mario, platform)) {
			
			mario->collision();
		}
		if (CheckCollisionWithPlatformluigi(luigi, platform)) {
			
				luigi->collision();
		}
		if (CheckCollisionWithPlatformmario(mario, platform1) ||
			CheckCollisionWithPlatformmario(mario, platform2)) {

			mario->collimonter();
		}
		if (CheckCollisionWithPlatformluigi(luigi, platform1) ||
			CheckCollisionWithPlatformluigi(luigi, platform2)) {

			luigi->collimonter();
		}
		
		
		mario->bouge(dureeIteration);
		luigi->bouge(dureeIteration);
	

		window.clear();
		window.draw(backgroundSprite);
		window.draw(mario->GetMySprite());
		window.draw(luigi->GetMySprite());
		window.draw(platform);
		window.draw(platform1);
		window.draw(platform2);
		window.display();
	}
	return 0;
}
bool CheckCollisionWithPlatformmario(Mario* x, const sf::RectangleShape& platform)
{

	return x->marioglobalPosition().intersects(platform.getGlobalBounds());
}
bool CheckCollisionWithPlatformluigi(Luigi* x, const sf::RectangleShape& platform)
{

	return x->luigiglobalPosition().intersects(platform.getGlobalBounds());
}