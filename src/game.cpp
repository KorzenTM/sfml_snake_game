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
    Game_Engine game_engine;
    sf::Event event;
    while(window.isOpen())
    {
        game_engine.processEvents(event,window);
        render();
    }
}

void Game::render()
{
    Player player; 
    window.clear();
    player.draw_player(window);
    window.display();
}