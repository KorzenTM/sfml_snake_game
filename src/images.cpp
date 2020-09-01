
#include <images.h>

Images::Images(std::string image_localization, int WIDTH, int HEIGHT): m_image_localization(image_localization),
                                                                        m_width(WIDTH), m_height(HEIGHT)
{
    if (!m_texture.loadFromFile(m_image_localization))
    {
        throw std::invalid_argument("No image found");
    }
}

void Images::show_logo()
{
    m_snake_sprite.setTexture(m_texture);
    m_snake_sprite.setScale(0.5, 0.5);
    m_snake_sprite.setPosition((m_width / 2.f) - (m_snake_sprite.getLocalBounds().width / 1.8f),
                               (m_height) - (m_snake_sprite.getLocalBounds().height / 1.8f));
}

void Images::set_menu_background_image()
{
    m_texture.setRepeated(true);
    m_menu_background.setTexture(m_texture);
    m_menu_background.setTextureRect(sf::IntRect (0, 0, m_width, m_height));
}

void Images::set_game_background_image()
{
    m_texture.setRepeated(true);
    m_game_background.setTexture(m_texture);
    m_game_background.setTextureRect(sf::IntRect (0, 0, m_width, m_height));
}

