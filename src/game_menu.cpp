#include "game_menu.h"
#include "informations.h"

Game_Menu::Game_Menu(int WIDTH, int HEIGHT): m_width(WIDTH), m_height(HEIGHT)
{
    menu_window.create(sf::VideoMode(m_width, m_height), "SNAKE", sf::Style::Titlebar | sf::Style::Close);
    menu_window.setFramerateLimit(60);
}

void Game_Menu::show_menu()
{
    Informations informations("..\\fonts\\COMICATE.TTF");
    while (menu_window.isOpen())
    {
        informations.show_title(m_width, m_height);
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
        menu_window.clear();
        informations.draw_informations(menu_window);
        menu_window.display();
    }

}
