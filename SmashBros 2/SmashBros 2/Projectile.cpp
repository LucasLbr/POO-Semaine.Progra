#include "Projectile.h"

#include<iostream>
#include <vector>
Projectile::Projectile( sf::Vector2f pos,bool droite)
{
	if (droite)
	{
		vitessex = 300;
	}
	else {
		vitessex = -300;
	}
	
	vitessey = 0;
	if (!texture.loadFromFile("bomb.png")) {
		std::cout << "Erreur lors du chargement de l'image perso.png" << std::endl;

	}
	MySprite.setTexture(texture);
	MySprite.setPosition(pos);
	MySprite.setTextureRect(sf::IntRect(0, 0, 30, 29));
	if (!droite)
	{
		MySprite.setScale(-1, 1);
	}

    
}
void Projectile::frapper(Personnage* cible)
{
	cible->recevoir_degats(20);
	cible->reculU();
}
sf::FloatRect Projectile::ProjectileglobalPosition()
{
	return MySprite.getGlobalBounds();
}
sf::Sprite Projectile::GetMySprite() {
	
		return MySprite;
	
}
void Projectile::bouge(sf::Time DI)
{
	MySprite.move(vitessex * DI.asSeconds(), vitessey * DI.asSeconds());

}
void Projectile::changement_vitesseG() {
	vitessex = -20;
}