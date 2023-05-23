#include <SFML/Graphics.hpp>
#include <iostream>
#include "Input.h"
#include "Mario.h"
#include "Luigi.h"
void CheckBtn(Mario* x, Luigi* y);

Input input;



//sf::RectangleShape rectangle(sf::Vector2f(50, 50));
//sf::RectangleShape rectangle2(sf::Vector2f(50, 50));
sf::RectangleShape platform(sf::Vector2f(1000, 50));
sf::RectangleShape platform1(sf::Vector2f(200, 25));
sf::RectangleShape platform2(sf::Vector2f(200, 25));

//bool CheckCollision(const Personnage& rect1, const Personnage& rect2);
//bool CheckCollisionWithPlatformmario(const sf::RectangleShape& platform);
//bool CheckCollisionWithPlatformluigi(const sf::RectangleShape& platform);
int main()
{
    int screenw = 1920;
    int screenh = 1080;
    sf::RenderWindow window(sf::VideoMode(screenw, screenh), "Smash Wish Bros");
    window.setFramerateLimit(60);
    //perso
    Mario *mario=new Mario();
    Luigi *luigi=new Luigi();
    
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

        CheckBtn(mario,luigi);

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

       /* if (CheckCollisionWithPlatformmario(platform) ||
            CheckCollisionWithPlatformmario( platform1) ||
            CheckCollisionWithPlatformmario(platform2)) {
            // Handle collision between rectangle and platforms
            // For example, stop the movement of rectangle
            mario->up();
        }*/

       /* if (CheckCollisionWithPlatformluigi( platform) ||
            CheckCollisionWithPlatformluigi( platform1) ||
            CheckCollisionWithPlatformluigi( platform2)) {
            // Handle collision between rectangle2 and platforms
            // For example, stop the movement of rectangle2
            luigi->up();
        }*/

        window.clear();
        //window.draw(rectangle);
       window.draw(mario->GetMySprite());
       window.draw(luigi->GetMySprite());
       // window.draw(rectangle2);
       // window.draw(luigi.LuigiGetRect());
        window.draw(platform);
        window.draw(platform1);
        window.draw(platform2);
        window.display();
    }

    return 0;
}

void CheckBtn(Mario *x,Luigi *y)
{
    Vector2f currentPosition = x->marioPosition();
    Vector2f currentPosition2 = y->LuigiPosition();
    if (input.GetButton().up == true)
    {
        x->up();
    }
    if (input.GetButton().down == true)
    {
        x->down();
    }
    if (input.GetButton().left == true)
    {
        x->left();
    }
    if (input.GetButton().right == true)
    {
        x->right();
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
    if (x->marioglobalPosition().intersects(platform.getGlobalBounds()))
    {
        // Rétablissez la position précédente du personnage
        x->mariosetPosition(currentPosition);
    }
    // -----------------j2-------------
    if (input.GetButton().z == true)
    {
        y->up();
    }
    if (input.GetButton().s == true)
    {
        y->down();
    }
    if (input.GetButton().q == true)
    {
        y->left();
    }
    if (input.GetButton().d == true)
    {
        y->right();
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
    if (y->LuigiglobalPosition().intersects(platform.getGlobalBounds()))
    {
        // Rétablissez la position précédente du personnage
        y->LuigisetPosition(currentPosition2);
    }
}

/*bool CheckCollision(const Personnage& rect1, const Personnage& rect2)
{
    return rect1.getGlobalBounds().intersects(rect2.getGlobalBounds());
}

bool CheckCollisionWithPlatformmario(const sf::RectangleShape& platform)
{

    return mario.marioglobalPosition().intersects(platform.getGlobalBounds());
}
bool CheckCollisionWithPlatformluigi(const sf::RectangleShape& platform)
{

    return  luigi.LuigiglobalPosition().intersects(platform.getGlobalBounds());
}
*/