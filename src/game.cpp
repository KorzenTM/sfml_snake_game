#include "game.h"
#include "player.h"
#include "food.h"
#include "collision.h"
#include "informations.h"
#include "score_board.h"
#include "game_menu.h"
#include <iostream>

Game_Board::Game_Board()
{

}

void Game_Board::show_game_board(sf::RenderWindow &thatWindow)
{
    sf::Clock clock;
    Score_Board score_board("..\\fonts\\arial.ttf", 0);
    Informations informations("..\\fonts\\arial.ttf", thatWindow.getSize().x, thatWindow.getSize().y);
    Collision collision;
    Food food(thatWindow.getSize().x, thatWindow.getSize().y, 10);
    Player player(10, 400, 300);
    int start_direction = 1;

    food.set_food_position();
    player.set_start_position();

    while(thatWindow.isOpen())
    {
        sf::Event event;
        float time = clock.getElapsedTime().asSeconds();

        if (time >= 1.0)
        {
            player.move(start_direction);
            collision.if_snake_out_of_window(thatWindow, player.get_snakes_table());
            informations.clear_getting_points_information();
            clock.restart();
        }

        while (thatWindow.pollEvent(event)) {
            switch (event.type)
            {
                case sf::Event::Closed:
                    thatWindow.close();
                    break;
                case sf::Event::KeyPressed:
                    player.set_direction(event, start_direction);
                    break;
            }
        }

        if (collision.if_snakes_with_body_collision(player.get_snakes_table()))
        {
            informations.show_collision_information();
            player.set_snake_speed(0.f);
            score_board.reset_points();
            if (event.key.code == sf::Keyboard::Enter)
            {
                food.set_food_position();
                player.set_start_position();
                informations.clear_collision_information();
                start_direction = 1;
            }
            else if (event.key.code == sf::Keyboard::Escape)
            {
                Game_Menu gameMenu(thatWindow.getSize().x, thatWindow.getSize().y);
                thatWindow.close();
                gameMenu.show_menu();
            }
        }
        else if (collision.if_snake_eat_food(food.get_food_global_bounds(), player.get_snake_global_bounds()))
        {
            informations.show_getting_points_information(food.get_food_position());
            food.set_food_position();
            player.resize_snake();
            score_board.add_score();
        }
        else if (collision.if_food_generate_on_snake(player.get_snakes_table(), food.get_food_global_bounds()))
        {
            food.set_food_position();
        }

        score_board.create_score_board(thatWindow.getSize().x, thatWindow.getSize().y);
        thatWindow.clear(sf::Color(255,255,255));
        player.draw_snake(thatWindow);
        food.draw_food(thatWindow);
        informations.draw_informations(thatWindow);
        score_board.draw_score_board(thatWindow);
        thatWindow.display();
    }
}





