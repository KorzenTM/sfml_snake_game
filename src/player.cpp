#include "player.h"


Player::Player():snake_1(sf::Vector2f(20.f, 20.f)),snake_2(sf::Vector2f(20.f, 20.f)),snake_3(sf::Vector2f(20.f, 20.f))
{
   snake_1.setFillColor(sf::Color(100,100,100));
   snake_2.setFillColor(sf::Color(100,250,50));
   snake_3.setFillColor(sf::Color(100,250,50));
}

void Player::draw_player(sf::RenderWindow &thatWindow)
{    
   thatWindow.draw(snake_1);
   thatWindow.draw(snake_2);
   thatWindow.draw(snake_3);
}