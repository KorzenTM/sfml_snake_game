#include "game_engine.h"
#include <iostream>

#define WIDTH 800
#define HEIGHT 600
float position[1];

void Game_Engine::move(sf::Event event,sf::RectangleShape &snake_1,sf::RectangleShape &snake_2,sf::RectangleShape &snake_3)
{
    int x_1=snake_1.getPosition().x;
    int y_1=snake_1.getPosition().y;
    int x_2=snake_2.getPosition().x;
    int y_2=snake_2.getPosition().y;
    if(event.key.code==sf::Keyboard::Space)
    {
        snake_1.setPosition(WIDTH/2,HEIGHT/2);
        snake_2.setPosition((WIDTH/2)-20,HEIGHT/2);
        snake_3.setPosition((WIDTH/2)-40,HEIGHT/2);
    }
    if(event.key.code==sf::Keyboard::W)
    {
        snake_1.move(0,-20);
        snake_2.setPosition(x_1,y_1);
        snake_3.setPosition(x_2,y_2);
    }
    if(event.key.code==sf::Keyboard::S)
    {
        snake_1.move(0,20);
        snake_2.setPosition(x_1,y_1);
        snake_3.setPosition(x_2,y_2);
    }
     if(event.key.code==sf::Keyboard::D)
    {
        snake_1.move(20,0);
        snake_2.setPosition(x_1,y_1);
        snake_3.setPosition(x_2,y_2);
    }
    if(event.key.code==sf::Keyboard::A)
    {
        snake_1.move(-20,0);
        snake_2.setPosition(x_1,y_1);
        snake_3.setPosition(x_2,y_2);
     }
}

void Game_Engine::processEvents(sf::Event event,sf::RenderWindow &thatWindow,sf::RectangleShape &snake_1,sf::RectangleShape &snake_2,sf::RectangleShape &snake_3,sf::CircleShape &food)
{
    position[0]=snake_1.getPosition().x;
    position[1]=snake_1.getPosition().y;
    std::cout<<"x:"<<snake_1.getPosition().x<<std::endl;
    std::cout<<"y:"<<snake_1.getPosition().y<<std::endl;
    if (snake_1.getGlobalBounds().intersects(food.getGlobalBounds()))
    {
            std::cout << "Collision!" << std::endl;
    }
    if(snake_1.getPosition().y>HEIGHT)
    {
        snake_1.setPosition(position[0],0.f);
    }
    if(snake_1.getPosition().y<0.f)
    {
        position[1]=snake_1.getPosition().y;
        snake_1.setPosition(position[0],HEIGHT);
    }
    if(snake_1.getPosition().x>WIDTH)
    {
        position[0]=snake_1.getPosition().x;
        snake_1.setPosition(0.f,position[1]);
    }
    if(snake_1.getPosition().x<0.f)
    {
        position[0]=snake_1.getPosition().x;
        snake_1.setPosition(WIDTH,position[1]);
    }
    while(thatWindow.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
            thatWindow.close();
            break;
            case sf::Event::KeyPressed:
            if(event.key.code==sf::Keyboard::Escape)
            {
                thatWindow.close();
            }
            else
            {
                move(event,snake_1,snake_2,snake_3);
            }

        }
    }
}


