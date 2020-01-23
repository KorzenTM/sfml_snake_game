#pragma once
#include <SFML/Graphics.hpp>

class Game_Engine
{
    public:
    void processEvents(sf::Event event,sf::RenderWindow &thatWindow,sf::RectangleShape &snake_1,sf::RectangleShape &snake_2,sf::RectangleShape &snake_3,sf::CircleShape &food);
    void move(sf::Event event,sf::RectangleShape &snake_1,sf::RectangleShape &snake_2,sf::RectangleShape &snake_3);
    void colission(sf::Event event,sf::RenderWindow &thatWindow,sf::RectangleShape &snake_1,sf::RectangleShape &snake_2,sf::RectangleShape &snake_3,sf::CircleShape &food);

    private:
    void render(sf::RenderWindow &thatWindow,sf::RectangleShape &snake_1,sf::RectangleShape &snake_2,sf::RectangleShape &snake_3,sf::CircleShape &food);


};