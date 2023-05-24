#include "Personnage.h"

Personnage::Personnage()
{

	vie = 1;
	position_defensive = false;
	
	vitessey = 0;
	vitessex = 0;
	vitessegravit = 0;
	UpIsPressed = true;
	bagarre = true;
	lastDirection = Right;
	ultime = 0;
	mort = 0;
}

void Personnage::pesanteur()
{
	vitessey += 10;
}



void Personnage::changement_vitesse(bool U, bool D, bool R, bool L, sf::Time dureeIteration)
{
	//std::cout << vitessex << std::endl;
	if (D)
	{
		
		vitessex = 0;
	}
	if (U&&UpIsPressed)
	{
		if (vitessey > -700)
		{
			vitessey -= 400 ;
		}
		UpIsPressed = false;
	}
	if (R)
	{
		if (vitessex <200)
		{
			vitessex += 400 * dureeIteration.asSeconds();
		}
	}
	if (L)
	{
		if (vitessex > -200)
		{
			vitessex -= 400 * dureeIteration.asSeconds();
		}
	}
}
bool Personnage::contact() {
	return bagarre;
}
void  Personnage::recevoir_degats(int degats)
{
	if (position_defensive == true) {
		
	}
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
void  Personnage::bouclier(bool x)
{
	if(x==true)position_defensive = true;

}

int  Personnage::get_vie()
{
	return vie;
}

void Personnage::reculD() {

	

}
void Personnage::reculG() {
	
}
void Personnage::dead() {
	vie = 1;
	if(ultime==0)ultime++;
	
	
}