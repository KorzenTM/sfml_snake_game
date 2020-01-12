#include "player.h"


Player::Player():snake(sf::Vector2f(20.f, 20.f))
{
   snake.setFillColor(sf::Color(100,250,50));
}

void Player::draw_player(sf::RenderWindow &thatWindow)
{    
   thatWindow.draw(snake);
}