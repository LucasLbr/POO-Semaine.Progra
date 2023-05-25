#include "Luigi.h"
#include <iostream>
Luigi::Luigi() :Personnage()
{

	if (!texture.loadFromFile("luigibis.png")) {
		std::cout << "Erreur lors du chargement de l'image perso.png" << std::endl;

	}
	MySprite.setTexture(texture);
	MySprite.setTextureRect(sf::IntRect(0, 0, 44, 64));
	//MySprite.setPosition(sf::Vector2f(1100, 500));
	lastDirection = Right;
	vitessey = 0;
	vitessex = 0;
}



void Luigi::collimonter() {
	vitessey = 0;
	MySprite.move(0, -2);
	UpIsPressed = true;

}
void Luigi::posture(bool U, bool D, bool R, bool L, bool un, bool deux,bool trois) {

	// Obtenir le temps écoulé depuis le début du programme en secondes
	float elapsedTime = animationClock.getElapsedTime().asSeconds();

	// Animation du personnage en fonction du temps
	if (trois) {
		int x = static_cast<int>(elapsedTime * 16) % 4;
		if (x == 0) MySprite.setTextureRect(sf::IntRect(0, 249, 44, 40));
		if (x == 1) MySprite.setTextureRect(sf::IntRect(44, 249, 44, 40));
		if (x == 2) MySprite.setTextureRect(sf::IntRect(88, 249, 46, 40));
		if (x == 3) MySprite.setTextureRect(sf::IntRect(134, 249, 46, 40));

		if (lastDirection == Right) {
			int x = static_cast<int>(elapsedTime * 16) % 4;
			if (x == 0) MySprite.setTextureRect(sf::IntRect(0, 249, 44, 40));
			if (x == 1) MySprite.setTextureRect(sf::IntRect(44, 249, 44, 40));
			if (x == 2) MySprite.setTextureRect(sf::IntRect(88, 249, 46, 40));
			if (x == 3) MySprite.setTextureRect(sf::IntRect(134, 249, 46, 40));

		}
		if (lastDirection == Left) {
			int x = static_cast<int>(elapsedTime * 16) % 4;
			if (x == 0) MySprite.setTextureRect(sf::IntRect(380, 246, 44, 40));
			if (x == 1) MySprite.setTextureRect(sf::IntRect(425, 246, 44, 40));
			if (x == 2) MySprite.setTextureRect(sf::IntRect(470, 246, 46, 40));
			if (x == 3) MySprite.setTextureRect(sf::IntRect(515, 246, 46, 40));

		}
	}
	if (un)
	{
		int x = static_cast<int>(elapsedTime * 16) % 4;
		if (x == 0) MySprite.setTextureRect(sf::IntRect(0, 249, 44, 40));
		if (x == 1) MySprite.setTextureRect(sf::IntRect(44, 249, 44, 40));
		if (x == 2) MySprite.setTextureRect(sf::IntRect(88, 249, 46, 40));
		if (x == 3) MySprite.setTextureRect(sf::IntRect(134, 249, 46, 40));
	
		if (lastDirection == Right) {
			int x = static_cast<int>(elapsedTime * 16) % 4;
			if (x == 0) MySprite.setTextureRect(sf::IntRect(0, 249, 44, 40));
			if (x == 1) MySprite.setTextureRect(sf::IntRect(44, 249, 44, 40));
			if (x == 2) MySprite.setTextureRect(sf::IntRect(88, 249, 46, 40));
			if (x == 3) MySprite.setTextureRect(sf::IntRect(134, 249, 46, 40));

		}
		if (lastDirection == Left) {
			int x = static_cast<int>(elapsedTime * 16) % 4;
			if (x == 0) MySprite.setTextureRect(sf::IntRect(380, 246, 44, 40));
			if (x == 1) MySprite.setTextureRect(sf::IntRect(425, 246, 44, 40));
			if (x == 2) MySprite.setTextureRect(sf::IntRect(470, 246, 46, 40));
			if (x == 3) MySprite.setTextureRect(sf::IntRect(515, 246, 46, 40));

		}
	}
	if (R)
	{
		int x = 0;
		x = (int)MySprite.getPosition().x / 35 % 8;
		//x = x * 12;
		if (x == 0)MySprite.setTextureRect(sf::IntRect(12, 140, 31, 45));
		if (x == 1)MySprite.setTextureRect(sf::IntRect(44, 140, 29, 45));
		if (x == 2)MySprite.setTextureRect(sf::IntRect(77, 140, 31, 45));
		if (x == 3)MySprite.setTextureRect(sf::IntRect(110, 140, 29, 45));
		if (x == 4)MySprite.setTextureRect(sf::IntRect(139, 140, 31, 45));
		if (x == 5)MySprite.setTextureRect(sf::IntRect(171, 140, 31, 45));
		if (x == 6)MySprite.setTextureRect(sf::IntRect(205, 140, 31, 45));
		if (x == 7)MySprite.setTextureRect(sf::IntRect(237, 140, 31, 45));
		//on touvhe pas les w et h
		lastDirection = Right;
	}
	if (L)
	{
		int x = 0;
		x = (int)MySprite.getPosition().x / 35 % 8;
		//x = x * 12;
		if (x == 0)MySprite.setTextureRect(sf::IntRect(295, 140, 28, 41));
		if (x == 1)MySprite.setTextureRect(sf::IntRect(322, 140, 31, 41));
		if (x == 2)MySprite.setTextureRect(sf::IntRect(355, 140, 31, 41));
		if (x == 3)MySprite.setTextureRect(sf::IntRect(390, 140, 31, 41));
		if (x == 4)MySprite.setTextureRect(sf::IntRect(422, 140, 28, 41));
		if (x == 5)MySprite.setTextureRect(sf::IntRect(449, 140, 31, 41));
		if (x == 6)MySprite.setTextureRect(sf::IntRect(482, 140, 31, 41));
		if (x == 7)MySprite.setTextureRect(sf::IntRect(517, 140, 31, 41));
		//on touvhe pas les w et h
		lastDirection = Left;
	}
	if (U)
	{
		MySprite.setTextureRect(sf::IntRect(12, 78, 22, 45));
		if (lastDirection == Right) {
			
			MySprite.setTextureRect(sf::IntRect(12, 78, 22, 45));
			

		}
		//on touvhe pas les w et h
		if (lastDirection == Left) {
			MySprite.setTextureRect(sf::IntRect(524, 78, 22, 45));

		}
	}
	if (D)
	{
		MySprite.setTextureRect(sf::IntRect(192, 70, 22, 38));
		if (lastDirection == Right) {

			MySprite.setTextureRect(sf::IntRect(192, 70, 22, 38));


		}
		//on touvhe pas les w et h
		if (lastDirection == Left) {
			MySprite.setTextureRect(sf::IntRect(342, 70, 22, 38));

		}

	}
	if (deux)
	{
		int x = static_cast<int>(elapsedTime * 16) % 4;
		if (x == 0) MySprite.setTextureRect(sf::IntRect(12, 199, 32, 45));
		if (x == 1) MySprite.setTextureRect(sf::IntRect(44, 199, 35, 45));
		if (x == 2) MySprite.setTextureRect(sf::IntRect(78, 199, 32, 45));
		if (x == 3) MySprite.setTextureRect(sf::IntRect(110, 199, 29, 45));
		if (lastDirection == Right) {

			int x = static_cast<int>(elapsedTime * 16) % 4;
		if (x == 0) MySprite.setTextureRect(sf::IntRect(12, 199, 32, 45));
		if (x == 1) MySprite.setTextureRect(sf::IntRect(44, 199, 35, 45));
		if (x == 2) MySprite.setTextureRect(sf::IntRect(78, 199, 32, 45));
		if (x == 3) MySprite.setTextureRect(sf::IntRect(110, 199, 29, 45));
	
		}
		if (lastDirection == Left) {
		int x = static_cast<int>(elapsedTime * 16) % 4;
		if (x == 0) MySprite.setTextureRect(sf::IntRect(291, 201, 32, 45));
		if (x == 1) MySprite.setTextureRect(sf::IntRect(324, 201, 30, 45));
		if (x == 2) MySprite.setTextureRect(sf::IntRect(355, 201, 32, 45));
		if (x == 3) MySprite.setTextureRect(sf::IntRect(389, 201, 29, 45));

		}
	}
}
void Luigi::frapperpied(Personnage* cible) {
	cible->recevoir_degats(10);
	cible->reculU();

}
void Luigi::reculU() {
	vitessey = -1 * vie;
}
void Luigi::frapper(Personnage* cible) {
	cible->recevoir_degats(10);
	if (lastDirection == Right)cible->reculD();
	if (lastDirection == Left)cible->reculG();
}
void Luigi::reculD() {

	vitessex = 1 * vie;

}
void Luigi::reculG() {
	vitessex = 1 * vie;
}
void Luigi::dead() {
	if (mort <2) {
		MySprite.setPosition(957, 470);
		vie = 1;
		if (ultime == 0)ultime++;
		mort += 1;
	}
}