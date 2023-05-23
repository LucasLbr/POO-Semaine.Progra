#pragma once
#include "Personnage.h"
#include <SFML/Graphics.hpp>
class Mario:public Personnage
{protected:
	int speed = 5;

//sf::RectangleShape rectangle;
sf::Texture texture;
sf::Sprite MySprite;

public:Mario();
	 sf::Sprite *GetMySprite();
	  void up();
	  void left();
	  void right();
	 
	  sf::FloatRect  marioglobalPosition();
	  sf::Vector2f mariosetPosition(const sf::Vector2f& newPosition);

	 
	  sf:: Vector2f marioPosition();
};

