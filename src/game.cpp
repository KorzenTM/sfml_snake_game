#include "game.h"
#include "player.h"
#include "food.h"
#include "collision.h"
#include "Subtitles.h"
#include "score_board.h"
#include "game_menu.h"
#include "textures.h"
#include "images.h"

Game_Board::Game_Board() {}

void Game_Board::show_game_board(sf::RenderWindow &thatWindow)
{
    sf::Clock clock;
    Score_Board score_board("..\\fonts\\arial.ttf", 0);
    Subtitles informations("..\\fonts\\arial.ttf", thatWindow.getSize().x, thatWindow.getSize().y);
    Collision collision;
    Food food(std::__cxx11::string(), thatWindow.getSize().x, thatWindow.getSize().y, 20);
    Player player(10, 400, 320);
    Images game_background("..\\resources\\images\\game_background.png", thatWindow.getSize().x, thatWindow.getSize().y);
    int start_direction = 1;

    game_background.set_game_background_image();
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
            informations.show_points_after_collision(score_board.get_points());
            player.set_snake_speed(0.f);
            if (event.key.code == sf::Keyboard::Enter)
            {
                food.set_food_position();
                player.set_start_position();
                informations.clear_collision_information();
                informations.clear_final_points_information();
                score_board.reset_points();
                start_direction = 1;
            }
            else if (event.key.code == sf::Keyboard::Escape)
            {
                Game_Menu gameMenu(thatWindow.getSize().x, thatWindow.getSize().y);
                thatWindow.close();
                gameMenu.show_menu();
            }
        }

        if (collision.if_snake_eat_food(food.get_food_global_bounds(), player.get_snake_global_bounds()))
        {
            informations.show_getting_points_information(food.get_food_position());
            food.set_food_position();
            player.resize_snake();
            score_board.add_score();
        }

        if (collision.if_food_generate_on_snake(player.get_snakes_table(), food.get_food_global_bounds()))
        {
            food.set_food_position();
        }

        score_board.create_score_board(thatWindow.getSize().x, thatWindow.getSize().y);
        thatWindow.clear();
        game_background.draw_game_background_image(thatWindow);
        player.draw_snake(thatWindow, start_direction);
        food.draw_food(thatWindow);
        informations.draw_collision_information(thatWindow);
        informations.draw_getting_points_information(thatWindow);
        score_board.draw_score_board(thatWindow);
        thatWindow.display();
    }
}





