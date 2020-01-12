#include "player.h"


void Player::draw_player(sf::RenderWindow &thatWindow)
{
   sf::CircleShape shape(50.f);
   shape.setFillColor(sf::Color(100,250,50)); 
   thatWindow.draw(shape);
}