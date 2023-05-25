#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include <vector>
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
	sf::Clock animationClock;
	bool position_defensive;
	enum Direction { Left, Right }; // Enumération pour représenter les directions possibles
	Direction lastDirection;
	int ultime;
	sf::Sprite MySprite;

	
	
public:
	virtual sf::Vector2f lancer(bool droite);
	Personnage();
	void pesanteur();

	
	bool contact();
	void bouge(sf::Time DI);
	virtual void changement_vitesse(bool U, bool D, bool R, bool L, sf::Time dureeIteration);
	virtual void recevoir_degats(int degats);
	virtual void frapper(Personnage* cible);
	virtual void frapperpied(Personnage* cible);
	virtual void attaque_spécial(Personnage* cible);
	virtual void bouclier(bool x);
	virtual void dead();
	virtual void posture(bool U, bool D, bool R, bool L, bool un, bool deux,bool trois);
	int get_vie();
	bool get_droite();
	virtual void reculD();
	virtual void reculG();
	sf::Sprite GetMySprite();
	sf::FloatRect  PersonnageglobalPosition();
	void collision();
	void positionDebut(int x, int y);
	virtual void reculU();
};
