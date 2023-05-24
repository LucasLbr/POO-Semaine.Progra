#pragma once
#include <SFML/Graphics.hpp>
class Platform
{
protected:sf::Sprite MySprite;
	sf::Texture texture;
	
public: 
	Platform(int w, int h, int x, int y);
	sf::Sprite GetMySprite();
	sf::FloatRect platformglobalPosition();
};

