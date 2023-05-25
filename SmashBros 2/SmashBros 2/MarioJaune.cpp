#include "MarioJaune.h"

#include <iostream>
 MarioJaune::MarioJaune() :Mario()
{

	if (!texture.loadFromFile("MarioJaune.png")) {
		std::cout << "Erreur lors du chargement de l'image perso.png" << std::endl;

	}
	MySprite.setTexture(texture);
	MySprite.setTextureRect(sf::IntRect(18, 22, 24, 40));
}