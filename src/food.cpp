#include "food.h"

Food::Food():food(10.f)
{
    food.setFillColor(sf::Color(150, 50, 250));
}

void Food::draw_food(sf::RenderWindow &thatWindow)
{
    thatWindow.draw(food);
}