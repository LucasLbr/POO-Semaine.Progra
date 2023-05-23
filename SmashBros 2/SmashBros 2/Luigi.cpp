#include "Luigi.h"
#include <iostream>
Luigi::Luigi() :Personnage()
{

	if (!texture.loadFromFile("luigi.png")) {
		std::cout << "Erreur lors du chargement de l'image perso.png" << std::endl;

	}
	MySprite.setTexture(texture);
	MySprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	MySprite.setPosition(sf::Vector2f(1340, 650));

	vitessey = 0;
	vitessex = 0;
}

sf::Sprite Luigi::GetMySprite() {
	return MySprite;
}
void Luigi::bouge(sf::Time DI)
{
	MySprite.move(vitessex * DI.asSeconds(), vitessey * DI.asSeconds());

}
sf::FloatRect Luigi::luigiglobalPosition()
{
	return MySprite.getGlobalBounds();
}
void Luigi::collision() {
	vitessey = 0;
	MySprite.move(0, -2);
	UpIsPressed = true;
}
void Luigi::collimonter() {
	vitessey = 0;
	MySprite.move(0, -2);
	UpIsPressed = true;

}