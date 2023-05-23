#include <SFML/Graphics.hpp>
#include <iostream>
#include "Input.h"
#include "Mario.h"
#include "Luigi.h"
void CheckBtn();

Input input;

Mario mario;
Luigi luigi;
//sf::RectangleShape rectangle(sf::Vector2f(50, 50));
//sf::RectangleShape rectangle2(sf::Vector2f(50, 50));
sf::RectangleShape platform(sf::Vector2f(1000, 50));
sf::RectangleShape platform1(sf::Vector2f(200, 25));
sf::RectangleShape platform2(sf::Vector2f(200, 25));

//bool CheckCollision(const Personnage& rect1, const Personnage& rect2);
bool CheckCollisionWithPlatformmario(const sf::RectangleShape& platform);
bool CheckCollisionWithPlatformluigi(const sf::RectangleShape& platform);
int main()
{
    int screenw = 1920;
    int screenh = 1080;
    sf::RenderWindow window(sf::VideoMode(screenw, screenh), "Smash Wish Bros");
    window.setFramerateLimit(60);
    //perso
   // rectangle.setFillColor(sf::Color::Red);
   // rectangle.setPosition(560, 650);
    //rectangle2.setFillColor(sf::Color::Green);
    //rectangle2.setPosition(1340, 650);
    //arene
    platform.setPosition(460, 700);
    platform.setFillColor(sf::Color::White);
    platform1.setPosition(500, 500);
    platform1.setFillColor(sf::Color::White);
    platform2.setPosition(1200, 500);
    platform2.setFillColor(sf::Color::White);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
               window.close();
            }
            input.InputHandler(event, window);
        }

        CheckBtn();

       // if (CheckCollision(mario, rectangle2)) {
            // Handle collision between rectangle and rectangle2
            // For example, change their colors
          //  mario.setFillColor(sf::Color::Yellow);
           // rectangle2.setFillColor(sf::Color::Yellow);
        //}
        //else {
            // No collision, restore their colors
           // rectangle.setFillColor(sf::Color::Red);
           // rectangle2.setFillColor(sf::Color::Green);
       // }

        if (CheckCollisionWithPlatformmario(platform) ||
            CheckCollisionWithPlatformmario( platform1) ||
            CheckCollisionWithPlatformmario(platform2)) {
            // Handle collision between rectangle and platforms
            // For example, stop the movement of rectangle
            mario.up();
        }

        if (CheckCollisionWithPlatformluigi( platform) ||
            CheckCollisionWithPlatformluigi( platform1) ||
            CheckCollisionWithPlatformluigi( platform2)) {
            // Handle collision between rectangle2 and platforms
            // For example, stop the movement of rectangle2
            luigi.up();
        }

        window.clear();
        //window.draw(rectangle);
       window.draw(* (mario.GetMySprite()));
       // window.draw(rectangle2);
       // window.draw(luigi.LuigiGetRect());
        window.draw(platform);
        window.draw(platform1);
        window.draw(platform2);
        window.display();
    }

    return 0;
}

void CheckBtn()
{
    Vector2f currentPosition = mario.marioPosition();
    Vector2f currentPosition2 = luigi.LuigiPosition();
    if (input.GetButton().up == true)
    {
        mario.up();
    }
    if (input.GetButton().down == true)
    {
        
    }
    if (input.GetButton().left == true)
    {
        mario.left();
    }
    if (input.GetButton().right == true)
    {
        mario.right();
    }
    if (input.GetButton().key1 == true)
    {

    }
    if (input.GetButton().key2 == true)
    {

    }
    if (input.GetButton().key3 == true)
    {

    }
    if (mario.marioglobalPosition().intersects(platform.getGlobalBounds()))
    {
        // Rétablissez la position précédente du personnage
        mario.mariosetPosition(currentPosition);
    }
    // -----------------j2-------------
    if (input.GetButton().z == true)
    {
        luigi.up();
    }
    if (input.GetButton().s == true)
    {
      
    }
    if (input.GetButton().q == true)
    {
        luigi.left();
    }
    if (input.GetButton().d == true)
    {
        luigi.right();
    }
    if (input.GetButton().g == true)
    {

    }
    if (input.GetButton().h == true)
    {

    }
    if (input.GetButton().j == true)
    {

    }
    if (luigi.LuigiglobalPosition().intersects(platform.getGlobalBounds()))
    {
        // Rétablissez la position précédente du personnage
        luigi.LuigisetPosition(currentPosition2);
    }
}

/*bool CheckCollision(const Personnage& rect1, const Personnage& rect2)
{
    return rect1.getGlobalBounds().intersects(rect2.getGlobalBounds());
}*/

bool CheckCollisionWithPlatformmario(const sf::RectangleShape& platform)
{
    
   return mario.marioglobalPosition().intersects(platform.getGlobalBounds());
}
bool CheckCollisionWithPlatformluigi(const sf::RectangleShape& platform)
{

    return  luigi.LuigiglobalPosition().intersects(platform.getGlobalBounds());
}
