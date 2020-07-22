#ifndef SFMLTEST_FOOD_H
#define SFMLTEST_FOOD_H

#pragma once
#include <SFML/Graphics.hpp>
#include "game.h"

class Food
{
public:

    Food(int WIDTH, int HEIGHT, int radius);
    void set_food_position();
    void draw_food(sf::RenderWindow &thatWindow);
    sf::Vector2f get_random_position();
    sf::FloatRect get_food_global_bounds() {return food.getGlobalBounds();}
    ~Food() {};
protected:
    sf::CircleShape food;
    int m_width, m_height;
    int m_radius;
    double m_x_position, m_y_position;
    sf::Vector2f food_position;
    sf::Vector2f temp_position;

};

#endif //SFMLTEST_FOOD_H
