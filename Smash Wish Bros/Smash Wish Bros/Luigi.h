#pragma once
#include "Personnage.h"
#include <SFML/Graphics.hpp>
class Luigi :public Personnage
{
protected:int speed = 5;
		 sf::Sprite MySprite;
		 sf::Texture texture;

public:Luigi();
	  sf::Sprite GetMySprite();
	  void up();
	  void left();
	  void right();
	  void down();
	 
	  sf::FloatRect  LuigiglobalPosition();
	  sf::Vector2f LuigisetPosition(const sf::Vector2f& newPosition);

	  sf::Vector2f LuigiPosition();
};

