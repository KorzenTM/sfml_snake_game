#pragma once
#include <SFML/Graphics.hpp>

class Food
{
    public:
    Food();
    void draw_food(sf::RenderWindow &thatWindow);
    sf::CircleShape food;
};