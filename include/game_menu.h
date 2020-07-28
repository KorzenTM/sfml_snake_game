#ifndef SNAKE_GAME_MENU_H
#define SNAKE_GAME_MENU_H

#include <SFML/Graphics.hpp>
#include "informations.h"

class Game_Menu
{
private:
    sf::Texture background_texture;
    sf::Sprite background;
    sf::Texture snake_texture;
    sf::Sprite snake_sprite;
    sf::RenderWindow menu_window;
    const int m_width;
    const int m_height;
    sf::RectangleShape m_quit_button;
    sf::RectangleShape m_start_button;
public:
    Game_Menu(int WIDTH, int HEIGHT);
    void create_quit_button();
    void quit_button_hover();
    void quit_button_clicked();
    void start_button_hover();
    void create_start_button();
    void start_button_clicked();
    void show_logo();
    void set_background_image();
    void show_menu();
    ~Game_Menu() {};
};
#endif //SNAKE_GAME_MENU_H
