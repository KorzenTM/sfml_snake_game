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

void Textures::change_texture_localization(std::string new_texture_localization)
{
    m_texture_localization = std::move(new_texture_localization);
    if (!m_texture_2.loadFromFile(m_texture_localization))
    {
        throw std::invalid_argument("No texture found");
    }
}

void Textures::set_head_snake_texture(sf::RectangleShape &snake_head, int direction)
{
    switch (direction)
    {
        case 0: //left
            change_texture_localization(R"(..\resources\images\snake_head_left.png)");
            snake_head.setTexture(&m_texture_2);
            break;
        case 1: //right
            change_texture_localization(R"(..\resources\images\snake_head_right.png)");
            snake_head.setTexture(&m_texture_2);
            break;
        case 2: //up
            change_texture_localization(R"(..\resources\images\snake_head_up.png)");
            snake_head.setTexture(&m_texture_2);
            break;
        case 3: //down
            change_texture_localization(R"(..\resources\images\snake_head_down.png)");
            snake_head.setTexture(&m_texture_2);
            break;
    }
}

void Textures::set_snake_body_texture(sf::RectangleShape &snake_body)
{
    snake_body.setTexture(&m_texture);
}

