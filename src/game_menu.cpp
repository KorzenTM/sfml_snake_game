#include "game_menu.h"
#include "informations.h"
#include "game.h"
#include <iostream>

Game_Menu::Game_Menu(int WIDTH, int HEIGHT): m_width(WIDTH), m_height(HEIGHT)
{
    menu_window.create(sf::VideoMode(m_width, m_height), "SNAKE", sf::Style::Titlebar | sf::Style::Close);
    menu_window.setFramerateLimit(60);
}

void Game_Menu::show_menu()
{
    Informations informations("..\\fonts\\COMICATE.TTF", m_width, m_height);
    create_quit_button();
    create_start_button();
    while (menu_window.isOpen())
    {
        informations.show_title();
        sf::Event event;
        while (menu_window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    menu_window.close();
                    break;
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f mouse = menu_window.mapPixelToCoords(sf::Mouse::getPosition(menu_window));
            sf::FloatRect quit_button_bounds = m_quit_button.getGlobalBounds();
            sf::FloatRect start_button_bounds = m_start_button.getGlobalBounds();
            if (quit_button_bounds.contains(mouse))
            {
                menu_window.close();
            }
            else if (start_button_bounds.contains(mouse))
            {
                Game_Board gameBoard;
                gameBoard.show_game_board(menu_window);
            }
        }
        menu_window.clear();
        informations.draw_informations(menu_window);
        menu_window.draw(m_quit_button);
        menu_window.draw(m_start_button);
        menu_window.display();
    }

}

void Game_Menu::create_quit_button()
{
    m_quit_button.setSize(sf::Vector2f(150.f, 50.f));
    m_quit_button.setFillColor(sf::Color(178, 34, 34));
    m_quit_button.setPosition(m_width - 170.f, m_height - 70.f);
}

void Game_Menu::create_start_button()
{
    m_start_button.setSize(sf::Vector2f(160.f, 80.f));
    m_start_button.setFillColor(sf::Color(60, 179, 113));
    m_start_button.setPosition(m_width / 2.5, m_height / 2.5);

}

