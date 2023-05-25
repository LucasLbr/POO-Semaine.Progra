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

/*void Personnage::lancer(Projectile* projectile) {
	
}*/
void Personnage::lancer(std::vector<Projectile*>* X){
	
	{
		//int vitesse;
		//sio mario D, vitesse = 50
			X->push_back(new Projectile(MySprite.getPosition()));
		//X->push_back(new Projectile(sf::Vector2f(750, 500)));
	}
}
void Personnage::pesanteur()
{
	vitessey += 10;
}
void Personnage::posture(bool U, bool D, bool R, bool L, bool un, bool deux,bool trois){}
void Personnage::positionDebut(int x, int y) {
	return MySprite.setPosition(sf::Vector2f(x, y));
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
sf::FloatRect Personnage::PersonnageglobalPosition()
{
	return MySprite.getGlobalBounds();
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
void Personnage::collision() {
	vitessey = 0;
	MySprite.move(0, -2);
	UpIsPressed = true;
}
void Personnage::bouge(sf::Time DI)
{
	MySprite.move(vitessex * DI.asSeconds(), vitessey * DI.asSeconds());

}
sf::Sprite Personnage::GetMySprite() {
	return MySprite;
}
void  Personnage::frapper(Personnage* cible)
{
	cible->recevoir_degats(5);
	position_defensive = false;
}
void Personnage::frapperpied(Personnage* cible){

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
void Personnage:: reculU() {}

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