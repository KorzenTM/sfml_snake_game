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
public:
    Informations(std::string font_localization);
    int collision_information();
    void clear_text();
    void draw_informations(sf::RenderWindow &thatWindow);
};

#endif //SNAKE_INFORMATIONS_H
