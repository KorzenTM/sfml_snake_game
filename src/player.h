#pragma once
#include <SFML/Graphics.hpp>


class Player
{
    public:
    Player();
    void draw_player(sf::RenderWindow &thatWindow);
    sf::RectangleShape snake;
};