#pragma once
#include <SFML/Graphics.hpp>
#include "Personnage.h"
class Projectile
{
protected: sf::Sprite MySprite;
         sf::Texture texture;
         int vitessex;
         int vitessey;
    public:
      
        Projectile( sf::Vector2f pos,bool droite);
        sf::Sprite GetMySprite();
        void bouge(sf::Time DI);
        void changement_vitesseG();
        sf::FloatRect ProjectileglobalPosition();
        void frapper(Personnage* cible);
   
};

