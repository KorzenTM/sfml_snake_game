#ifndef SNAKE_IMAGES_H
#define SNAKE_IMAGES_H

#include <SFML/Graphics.hpp>
#include <string>

class Images
{
private:
    int m_width, m_height;
    std::string m_image_localization;
    sf::Texture m_texture;
    sf::Sprite m_menu_background;
    sf::Sprite m_snake_sprite;
    sf::Sprite m_game_background;
public:
    Images(std::string image_localization, int WIDTH, int HEIGHT);
    void show_logo();
    void set_menu_background_image();
    void set_game_background_image();
    inline void draw_menu_background_image(sf::RenderWindow &thatWindow) {thatWindow.draw(m_menu_background);};
    inline void draw_logo(sf::RenderWindow &thatWindow) {thatWindow.draw(m_snake_sprite);};
    inline void draw_game_background_image(sf::RenderWindow &thatWindow) {thatWindow.draw(m_game_background);};
};


#endif //SNAKE_IMAGES_H
