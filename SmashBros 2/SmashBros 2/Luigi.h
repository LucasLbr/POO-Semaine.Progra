#pragma once
#include "Personnage.h"
#include <SFML/Graphics.hpp>
class Luigi :public Personnage
{
protected:


	sf::Sprite MySprite;
	sf::Texture texture;
	sf::Vector2f currentPosition;
	/*int vitessey;
	int vitessex;*/

public:Luigi();
	  sf::Sprite GetMySprite();
	  void bouge(sf::Time DI);
	  sf::FloatRect  luigiglobalPosition();
	  void collision();
	  void collimonter();
};

