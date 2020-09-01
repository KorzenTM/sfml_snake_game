#include "food.h"
#include <iostream>

Food::Food(std::string textureLocalization, int WIDTH, int HEIGHT, int radius) :
        Textures("..\\resources\\images\\apple.png"), m_width(WIDTH), m_height(HEIGHT),
        m_radius(radius)
{
    food.setRadius(m_radius);
}

void Food::set_food_position()
{
    temp_position = get_random_position();
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

void Food::draw_food(sf::RenderWindow &thatWindow)
{
    set_food_texture(food);
    thatWindow.draw(food);
}

