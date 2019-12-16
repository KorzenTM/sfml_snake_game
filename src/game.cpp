#include "game.h"

Game::Game():window(sf::VideoMode(WIDTH,HEIGHT),"Name")
{
    window.setFramerateLimit(60);
    
}

void Game::run()
{
    while(window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
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
            
            break;
        }
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