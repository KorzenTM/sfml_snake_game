#include "game.h"
#include "game_engine.h"
#include "game_engine.cpp"

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
        update();
        render();
    }
}


void Game::update()
{

}
void Game::render()
{
    window.clear();
    window.display();
}