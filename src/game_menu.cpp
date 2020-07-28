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
    Informations title("..\\fonts\\Gameplay.ttf", m_width, m_height);
    Informations buttons_text("..\\fonts\\arial.ttf", m_width, m_height);

    create_quit_button();
    buttons_text.set_quit_button_text(m_quit_button.getGlobalBounds());

    create_start_button();
    buttons_text.set_start_button_text(m_start_button.getGlobalBounds());

    title.show_title();
    set_background_image();
    show_logo();

    while (menu_window.isOpen())
    {
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
        quit_button_hover();
        start_button_hover();
        menu_window.clear();
        menu_window.draw(background);
        menu_window.draw(snake_sprite);
        menu_window.draw(m_quit_button);
        menu_window.draw(m_start_button);
        title.draw_informations(menu_window);
        buttons_text.draw_informations(menu_window);
        menu_window.display();
    }

}

void Game_Menu::set_background_image()
{
    if (!background_texture.loadFromFile("..\\resources\\images\\background.jpg"))
    {
        throw std::invalid_argument("No file found");
    }
    else
    {
        background_texture.setRepeated(true);
        background.setTexture(background_texture);
        background.setTextureRect(sf::IntRect (0,0, m_width, m_height));
    }
}

void Game_Menu::show_logo()
{
    if (!snake_texture.loadFromFile("..\\resources\\images\\snake.png"))
    {
        throw std::invalid_argument("No file found");
    }
    else
    {
        snake_sprite.setTexture(snake_texture);
        snake_sprite.setScale(0.5, 0.5);
        snake_sprite.setPosition(50, 300);
    }

}

void Game_Menu::create_quit_button()
{
    m_quit_button.setSize(sf::Vector2f(150.f, 50.f));
    m_quit_button.setPosition(m_width - 170.f, m_height - 70.f);
}

void Game_Menu::create_start_button()
{
    m_start_button.setSize(sf::Vector2f(160.f, 80.f));
    m_start_button.setPosition(m_width / 2.5, m_height / 2.5);

}

void Game_Menu::quit_button_hover()
{
    if (m_quit_button.getGlobalBounds().contains(menu_window.mapPixelToCoords(sf::Mouse::getPosition(menu_window))))
    {
        m_quit_button.setFillColor(sf::Color(128,0,0));
        m_quit_button.setOutlineThickness(2);
        m_quit_button.setOutlineColor(sf::Color::White);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            quit_button_clicked();
        }
    }
    else
    {
        m_quit_button.setOutlineThickness(0);
        m_quit_button.setFillColor(sf::Color(178, 34, 34));
    }
}

void Game_Menu::quit_button_clicked()
{
    sf::Vector2f mouse = menu_window.mapPixelToCoords(sf::Mouse::getPosition(menu_window));
    sf::FloatRect quit_button_bounds = m_quit_button.getGlobalBounds();
    if (quit_button_bounds.contains(mouse))
    {
        menu_window.close();
    }
}

void Game_Menu::start_button_hover()
{
    if (m_start_button.getGlobalBounds().contains(menu_window.mapPixelToCoords(sf::Mouse::getPosition(menu_window))))
    {
        m_start_button.setFillColor(sf::Color(0, 100, 0));
        m_start_button.setOutlineThickness(2);
        m_start_button.setOutlineColor(sf::Color::White);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            start_button_clicked();
        }
    }
    else
    {
        m_start_button.setFillColor(sf::Color(34, 139, 34));
        m_start_button.setOutlineThickness(0);
    }
}

void Game_Menu::start_button_clicked()
{
    sf::Vector2f mouse = menu_window.mapPixelToCoords(sf::Mouse::getPosition(menu_window));
    sf::FloatRect start_button_bounds = m_start_button.getGlobalBounds();
    if (start_button_bounds.contains(mouse))
    {
        Game_Board gameBoard;
        gameBoard.show_game_board(menu_window);
    }
}




