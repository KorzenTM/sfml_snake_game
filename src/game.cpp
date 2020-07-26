#include "game.h"
#include "player.h"
#include "player.cpp"
#include "food.h"
#include "food.cpp"
#include "collision.h"
#include "informations.h"
#include "score_board.h"
#include <iostream>

Game_Window::Game_Window(int WIDTH, int HEIGHT):m_width(WIDTH), m_height(HEIGHT)
{
    window.create(sf::VideoMode(m_width, m_height), "SNAKE", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
}

void Game_Window::Show_Window()
{
    sf::Clock clock;
    Score_Board score_board("..\\fonts\\arial.ttf", 0);
    Informations informations("..\\fonts\\arial.ttf");
    Collision collision;
    Food food(m_width, m_height, 10);
    Player player(10, 400, 300);
    int start_direction = 1;

    food.set_food_position();
    player.set_start_position();

    while(window.isOpen())
    {
        sf::Event event;
        float time = clock.getElapsedTime().asSeconds();

        if (time >= 1.0)
        {
            player.move(start_direction);
            collision.if_snake_out_of_window(window, player.get_snakes_table());
            informations.clear_text();
            clock.restart();
        }

        while (window.pollEvent(event)) {
            switch (event.type)
            {
                case sf::Event::KeyPressed:
                    player.set_direction(event, start_direction);
                    break;
            }
        }

        if (collision.if_snakes_with_body_collision(player.get_snakes_table()))
        {
            informations.collision_information();
            player.set_snake_speed(0.f);
            score_board.reset_points();
            if (event.key.code == sf::Keyboard::Enter)
            {
                food.set_food_position();
                player.set_start_position();
                informations.clear_text();
                start_direction = 1;
            }
            else if (event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
        else if (collision.if_snake_eat_food(food.get_food_global_bounds(), player.get_snake_global_bounds()))
        {
            informations.getting_points_information(food.get_food_position());
            food.set_food_position();
            player.resize_snake();
            score_board.add_score();
        }
        else if (collision.if_food_generate_on_snake(player.get_snakes_table(), food.get_food_global_bounds()))
        {
            food.set_food_position();
        }

        score_board.create_score_board(m_width, m_height);
        window.clear(sf::Color(255,255,255));
        player.draw_snake(window);
        food.draw_food(window);
        informations.draw_informations(window);
        score_board.draw_score_board(window);
        window.display();
    }
}





