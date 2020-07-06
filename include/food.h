#ifndef SFMLTEST_FOOD_H
#define SFMLTEST_FOOD_H

#pragma once
#include <SFML/Graphics.hpp>

class Food
{
public:

    Food(int WIDTH, int HEIGHT, int radius);
    void set_position();
    void draw(sf::RenderWindow &thatWindow);
    sf::Vector2f get_random_position();
    ~Food() {};
private:
    sf::CircleShape food;
    int m_width, m_height;
    int m_radius;
    double m_x_position, m_y_position;
    sf::Vector2f food_position;
    sf::Vector2f temp_position;

};

#endif //SFMLTEST_FOOD_H
