#include "Mario.h"
#include <iostream>
Mario::Mario() :Personnage()
{
	
	if (!texture.loadFromFile("mario.png")) {
		std::cout << "Erreur lors du chargement de l'image perso.png" <<std:: endl;
	
	}
	MySprite.setTexture(texture);
	MySprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	MySprite.setPosition(sf::Vector2f(560, 650));

}
void Mario::up() {
	MySprite.move(0, -speed);
}
void Mario::left() {
	MySprite.move(-speed, 0);
}
void Mario::right() {
	MySprite.move(speed, 0);
}

sf::FloatRect Mario:: marioglobalPosition()
{
	return MySprite.getGlobalBounds();
}

sf::Vector2f Mario::marioPosition() {
	return MySprite.getPosition();
}
sf::Vector2f Mario::mariosetPosition(const sf::Vector2f& newPosition) {
	sf::Vector2f previousPosition = MySprite.getPosition();
	MySprite.setPosition(newPosition);
	return previousPosition;
}
sf::Sprite* Mario::GetMySprite() {
return &MySprite;
}