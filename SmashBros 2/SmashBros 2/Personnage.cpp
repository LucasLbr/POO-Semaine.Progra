#include "Personnage.h"

Personnage::Personnage()
{

	vie = 0;
	position_defensive = false;
	
	vitessey = 0;
	vitessex = 0;
	vitessegravit = 0;
	UpIsPressed = true;
	bagarre = true;
}

void Personnage::pesanteur()
{
	vitessey += 10;
}


/*void Personnage::bouge(sf::Time DI)
{
	sprite.move(vitessex * DI.asSeconds(), vitessey * DI.asSeconds());
}*/

void Personnage::changement_vitesse(bool U, bool D, bool R, bool L, sf::Time dureeIteration)
{
	//std::cout << vitessex << std::endl;
	if (D)
	{
		if (vitessey < 400)
		{
			vitessey += 800 * dureeIteration.asSeconds();
		}
	}
	if (U&&UpIsPressed)
	{
		if (vitessey > -1400)
		{
			vitessey -= 700 ;
		}
		UpIsPressed = false;
	}
	if (R)
	{
		if (vitessex < 400)
		{
			vitessex += 800 * dureeIteration.asSeconds();
		}
	}
	if (L)
	{
		if (vitessex > -400)
		{
			vitessex -= 800 * dureeIteration.asSeconds();
		}
	}
}
bool Personnage::contact() {
	return bagarre;
}
void  Personnage::recevoir_degats(int degats)
{
	if (position_defensive == true) vie = vie;
	else vie += degats;
}
void  Personnage::frapper(Personnage* cible)
{
	cible->recevoir_degats(5);
	position_defensive = false;
}
void  Personnage::attaque_spécial(Personnage* cible)
{
	cible->recevoir_degats(40);
	position_defensive = false;
}
void  Personnage::bouclier()
{
	position_defensive = true;

}

int  Personnage::get_vie()
{
	return vie;
}