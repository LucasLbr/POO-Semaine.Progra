#pragma once
#include <SFML/Graphics.hpp>
class Projectile
{
protected: sf::Sprite MySprite;
         sf::Texture texture;
         int vitessex;
         int vitessey;
    public:
      
        Projectile( sf::Vector2f pos);
        sf::Sprite GetMySprite();

       
   
};

