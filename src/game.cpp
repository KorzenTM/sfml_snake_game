#include "game.h"
#include "player.h"
#include "player.cpp"
#include "food.h"
#include "food.cpp"


Game_Window::Game_Window(int WIDTH, int HEIGHT):m_width(WIDTH), m_height(HEIGHT)
{
    window.create(sf::VideoMode(m_width, m_height), "SNAKE", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(1);
}

void Game_Window::Show_Window()
{
    //srand(time(NULL));
    //food.food.setPosition((std::rand()%(WIDTH/20)+0)*20,(std::rand()%(HEIGHT/20)+0)*20);
    Player player(10, 400, 300);
    player.set_start_position();
    while(window.isOpen())
    {
        sf::Event event;
        player.move();
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code==sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    else
                    {
                        player.snake_control(event, window);
                    }
            }
        }

        window.clear();
        player.draw_snake(window);
        window.display();
    }
}




