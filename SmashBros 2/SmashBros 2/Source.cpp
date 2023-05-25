#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personnage.h"
#include "Mario.h"
#include "Luigi.h"
#include "Platform.h"
#include "MarioJaune.h"
#include "Projectile.h"
Personnage* SelectionJoueur();

/*bool CheckCollisionWithPlatformmario(Mario* x, Platform platform);
bool CheckCollisionWithPlatformluigi(Luigi* x, Platform platform);
bool CheckCollisionMarioLuigi(Mario* x, Luigi* y);*/
bool CheckCollisionentrePersonnage(Personnage* x, Personnage* y);
bool CheckCollisionWithPlatforPersonnage(Personnage* x, Platform platform);

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
	bool move3 = false;
	bool moveJ = false;
	bool isUpPressed = false;
	bool menu = true;

	std::vector<Projectile*>projectile;
	
	sf::Clock clock;
	sf::Time dureeIteration = sf::Time::Zero;
	std::vector<Personnage*> tab;
	

	//Mario* mario = new Mario();
	//Luigi* luigi = new Luigi();
	// arene
	Personnage* Joueur1;
	Personnage* Joueur2;
	
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
				case sf::Keyboard::J:
					moveJ= true;
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
				case sf::Keyboard::Numpad3:
					move3 = true;
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
				case sf::Keyboard::Numpad3:
					move3 = false;
					break;
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
				case sf::Keyboard::J:
					moveJ = false;
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
		if (menu == true) {
			Joueur1 = SelectionJoueur();
			tab.push_back(Joueur1);
			Joueur2 = SelectionJoueur();
			tab.push_back(Joueur2);
			tab[0]->positionDebut(750, 500);
			tab[1]->positionDebut(1100, 500);
		}
		if (menu == false) {
	
			for (int i = 0; i < tab.size(); i++) {
				tab[i]->pesanteur();
			}

			if (move3 == true) {
				tab[0]->lancer(&projectile);
			}
			if (moveJ == true) {
				tab[1]->lancer(&projectile);
			}


			tab[0]->changement_vitesse(moveU, moveD, moveR, moveL, dureeIteration);
			tab[1]->changement_vitesse(moveZ, moveS, moveD2, moveQ, dureeIteration);

			tab[0]->bouclier(moveD);
			tab[1]->bouclier(moveS);
			tab[0]->posture(moveU, moveD, moveR, moveL, move1, move2,move3);
			tab[1]->posture(moveZ, moveS, moveD2, moveQ, moveG, moveH,moveJ);
			for (int i = 0; i < tab.size(); i++) {
				tab[i]->bouge(dureeIteration);
			}

			for (int i = 0; i < tab.size(); i++) {
				if (CheckCollisionWithPlatforPersonnage(tab[i], Principale)) {
					tab[i]->collision();
				}
			}
			for (int i = 0; i < tab.size(); i++) {
				if (CheckCollisionWithPlatforPersonnage(tab[i], platform1)) {
					tab[i]->collision();
				}
			}
			for (int i = 0; i < tab.size(); i++) {
				if (CheckCollisionWithPlatforPersonnage(tab[i], platform2)) {
					tab[i]->collision();
				}
			}
			for (int i = 0; i < tab.size(); i++) {
				if (CheckCollisionWithPlatforPersonnage(tab[i], dead)) {
					tab[i]->dead();
				}
			}
			/*if (CheckCollisionWithPlatformmario(mario, Principale)|| CheckCollisionWithPlatformmario(mario, platform1) ||
				CheckCollisionWithPlatformmario(mario, platform2)) {

				mario->collision();
			}
			if (CheckCollisionWithPlatformluigi(luigi, Principale)|| CheckCollisionWithPlatformluigi(luigi, platform1) ||
				CheckCollisionWithPlatformluigi(luigi, platform2)) {

				luigi->collision();
			}

			if (CheckCollisionWithPlatformmario(mario, dead))
			{

				mario->dead();


			}
			if (CheckCollisionWithPlatformluigi(luigi, dead)) {
				luigi->dead();*/

			if (CheckCollisionentrePersonnage(tab[0], tab[1]) == true) {
				if (move1 == true)tab[0]->frapper(tab[1]);
				if (moveG == true)tab[1]->frapper(tab[0]);
				if (move2 == true)tab[0]->frapperpied(tab[1]);
				if (moveH == true)tab[1]->frapperpied(tab[0]);

			}
			int scoremario = tab[0]->get_vie();
			int scoreluigi = tab[1]->get_vie();
			font.loadFromFile("\Poppins Medium 500.ttf");
			txt.setPosition(840, 700);
			txt.setCharacterSize(40);
			txt.setFont(font);
			txt.setString(std::to_string(scoremario) + "% | " + std::to_string(scoreluigi) + "%");



			view.reset(sf::FloatRect(0, 0, screenw, screenh));
			sf::Vector2f position(screenw / 2, screenh / 2);
			view.zoom(0.5f);
			window.setView(view);


			
			window.clear();
		
			window.draw(backgroundSprite);
			window.draw(txt);
			window.draw(tab[0]->GetMySprite());
			window.draw(tab[1]->GetMySprite());
		
			window.draw(dead.GetMySprite());
			window.draw(platform1.GetMySprite());
			window.draw(platform2.GetMySprite());
			window.draw(Principale.GetMySprite());
			for (int i = 0; i < projectile.size(); i++) {
				window.draw(projectile[i]->GetMySprite());

			}
			
			window.display();
			
		}
		menu = false;
	}
	for (int i = 0; i < tab.size(); i++) {
		delete tab[i];
	}
	
}
bool CheckCollisionWithPlatforPersonnage(Personnage* x, Platform platform)
{

	return x->PersonnageglobalPosition().intersects(platform.platformglobalPosition());
}
/*bool CheckCollisionWithPlatformluigi(Luigi* x, Platform platform)
{

	return x->luigiglobalPosition().intersects(platform.platformglobalPosition());
}*/
bool CheckCollisionentrePersonnage(Personnage* x, Personnage* y) {
	return x->PersonnageglobalPosition().intersects(y->PersonnageglobalPosition());
}
Personnage* SelectionJoueur() {
	Personnage* j;
	int c;
	std::cout << "1 mario 2 luigi" << std::endl;
	std::cin >> c;
	switch (c) {
	case (1):j = new Mario();
		break;
	case (2):j = new Luigi();
		break;
	case (3):j = new MarioJaune();
		break;
	default:j = new Mario();
	}


	return j;
}