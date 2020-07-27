#ifndef SNAKE_GAME_MENU_H
#define SNAKE_GAME_MENU_H

#include <SFML/Graphics.hpp>

class Game_Menu
{
private:
    sf::RenderWindow menu_window;
    const int m_width;
    const int m_height;
public:
    Game_Menu(int WIDTH, int HEIGHT);
    void show_menu();
    ~Game_Menu() {};
};
#endif //SNAKE_GAME_MENU_H
