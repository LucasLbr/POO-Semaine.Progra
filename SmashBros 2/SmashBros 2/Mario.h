#pragma once
#include "Personnage.h"
#include <SFML/Graphics.hpp>
class Mario :public Personnage
{
protected:


	sf::Sprite MySprite;
	sf::Texture texture;
	sf::Vector2f currentPosition;
	/*int vitessey;
	int vitessex;*/

public:Mario();
	  sf::Sprite GetMySprite();
	  void bouge(sf::Time DI);
	  sf::FloatRect  marioglobalPosition();
	  void collision();
	  void collimonter();
};

