#include "Platform.h"
#include <iostream>

Platform::Platform(int w, int h,int x,int y)
{
	if (!texture.loadFromFile("plateformweb.png")) {
		std::cout << "Erreur lors du chargement de l'image platform.png" << std::endl;

	}
	MySprite.setTexture(texture);
	MySprite.setTextureRect(sf::IntRect(112, 166, w, h));
	MySprite.setPosition(sf::Vector2f(x, y));
}
sf::Sprite Platform::GetMySprite() {
	return MySprite;
}
sf::FloatRect Platform::platformglobalPosition()
{
	return MySprite.getGlobalBounds();
}