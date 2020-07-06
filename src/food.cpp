#include "food.h"
#include <iostream>
Food::Food(int WIDTH, int HEIGHT, int radius): m_width(WIDTH), m_height(HEIGHT), m_radius(radius)
{
    food.setRadius(radius);
    food.setFillColor(sf::Color(132, 0, 0));
}

void Food::draw(sf::RenderWindow &thatWindow)
{
    thatWindow.draw(food);
}

void Food::set_position()
{
    temp_position = get_random_position();
    std::cout << temp_position.x << " " << temp_position.y << "\n";
    food.setPosition(temp_position.x, temp_position.y);
}

sf::Vector2f Food::get_random_position()
{
    m_x_position = (std::rand() % (m_width / (m_radius * 2)) + 0) * (m_radius * 2);
    m_y_position = (std::rand() % (m_height / (m_radius * 2)) + 0) * (m_radius * 2);
    food_position.x = m_x_position;
    food_position.y = m_y_position;
    return food_position;
}

