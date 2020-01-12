#include "game.h"
#include "game_engine.h"
#include "game_engine.cpp"
#include "player.h"
#include "player.cpp"

Game::Game():window(sf::VideoMode(WIDTH,HEIGHT),"SNAKE")
{
    window.setFramerateLimit(60);
    
}

void Game::run()
{
    Player player;
    Game_Engine game_engine;
    sf::Event event;
    while(window.isOpen())
    {
        game_engine.processEvents(event,window,player.snake);
        render(player.snake);
    }
}

void Game::render(sf::RectangleShape &snake)
{ 
    window.clear();
    window.draw(snake);
    window.display();
}