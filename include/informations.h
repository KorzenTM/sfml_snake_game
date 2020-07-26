#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#ifndef SNAKE_INFORMATIONS_H
#define SNAKE_INFORMATIONS_H

class Informations
{
private:
    std::string m_font_localization;
    sf::Font font;
    sf::Text m_collision_text;
    sf::Text m_key_press_information;
    sf::Text m_getting_points_information;
public:
    Informations(std::string font_localization);
    void collision_information();
    void getting_points_information(sf::Vector2f food_position);
    void clear_text();
    void draw_informations(sf::RenderWindow &thatWindow);
    ~Informations() {};
};

#endif //SNAKE_INFORMATIONS_H
