#pragma once
#include "Personnage.h"
#include <SFML/Graphics.hpp>
class Mario:public Personnage
{protected:
	int speed = 5;

	sf::Sprite MySprite;
sf::Texture texture;


public:Mario();
	 sf::Sprite GetMySprite();
	  void up();
	  void left();
	  void right();
	  void down();
	  sf::FloatRect  marioglobalPosition();
	  sf::Vector2f mariosetPosition(const sf::Vector2f& newPosition);

	 
	  sf:: Vector2f marioPosition();
};

