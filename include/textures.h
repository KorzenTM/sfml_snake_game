#ifndef SNAKE_TEXTURES_H
#define SNAKE_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <string>


class Textures
{
private:
    std::string m_texture_localization;
    sf::Texture m_texture;
    sf::Texture m_texture_2;
    void change_texture_localization(std::string new_texture_localization);
public:
    Textures(std::string texture_localization);
    void set_head_snake_texture(sf::RectangleShape &snake_head, int direction = 1);
    void set_snake_body_texture(sf::RectangleShape &snake_body);
    void set_food_texture(sf::CircleShape &food);
    ~Textures() {};
};

#endif //SNAKE_TEXTURES_H
