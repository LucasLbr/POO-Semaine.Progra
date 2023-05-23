#include "Personnage.h"
#include <SFML/Graphics.hpp>

Personnage::Personnage()
{
   
    vie = 0;
    position_defensive = false;
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