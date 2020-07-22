#include "game.h"
#include "player.h"
#include "player.cpp"
#include "food.h"
#include "food.cpp"
#include "collision.h"
#include <iostream>

Game_Window::Game_Window(int WIDTH, int HEIGHT):m_width(WIDTH), m_height(HEIGHT)
{
    window.create(sf::VideoMode(m_width, m_height), "SNAKE", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
}

void Game_Window::Show_Window()
{
    sf::Clock clock;
    Collision collision;
    Food food(m_width, m_height, 10);
    Player player(10, 400, 300);
    int start_direction = 1;

    food.set_food_position();
    player.set_start_position();

    while(window.isOpen())
    {
        sf::Event event;
        float time = clock.getElapsedTime().asSeconds() ;
        if (time >= 1.0)
        {
            player.move(start_direction);
            collision.if_snake_out_of_window(window, player.get_snakes_table());
            clock.restart();
        }
        while (window.pollEvent(event)) {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if (collision.if_snakes_with_body_collision(player.get_snakes_table()))
                    {
                        if (event.key.code == sf::Keyboard::Enter)
                        {
                            //food.set_food_position();
                            player.set_start_position();
                        }
                        else if (event.key.code == sf::Keyboard::Escape)
                        {
                            window.close();
                        }
                    }
                    else
                    {
                        player.set_direction(event, start_direction);
                    }
            }
        }
        window.clear(sf::Color(255,255,255));
        player.draw_snake(window);
        food.draw_food(window);
        window.display();
    }
}





