#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personnage.h"
#include "Mario.h"
#include "Luigi.h"
#include "Platform.h"
bool CheckCollisionWithPlatformmario(Mario* x, Platform platform);
bool CheckCollisionWithPlatformluigi(Luigi* x, Platform platform);
bool CheckCollisionMarioLuigi(Mario* x, Luigi* y);
int main()
{
	int screenw = 1920;
	int screenh = 1080;
	sf::View view;
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
	bool move1 = false;
	bool move2 = false;
	bool moveG = false;
	bool moveH = false;
	 bool isUpPressed = false;
	
	
	sf::Clock clock;
	sf::Time dureeIteration = sf::Time::Zero;
	Mario* mario = new Mario();
	Luigi* luigi = new Luigi();
	// arene
	
	sf::Font font;
	sf::Text txt;
	
	Platform Principale(500, 25, 700, 600);
	Platform platform1(100, 15, 750, 450);
	Platform platform2(100, 15, 1050, 450);
	Platform dead(screenw, 25, 0, 1000);
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("backgroundDBZbis.png")) {
		std::cout << "Erreur lors du chargement de l'image background.png" << std::endl;
		return 1;
	}
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(480, 270);
	
	
	

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
				case sf::Keyboard::G:
					moveG = true;
					break;
				case sf::Keyboard::H:
					moveH = true;
					break;
				case sf::Keyboard::Left:
					moveL = true;
					break;
				case sf::Keyboard::Up:

					moveU = true;
					break;

				case sf::Keyboard::Numpad1:
					move1 = true;
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
				case sf::Keyboard::Numpad2:
					move2 = true;


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
				case sf::Keyboard::Numpad2:
					move2 = false;
					break;
				case sf::Keyboard::Left:
					moveL = false;
					break;
				case sf::Keyboard::Up:
					moveU = false;
					break;
				case sf::Keyboard::Numpad1:
					move1 = false;
					break;
				case sf::Keyboard::Down:
					moveD = false;
					break;
				case sf::Keyboard::S:
					moveS = false;
					break;
				case sf::Keyboard::G:
					moveG = false;
					break;
				case sf::Keyboard::H:
					moveH = false;
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
		mario->bouclier(moveD);
		luigi->bouclier(moveS);

		if (CheckCollisionWithPlatformmario(mario, Principale)) {

			mario->collision();
		}
		if (CheckCollisionWithPlatformluigi(luigi, Principale)) {

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
		if (CheckCollisionWithPlatformmario(mario, dead))
		{
			 
			mario->dead();
			
			
		}
		if (CheckCollisionWithPlatformluigi(luigi, dead)) {
			luigi->dead();
		}
		if (CheckCollisionMarioLuigi(mario, luigi) == true ) {
			if (move1==true )mario->frapper(luigi);
			if (moveG == true)luigi->frapper(mario);
		}
		int scoremario = mario->get_vie();
		int scoreluigi = luigi->get_vie();
		font.loadFromFile("\Poppins Medium 500.ttf");
		txt.setPosition(840, 700);
		txt.setCharacterSize(40);
		txt.setFont(font);
		txt.setString(std::to_string(scoremario) + "% | " + std::to_string(scoreluigi) + "%");

		mario->posture(moveU, moveD, moveR, moveL,move1,move2);
		luigi->posture(moveZ, moveS, moveD2, moveQ, moveG, moveH);
		mario->bouge(dureeIteration);
		luigi->bouge(dureeIteration);
		std::cout << mario->get_vie() << std::endl;
		std::cout << luigi->get_vie() << std::endl;
		view.reset(sf::FloatRect(0, 0, screenw, screenh));
		sf::Vector2f position(screenw / 2, screenh / 2);
		view.zoom(0.5f);
		window.setView(view);
		


		window.clear();
		
		window.draw(backgroundSprite);
		window.draw(txt);
		window.draw(mario->GetMySprite());
		window.draw(luigi->GetMySprite());
		window.draw(dead.GetMySprite());
		window.draw(platform1.GetMySprite());
		window.draw(platform2.GetMySprite());
		window.draw(Principale.GetMySprite());
		window.display();

	}delete mario;
	delete luigi;
	return 0;
}
bool CheckCollisionWithPlatformmario(Mario* x, Platform platform)
{

	return x->marioglobalPosition().intersects(platform.platformglobalPosition());
}
bool CheckCollisionWithPlatformluigi(Luigi* x, Platform platform)
{

	return x->luigiglobalPosition().intersects(platform.platformglobalPosition());
}
bool CheckCollisionMarioLuigi(Mario* x, Luigi* y) {
	return x->marioglobalPosition().intersects(y->luigiglobalPosition());
}