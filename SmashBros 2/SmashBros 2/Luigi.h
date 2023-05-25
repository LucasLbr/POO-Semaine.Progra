#pragma once
#include "Personnage.h"
#include <SFML/Graphics.hpp>
class Luigi :public Personnage
{
protected:


	//sf::Sprite MySprite;
	sf::Texture texture;
	sf::Vector2f currentPosition;
	/*int vitessey;
	int vitessex;*/
	//sf::Clock animationClock;
	//enum Direction { Left, Right }; // Enumération pour représenter les directions possibles
//	Direction lastDirection;
public:Luigi();
	//  sf::Sprite GetMySprite();
	//  void bouge(sf::Time DI);
	 // sf::FloatRect  luigiglobalPosition();
	//  void collision();
	  void collimonter();
	  void posture(bool U, bool D, bool R, bool L, bool un, bool deux,bool trois);
	  void reculD();
	  void reculG();
	  void dead();
	  void frapperpied(Personnage*cible);
	  void reculU();
	  void frapper(Personnage* cible);
};

