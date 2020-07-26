#include "informations.h"

Informations::Informations(std::string font_localization):m_font_localization(font_localization)
{
    if (!font.loadFromFile(m_font_localization))
    {
        throw std::invalid_argument("No font file in the specified location");
    }
}

void Informations::collision_information()
{
    m_collision_text.setFont(font);
    m_collision_text.setString("Impact detected.\n     Try again!");
    m_collision_text.setCharacterSize(24);
    m_collision_text.setFillColor(sf::Color::Red);
    m_collision_text.setStyle(sf::Text::Bold);
    m_collision_text.setPosition(300,50);

    m_key_press_information.setFont(font);
    m_key_press_information.setString("Press enter to continue.\nEscape to exit the game.");
    m_key_press_information.setCharacterSize(24);
    m_key_press_information.setFillColor(sf::Color::Red);
    m_key_press_information.setStyle(sf::Text::Bold);
    m_key_press_information.setPosition(260,450);
}

void Informations::clear_text()
{
    m_collision_text.setString("");
    m_key_press_information.setString("");
    m_getting_points_information.setString("");
}

void Informations::getting_points_information(sf::Vector2f food_position)
{
    m_getting_points_information.setFont(font);
    m_getting_points_information.setString("10 points for you!");
    m_getting_points_information.setCharacterSize(14);
    m_getting_points_information.setFillColor(sf::Color::Red);
    m_getting_points_information.setStyle(sf::Text::Bold);
    m_getting_points_information.setPosition(food_position.x - 50.f, (food_position.y + 30.f));

}

void Informations::draw_informations(sf::RenderWindow &thatWindow)
{
    thatWindow.draw(m_collision_text);
    thatWindow.draw(m_key_press_information);
    thatWindow.draw(m_getting_points_information);
}

