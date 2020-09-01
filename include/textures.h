#ifndef SNAKE_TEXTURES_H
#define SNAKE_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <string>

class Textures
{
private:
    std::string m_texture_localization;
    sf::Texture m_texture;
    sf::Sprite m_menu_background;
    sf::Sprite m_snake_sprite;
    sf::Sprite m_game_background;
public:
    Textures(std::string texture_localization);
    void set_snake_texture(sf::RectangleShape &snake);
    void set_food_texture(sf::CircleShape &food);
    ~Textures() {};
};

#endif //SNAKE_TEXTURES_H
