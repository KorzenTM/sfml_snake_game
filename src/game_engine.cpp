#include "game_engine.h"

void Game_Engine::processEvents(sf::Event event,sf::RenderWindow &thatWindow)
{
    while(thatWindow.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
            thatWindow.close();
            break;
            case sf::Event::KeyPressed:
            if(event.key.code==sf::Keyboard::Escape)
            {
                thatWindow.close();
            }
            
            break;
        }
    }
}