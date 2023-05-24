#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Personnage
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	int mort;
	float vitessey;
	float vitessex;
	float vitessegravit;
	bool UpIsPressed;
	bool bagarre;
	int vie;
	bool position_defensive;
	enum Direction { Left, Right }; // Enumération pour représenter les directions possibles
	Direction lastDirection;
	int ultime;
public:
	Personnage();
	void pesanteur();
	//virtual void bouge(sf::Time DI);
	bool contact();
	
	virtual void changement_vitesse(bool U, bool D, bool R, bool L, sf::Time dureeIteration);
	virtual void recevoir_degats(int degats);
	virtual void frapper(Personnage* cible);
	virtual void attaque_spécial(Personnage* cible);
	virtual void bouclier(bool x);
	virtual void dead();
	int get_vie();
	virtual void reculD();
	virtual void reculG();

};
