#include "Mario.h"
#include <iostream>
Mario::Mario() :Personnage()
{

	if (!texture.loadFromFile("Mariobis.png")) {
		std::cout << "Erreur lors du chargement de l'image perso.png" << std::endl;

	}
	MySprite.setTexture(texture);
	MySprite.setTextureRect(sf::IntRect(18, 22, 24, 40));
	MySprite.setPosition(sf::Vector2f(750, 500));
	//lastDirection = Right;
	vitessey = 0;
	vitessex = 0;
}

sf::Sprite Mario::GetMySprite() {
	return MySprite;
}
void Mario::bouge(sf::Time DI)
{
	MySprite.move(vitessex * DI.asSeconds(), vitessey * DI.asSeconds());
	
}
sf::FloatRect Mario::marioglobalPosition()
{
	return MySprite.getGlobalBounds();
}
void Mario::collision() {
	vitessey=0;
	MySprite.move(0, -2);
	UpIsPressed = true;
}
void Mario::collimonter() {
	vitessey = 0;
	MySprite.move(0, -2);
	UpIsPressed = true;
	
}
void Mario::posture(bool U, bool D, bool R, bool L,bool un,bool deux) {

	// Obtenir le temps écoulé depuis le début du programme en secondes
	float elapsedTime = animationClock.getElapsedTime().asSeconds();

	// Animation du personnage en fonction du temps

	if (un)
	{
		int x = static_cast<int>(elapsedTime * 16) % 6;
		if (x == 0) MySprite.setTextureRect(sf::IntRect(0, 190, 38, 40));
		if (x == 1) MySprite.setTextureRect(sf::IntRect(43, 190, 50, 40));
		if (x == 2) MySprite.setTextureRect(sf::IntRect(93, 190, 48, 40));
		if (x == 3) MySprite.setTextureRect(sf::IntRect(141, 190, 38, 40));
		if (x == 4) MySprite.setTextureRect(sf::IntRect(182, 190, 38, 40));
		if (x == 5) MySprite.setTextureRect(sf::IntRect(222, 190, 38, 40));
		if (lastDirection == Right) {
			int x = static_cast<int>(elapsedTime * 16) % 6;
			if (x == 0) MySprite.setTextureRect(sf::IntRect(0, 190, 38, 40));
			if (x == 1) MySprite.setTextureRect(sf::IntRect(43, 190, 50, 40));
			if (x == 2) MySprite.setTextureRect(sf::IntRect(93, 190, 48, 40));
			if (x == 3) MySprite.setTextureRect(sf::IntRect(141, 190, 38, 40));
			if (x == 4) MySprite.setTextureRect(sf::IntRect(182, 190, 38, 40));
			if (x == 5) MySprite.setTextureRect(sf::IntRect(222, 190, 38, 40));
			
		}
		if (lastDirection==Left) {
			int x = static_cast<int>(elapsedTime * 16) % 6;
			if (x == 0) MySprite.setTextureRect(sf::IntRect(538, 187, 38, 40));
			if (x == 1) MySprite.setTextureRect(sf::IntRect(483, 187, 50, 40));
			if (x == 2) MySprite.setTextureRect(sf::IntRect(436, 187, 46, 40));
			if (x == 3) MySprite.setTextureRect(sf::IntRect(400, 187, 36, 40));
			if (x == 4) MySprite.setTextureRect(sf::IntRect(358, 187, 38, 40));
			if (x == 5) MySprite.setTextureRect(sf::IntRect(322, 187, 35, 40));
		
		}
	}
	if (R)
	{int x = 0;
		x = (int)MySprite.getPosition().x /35% 8;
		//x = x * 12;
		if (x==0)MySprite.setTextureRect(sf::IntRect(12, 142, 31, 45));
		if (x == 1)MySprite.setTextureRect(sf::IntRect(44, 142, 31, 45));
		if (x == 2)MySprite.setTextureRect(sf::IntRect(82, 142, 31, 45));
		if (x == 3)MySprite.setTextureRect(sf::IntRect(116, 142, 28, 45));
		if (x == 4)MySprite.setTextureRect(sf::IntRect(145, 142, 31, 45));
		if (x == 5)MySprite.setTextureRect(sf::IntRect(181, 142, 31, 45));
		if (x == 6)MySprite.setTextureRect(sf::IntRect(220, 142, 31, 45));
		if (x == 7)MySprite.setTextureRect(sf::IntRect(254, 142, 31, 45));
		//on touvhe pas les w et h
		lastDirection = Right;
	}
	if (L)
	{
		int x = 0;
		x = (int)MySprite.getPosition().x / 35 % 8;
		//x = x * 12;
		if (x == 0)MySprite.setTextureRect(sf::IntRect(295, 145, 28, 42));
		if (x == 1)MySprite.setTextureRect(sf::IntRect(328, 145, 31, 42));
		if (x == 2)MySprite.setTextureRect(sf::IntRect(365, 145, 31, 42));
		if (x == 3)MySprite.setTextureRect(sf::IntRect(402, 145, 31, 42));
		if (x == 4)MySprite.setTextureRect(sf::IntRect(435, 145, 28, 42));
		if (x == 5)MySprite.setTextureRect(sf::IntRect(465, 145, 31, 42));
		if (x == 6)MySprite.setTextureRect(sf::IntRect(501, 145, 31, 42));
		if (x == 7)MySprite.setTextureRect(sf::IntRect(535, 145, 31, 42));
		//on touvhe pas les w et h
		lastDirection = Left;
	}
	 if (U)
	{
		MySprite.setTextureRect(sf::IntRect(14, 83, 30, 50));
		if (lastDirection==Right) {
			//int x = 0;
			//x = (int)MySprite.getPosition().y / 25 % 6;
			//x = x * 12;
			MySprite.setTextureRect(sf::IntRect(14, 83, 30, 50));
			//if (x == 1)MySprite.setTextureRect(sf::IntRect(45, 83, 30, 65));
			//if (x == 2)MySprite.setTextureRect(sf::IntRect(78, 83, 30, 65));
			//if (x == 3)MySprite.setTextureRect(sf::IntRect(111, 83, 30, 65));
			//if (x == 4)MySprite.setTextureRect(sf::IntRect(141, 83, 30, 65));
			//if (x == 5)MySprite.setTextureRect(sf::IntRect(171, 83, 30, 65));
		
		}
		//on touvhe pas les w et h
		if (lastDirection==Left) {
			MySprite.setTextureRect(sf::IntRect(535, 83, 30, 50));
			
		}
	}
	if (D)
	{
		MySprite.setTextureRect(sf::IntRect(200, 2, 30, 62));
		if (lastDirection==Right) {
			//int x = 0;
			//x = (int)MySprite.getPosition().y / 25 % 6;
			//x = x * 12;
			MySprite.setTextureRect(sf::IntRect(200, 2, 30, 62));
			//if (x == 1)MySprite.setTextureRect(sf::IntRect(45, 83, 30, 65));
			//if (x == 2)MySprite.setTextureRect(sf::IntRect(78, 83, 30, 65));
			//if (x == 3)MySprite.setTextureRect(sf::IntRect(111, 83, 30, 65));
			//if (x == 4)MySprite.setTextureRect(sf::IntRect(141, 83, 30, 65));
			//if (x == 5)MySprite.setTextureRect(sf::IntRect(171, 83, 30, 65));
			
		}
		//on touvhe pas les w et h
		if (lastDirection==Left) {
			MySprite.setTextureRect(sf::IntRect(313, 0, 30, 62));
		
		}
		
	}
	if (deux)
	{
		int x = static_cast<int>(elapsedTime * 16) % 7;
		if (x == 0) MySprite.setTextureRect(sf::IntRect(10, 233, 28, 40));
		if (x == 1) MySprite.setTextureRect(sf::IntRect(43, 233, 24, 40));
		if (x == 2) MySprite.setTextureRect(sf::IntRect(70, 233, 48, 40));
		if (x == 3) MySprite.setTextureRect(sf::IntRect(122, 233, 38, 40));
		if (x == 4) MySprite.setTextureRect(sf::IntRect(165, 233, 36, 40));
		if (x == 5) MySprite.setTextureRect(sf::IntRect(201, 233, 25, 40));
		if (x == 6) MySprite.setTextureRect(sf::IntRect(229, 233, 38, 40));
		if (lastDirection == Right) {
		
			int x = static_cast<int>(elapsedTime * 16) % 7;
			if (x == 0) MySprite.setTextureRect(sf::IntRect(10, 233, 28, 40));
			if (x == 1) MySprite.setTextureRect(sf::IntRect(43, 233, 24, 40));
			if (x == 2) MySprite.setTextureRect(sf::IntRect(70, 233, 48, 40));
			if (x == 3) MySprite.setTextureRect(sf::IntRect(122, 233, 38, 40));
			if (x == 4) MySprite.setTextureRect(sf::IntRect(165, 233, 36, 40));
			if (x == 5) MySprite.setTextureRect(sf::IntRect(201, 233, 25, 40));
			if (x == 6) MySprite.setTextureRect(sf::IntRect(229, 233, 38, 40));
		}
		if (lastDirection == Left) {
			int x = static_cast<int>(elapsedTime * 16) % 7;
			if (x == 0) MySprite.setTextureRect(sf::IntRect(538, 230, 30, 45));
			if (x == 1) MySprite.setTextureRect(sf::IntRect(510, 230, 24, 45));
			if (x == 2) MySprite.setTextureRect(sf::IntRect(456, 230, 50, 45));
			if (x == 3) MySprite.setTextureRect(sf::IntRect(412, 230, 43, 45));
			if (x == 4) MySprite.setTextureRect(sf::IntRect(377, 230, 35, 45));
			if (x == 5) MySprite.setTextureRect(sf::IntRect(350, 230, 25, 45));
			if (x == 6) MySprite.setTextureRect(sf::IntRect(320, 230, 28, 45));

		}
	}
}
void Mario::reculD() {

	vitessex = 1 * vie;

}
void Mario::reculG() {
	vitessex = -1 * vie;
}
void Mario::frapper(Personnage* cible) {
	cible->recevoir_degats(10);
	if (lastDirection == Right)cible->reculD();
	if (lastDirection == Left)cible->reculG();
}
void Mario::dead() {
	if (mort <= 1) {
		MySprite.setPosition(957, 470);
		vie = 1;
		if (ultime == 0)ultime++;
		mort += 1;
	}


}