#include "Mario.h"
#include <iostream>
Mario::Mario() :Personnage()
{

	if (!texture.loadFromFile("mario.png")) {
		std::cout << "Erreur lors du chargement de l'image perso.png" << std::endl;

	}
	MySprite.setTexture(texture);
	MySprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	MySprite.setPosition(sf::Vector2f(560, 650));
	
	vitessey = 0;
	vitessex = 0;
}

sf::Sprite Mario::GetMySprite() {
	return MySprite;
}
void Mario::bouge(sf::Time DI)
{
	MySprite.move(vitessex * DI.asSeconds(), vitessey * DI.asSeconds());
	
}
sf::FloatRect Mario::marioglobalPosition()
{
	return MySprite.getGlobalBounds();
}
void Mario::collision() {
	vitessey=0;
	MySprite.move(0, -2);
	UpIsPressed = true;
}
void Mario::collimonter() {
	vitessey = 0;
	MySprite.move(0, -2);
	UpIsPressed = true;
	
}