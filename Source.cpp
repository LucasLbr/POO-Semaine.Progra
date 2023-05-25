#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include <math.h>
#include <cstdlib>
#include <vector>

using namespace sf;

class Bullet
{
public:
    Sprite shape;
    Bullet(Texture* texture, Vector2f pos)
    {
        this->shape.setTexture(*texture);
        this->shape.setScale(0.3f, 0.3f);

        this->shape.setPosition(pos);
    }

    ~Bullet()
    {

    }
};

class Player
{
public:
    Sprite shape;
    Texture *texture;
    int HP;
    int HPMax;

     std::vector <Bullet> bullets;

    Player(Texture *texture )
    {  
        this->HPMax = 10;
        this->HP = this->HPMax;

        this->texture = texture;
        this->shape.setTexture(*texture);

        this->shape.setScale(0.5f, 0.5f);
        
    }
    ~Player()
    {

    }
};


class Enemy
{
public:
    Sprite shape;
    int HP;
    int HPMax;
    
    Enemy(Texture* texture, Vector2u windowSize)
    {
        this->  HPMax = rand() % 3 + 1;
        this-> HP = this->HPMax;

        this->shape.setTexture(*texture);

        this->shape.setScale(0.5f, 0.5f);

        this->shape.setPosition(windowSize.x-this->shape.getGlobalBounds().width, rand()% (int)(windowSize.y- this->shape.getGlobalBounds().height));
    }

    ~Enemy()
    {

   }
};









int main()
{
    srand(time(NULL));

   
    RenderWindow window(VideoMode(800, 600), "Spaceship Action!", Style::Default);
    window.setFramerateLimit(60);
  
    // init text
    Font font;
    font.loadFromFile("Textures/Dosis-Light.ttf");

    // init textures
    Texture playerTex;
    playerTex.loadFromFile("Textures/Green.png");

    Texture enemyTex;
    enemyTex.loadFromFile("Textures/Red.png");

    Texture bulletTex;
    bulletTex.loadFromFile("Textures/laser.png");

    //UI init
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(Color::White);
    scoreText.setPosition(10.f, 10.f);

    Text gameOvertext;
    gameOvertext.setFont(font);
    gameOvertext.setCharacterSize(30);
    gameOvertext.setFillColor(Color::Red);
    gameOvertext.setPosition(100.f, window.getSize().y / 2); // mettre au centre
    gameOvertext.setString("GAME OVER");

    // Player init
    int score = 0;
    Player player(&playerTex);
    int shootTimer = 20;

    Text hpText;
    hpText.setFont(font);
    hpText.setCharacterSize(12);
    hpText.setFillColor(Color::White);

    //Enemy init
    int enemySpawnTimer = 0;
    std::vector<Enemy> enemies;

    Text eHpText;
    eHpText.setFont(font);
    eHpText.setCharacterSize(12);
    eHpText.setFillColor(Color::White);


        while (window.isOpen())
        {
           
            sf::Event event;
            while (window.pollEvent(event))
            {
             
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            if (player.HP > 0)
            {


                //Player update
                if (Keyboard::isKeyPressed(Keyboard::Z)) //Haut
                    player.shape.move(0.f, -10.f);
                if (Keyboard::isKeyPressed(Keyboard::Q)) //G
                    player.shape.move(-10.f, 0.f);
                if (Keyboard::isKeyPressed(Keyboard::S)) //bas
                    player.shape.move(0.f, 10.f);
                if (Keyboard::isKeyPressed(Keyboard::D)) //D
                    player.shape.move(10.f, 0.f);

                hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - hpText.getGlobalBounds().height);
                hpText.setString(std::to_string(player.HP) + "/" + std::to_string(player.HPMax));


                //Collision with window
                if (player.shape.getPosition().x <= 0) //LEFT
                    player.shape.setPosition(0.f, player.shape.getPosition().y);
                if (player.shape.getPosition().x >= window.getSize().x - player.shape.getGlobalBounds().width) //RIGHT
                    player.shape.setPosition(window.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);
                if (player.shape.getPosition().y <= 0) //TOP
                    player.shape.setPosition(player.shape.getPosition().x, 0.f);
                if (player.shape.getPosition().y >= window.getSize().y - player.shape.getGlobalBounds().height) //BOTTOM
                    player.shape.setPosition(player.shape.getPosition().x, window.getSize().y - player.shape.getGlobalBounds().height);



                //Update controls
                if (shootTimer < 15)
                    shootTimer++;



                if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 15) //shooting
                {
                    player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
                    shootTimer = 0; //reset le timer
                }

                //Bullets

                for (size_t i = 0; i < player.bullets.size(); i++)
                {

                    //Move
                    player.bullets[i].shape.move(20.f, 0.f);
                    //Out of window bounds
                    if (player.bullets[i].shape.getPosition().x > window.getSize().x)
                    {
                        player.bullets.erase(player.bullets.begin() + i);
                        break;
                    }



                    //Enemy collision

                    for (size_t k = 0; k < enemies.size(); k++)
                    {
                        if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
                        {
                            if (enemies[k].HP <= 1)
                            {
                                score += enemies[k].HPMax; //+ de score + d'hp
                                enemies.erase(enemies.begin() + k); // attention order
                            }

                            else
                                enemies[k].HP--; // enemy taking dmgs

                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }
                    }

                }

                //Enemy spawner
                if (enemySpawnTimer < 20)
                    enemySpawnTimer++;

                if (enemySpawnTimer >= 20)
                {

                    enemies.push_back(Enemy(&enemyTex, window.getSize()));
                    enemySpawnTimer = 0; //reset timer
                }


                for (size_t i = 0; i < enemies.size(); i++)
                {
                    enemies[i].shape.move(-4.f, 0.f); //i c'est pour la position -> vecteur
                    if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
                    {
                        enemies.erase(enemies.begin() + i); //retire 
                        break;
                    }


                    if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                    {
                        enemies.erase(enemies.begin() + i);

                        player.HP--; //player dmg
                    }

                }

                //UI Update
                scoreText.setString("Score: " + std::to_string(score));

            }
            //Draw ================================================
            window.clear();


            //player
            window.draw(player.shape);

            //Bullets
            for (size_t i = 0; i < player.bullets.size(); i++)
            {
                window.draw(player.bullets[i].shape);
            }
          
            //enemy
            for (size_t i = 0; i < enemies.size(); i++)
            {
                eHpText.setString(std::to_string(enemies[i].HP) + "/" + std::to_string(enemies[i].HPMax));
                eHpText.setPosition(enemies[i].shape.getPosition().x, enemies[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                window.draw(eHpText);
                window.draw(enemies[i].shape);
            }
                //UI
             window.draw(scoreText);
             window.draw(hpText);

             if (player.HP <= 0)
             window.draw(gameOvertext);




            window.display();
    


        }
        
        
    return 0;
}