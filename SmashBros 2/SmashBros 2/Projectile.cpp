#include "Projectile.h"
#include<iostream>
Projectile::Projectile( sf::Vector2f pos)
{
	vitessex = 1;
	vitessey = 0;
	if (!texture.loadFromFile("cara.png")) {
		std::cout << "Erreur lors du chargement de l'image perso.png" << std::endl;

	}
	MySprite.setTexture(texture);
	MySprite.setPosition(pos);
	//MySprite.setTextureRect(sf::IntRect(18, 22, 24, 40));
  

    
}
sf::Sprite Projectile::GetMySprite() {
	
		return MySprite;
	
}