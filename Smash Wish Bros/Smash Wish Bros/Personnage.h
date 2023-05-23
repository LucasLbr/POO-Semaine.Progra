#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Personnage
{
protected:
    int vie;
    bool position_defensive;
    
  
public:
    Personnage();
    virtual void recevoir_degats(int degats);
    virtual void frapper(Personnage* cible);
    virtual void attaque_spécial(Personnage* cible);
    virtual void bouclier();
   
    int get_vie();
};