#include "Luigi.h"
#include <iostream>
Luigi::Luigi() :Personnage()
{
	if (!texture.loadFromFile("luigi.png")) {
		std::cout << "Erreur lors du chargement de l'image perso.png" << std::endl;

	}
	MySprite.setTexture(texture);
	MySprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	MySprite.setPosition(sf::Vector2f(1340, 650));


	
	

}
sf::Sprite Luigi::GetMySprite() {
	return MySprite;
}
void Luigi::up() {
	MySprite.move(0, -speed);
}
void Luigi::left() {
	MySprite.move(-speed, 0);
}
void Luigi::right() {
	MySprite.move(speed, 0);
}
void Luigi::down() {
	MySprite.move(0, speed);
}

sf::FloatRect Luigi::LuigiglobalPosition()
{
	return MySprite.getGlobalBounds();
}

sf::Vector2f Luigi::LuigiPosition() {
	return MySprite.getPosition();
}
sf::Vector2f Luigi::LuigisetPosition(const sf::Vector2f& newPosition) {
	sf::Vector2f previousPosition = MySprite.getPosition();
	MySprite.setPosition(newPosition);
	return previousPosition;
}