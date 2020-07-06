#include "player.h"
#include <iostream>
enum direction{left, right, up, down};

Player::Player(int snake_length, double x_start_position, double y_start_position) :
                m_snake_length(snake_length), m_x_start_position(x_start_position), m_y_start_position(
                y_start_position)
{
    assert(snake_length > 0);

    Part_of_Snake.setSize(sf::Vector2f(snake_size, snake_size));
    Part_of_Snake.setFillColor(sf::Color(1, 145, 0));
    Snakes.resize(m_snake_length);
    for(auto & Snake : Snakes)
    {
        Snake = Part_of_Snake;
    }
}

void Player::set_start_position()
{
    Snakes[0].setPosition(m_x_start_position, m_y_start_position);
    for(size_t i = 1; i < Snakes.size(); i++)
    {
        Snakes[i].setPosition(Snakes[i-1].getPosition().x - snake_size, Snakes[i - 1].getPosition().y);
    }
}

void Player::draw(sf::RenderWindow &thatWindow)
{
    for(auto & Snake : Snakes)
    {
        thatWindow.draw(Snake);
    }
}

void Player::move(int &direction)
{
    sf::Vector2f lastPosition (Snakes[0].getPosition().x, Snakes[0].getPosition().y);
    switch(direction)
    {
        case left:
            Snakes[0].move(-speed  ,0.f);
            break;
        case right:
            Snakes[0].move(speed ,0.f);
            break;
        case up:
            Snakes[0].move(0.f,-speed );
            break;
        case down:
            Snakes[0].move(0.f,speed );
            break;
        default:
            break;
    }
    set_position(lastPosition);
    boundaries_cross(800,600);
}

void Player::set_position(sf::Vector2f &last_head_position)
{
    sf::Vector2f newPosition (last_head_position);
    for(int i = 1; i < Snakes.size(); i++)
    {
        last_head_position = Snakes[i].getPosition();
        Snakes[i].setPosition(newPosition.x , newPosition.y);
        newPosition = last_head_position;
    }

}

void Player::set_direction(sf::Event &event, int &direction)
{
    if(event.key.code == sf::Keyboard::W)
    {
        if (direction == down)
        {
            return;
        }
        direction = up;
    }
    if(event.key.code == sf::Keyboard::S)
    {
        if (direction == up)
        {
            return;
        }
        direction = down;
    }
    if(event.key.code == sf::Keyboard::D)
    {
        if (direction == left)
        {
            return;
        }
        direction = right;
    }
    if(event.key.code == sf::Keyboard::A)
    {
        if (direction == right)
        {
            return;
        }
        direction = left;
    }
}

void Player::boundaries_cross(double window_width, double window_height)
{
    double head_x_position = Snakes[0].getPosition().x;
    double head_y_position = Snakes[0].getPosition().y;
    if(head_x_position + snake_size > window_width)
    {
        Snakes[0].setPosition(0.0, head_y_position);
    }
    if(head_x_position < 0.0)
    {
        Snakes[0].setPosition(window_width - snake_size, head_y_position);
    }
    if(head_y_position + snake_size > window_height)
    {
        Snakes[0].setPosition(head_x_position, 0.0);
    }
    if(head_y_position < 0.0 )
    {
        Snakes[0].setPosition(head_x_position, window_height - snake_size);

    }
}








