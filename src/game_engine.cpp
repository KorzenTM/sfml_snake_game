#include "game_engine.h"
#include <iostream>

#define WIDTH 800
#define HEIGHT 600
float position[1];

void Game_Engine::processEvents(sf::Event event,sf::RenderWindow &thatWindow,sf::RectangleShape &snake)
{
    position[0]=snake.getPosition().x;
    position[1]=snake.getPosition().y;
    std::cout<<"x:"<<snake.getPosition().x<<std::endl;
    std::cout<<"y:"<<snake.getPosition().y<<std::endl;

    if(snake.getPosition().y>HEIGHT)
    {
        snake.setPosition(position[0],0.f);
    }
    if(snake.getPosition().y<0.f)
    {
        position[1]=snake.getPosition().y;
        snake.setPosition(position[0],HEIGHT);
    }
    if(snake.getPosition().x>WIDTH)
    {
        position[0]=snake.getPosition().x;
        snake.setPosition(0.f,position[1]);
    }
    if(snake.getPosition().x<0.f)
    {
        position[0]=snake.getPosition().x;
        snake.setPosition(WIDTH,position[1]);
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
            if(event.key.code==sf::Keyboard::Space)
            {
                snake.setPosition(400.f,300.f);
            }
            if(event.key.code==sf::Keyboard::W)
            {
                snake.move(0,-20);
            }
            if(event.key.code==sf::Keyboard::S)
            {
                snake.move(0,20);
            }
            if(event.key.code==sf::Keyboard::D)
            {
                snake.move(20,0);
            }
            if(event.key.code==sf::Keyboard::A)
            {
                snake.move(-20,0);
            }
            
            break;
        }
    }
}