#include "textures.h"

Textures::Textures(std::string texture_localization): m_texture_localization(texture_localization)
{
    if (!m_texture.loadFromFile(m_texture_localization))
    {
        throw std::invalid_argument("No texture found");
    }
}

void Textures::set_food_texture(sf::CircleShape &food)
{
    food.setTexture(&m_texture);
}

void Textures::set_snake_texture(sf::RectangleShape &snake)
{
    snake.setTexture(&m_texture);
}
