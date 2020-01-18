#include "game.h"
#include "game_engine.h"
#include "game_engine.cpp"
#include "player.h"
#include "player.cpp"
#include "food.h"
#include "food.cpp"
#include <ctime>

Game::Game():window(sf::VideoMode(WIDTH,HEIGHT),"SNAKE")
{
    window.setFramerateLimit(60);
    
}

void Game::run()
{
    srand(time(NULL));
    Player player;
    Food food;
    Game_Engine game_engine;
    sf::Event event;
    player.snake_1.setPosition(WIDTH/2,HEIGHT/2);
    player.snake_2.setPosition((WIDTH/2)-20,HEIGHT/2);
    player.snake_3.setPosition((WIDTH/2)-40,HEIGHT/2);
    food.food.setPosition((std::rand()%(WIDTH/20)+0)*20,(std::rand()%(HEIGHT/20)+0)*20);
    while(window.isOpen())
    {
        game_engine.processEvents(event,window,player.snake_1,player.snake_2,player.snake_3,food.food);
        render(player.snake_1,player.snake_2,player.snake_3,food.food);
    }
}

void Game::render(sf::RectangleShape &snake_1,sf::RectangleShape &snake_2,sf::RectangleShape &snake_3,sf::CircleShape &food)
{ 
    window.clear();
    window.draw(snake_1);
    window.draw(snake_2);
    window.draw(snake_3);
    window.draw(food);
    window.display();
}