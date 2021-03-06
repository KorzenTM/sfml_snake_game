#include "collision.h"
#include <iostream>

Collision::Collision() {}

void Collision::if_snake_out_of_window(sf::RenderWindow &thatWindow, std::vector<sf::RectangleShape> &Snakes)
{
    p_snake_size = Snakes[0].getSize().x;
    p_snake_head_position.x = Snakes[0].getPosition().x;
    p_snake_head_position.y = Snakes[0].getPosition().y;

    if(p_snake_head_position.x + p_snake_size > thatWindow.getSize().x)
    {
        Snakes[0].setPosition(0.0, p_snake_head_position.y);
    }
    if(p_snake_head_position.x < 0.0)
    {
        Snakes[0].setPosition(thatWindow.getSize().x - p_snake_size, p_snake_head_position.y);
    }
    if(p_snake_head_position.y + p_snake_size > thatWindow.getSize().y)
    {
        Snakes[0].setPosition(p_snake_head_position.x, 0.0);
    }
    if(p_snake_head_position.y < 0.0 )
    {
        Snakes[0].setPosition(p_snake_head_position.x, thatWindow.getSize().y - p_snake_size);
    }
}

bool Collision::if_snakes_with_body_collision(std::vector<sf::RectangleShape> &Snakes)
{
    for (size_t i = 1; i < Snakes.size(); i++)
    {
        if (Snakes[0].getGlobalBounds().intersects(Snakes[i].getGlobalBounds()))
        {
            return true;
        }
    }
    return false;
}

bool Collision::if_snake_eat_food(sf::FloatRect food_bounds, sf::FloatRect snake_bounds)
{
    if (snake_bounds.intersects(food_bounds))
    {
        return true;
    }
    return false;
}

bool Collision::if_food_generate_on_snake(std::vector<sf::RectangleShape> &Snakes, sf::FloatRect food_bounds)
{
    for (size_t i = 1; i < Snakes.size(); i++)
    {
        if (Snakes[0].getGlobalBounds().intersects(food_bounds))
        {
            return true;
        }
    }
    return false;
}




