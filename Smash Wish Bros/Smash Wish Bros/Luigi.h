#pragma once
#include "Personnage.h"
#include <SFML/Graphics.hpp>
class Luigi :public Personnage
{
private:int speed = 5;
	   sf::RectangleShape rectangle;

public:Luigi();
	  void up();
	  void left();
	  void right();
	  sf::RectangleShape& LuigiGetRect();
	  sf::FloatRect  LuigiglobalPosition();
	  sf::Vector2f LuigisetPosition(const sf::Vector2f& newPosition);

	  sf::Vector2f LuigiPosition();
};

