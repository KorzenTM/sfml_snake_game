#include "game.h"
#include "player.h"
#include "player.cpp"
#include "food.h"
#include "food.cpp"
#include <iostream>

Game_Window::Game_Window(int WIDTH, int HEIGHT):m_width(WIDTH), m_height(HEIGHT) {
    window.create(sf::VideoMode(m_width, m_height), "SNAKE", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
}

void Game_Window::Show_Window()
{
    //srand(time(NULL));
    //food.food.setPosition((std::rand()%(WIDTH/20)+0)*20,(std::rand()%(HEIGHT/20)+0)*20);
    Player player(10, 400, 300);
    player.set_start_position();
    int start_direction = 1;
    sf::Clock clock;
    while(window.isOpen())
    {
        sf::Event event;
        float time = clock.getElapsedTime().asSeconds() ;
        if (time >= 1.0) {
            player.move(start_direction);
            clock.restart();
        }

        //float delta = clock.restart().asSeconds();

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    } else {
                        //delta = clock.restart().asSeconds();
                        player.set_direction(event, start_direction);
                    }
            }
        }

        window.clear(sf::Color(255,255,255));
        player.draw(window);
        window.display();
    }
}




