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
	sf::Clock animationClock;
	//enum Direction { Left, Right }; // Enumération pour représenter les directions possibles
	//Direction lastDirection;

public:Mario();
	  sf::Sprite GetMySprite();
	  void bouge(sf::Time DI);
	  sf::FloatRect  marioglobalPosition();
	  void collision();
	  void collimonter();
	  void posture(bool U, bool D, bool R, bool L,bool un,bool deux);
	  void reculD();
	  void reculG();
	  void frapper(Personnage* cible);
	  void dead();
};

