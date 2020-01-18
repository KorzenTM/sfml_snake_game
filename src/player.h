#pragma once
#include <SFML/Graphics.hpp>


class Player
{
    public:
    Player();
    void draw_player(sf::RenderWindow &thatWindow);
    sf::RectangleShape snake_1;
    sf::RectangleShape snake_2;
    sf::RectangleShape snake_3;
};