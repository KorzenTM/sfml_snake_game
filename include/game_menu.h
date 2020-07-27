#ifndef SNAKE_GAME_MENU_H
#define SNAKE_GAME_MENU_H

#include <SFML/Graphics.hpp>

class Game_Menu
{
private:
    sf::RenderWindow menu_window;
    const int m_width;
    const int m_height;
    sf::RectangleShape m_quit_button;
    sf::RectangleShape m_start_button;
public:
    Game_Menu(int WIDTH, int HEIGHT);
    void create_quit_button();
    void create_start_button();
    void show_menu();
    ~Game_Menu() {};
};
#endif //SNAKE_GAME_MENU_H
