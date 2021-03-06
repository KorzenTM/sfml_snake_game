#include "player.h"
#include <iostream>

enum direction{left, right, up, down};

Player::Player(int snake_length, double x_start_position, double y_start_position):
Textures("..\\resources\\images\\snake_body.png"), m_snake_length(snake_length),
        m_x_start_position(x_start_position), m_y_start_position(y_start_position)
{
    if (m_snake_length == 0)
    {
        throw std::invalid_argument("Snake length can not be 0!");
    }
    Part_of_Snake.setSize(sf::Vector2f(m_snake_size, m_snake_size));
    Snakes.resize(m_snake_length);
    for(auto & Snake : Snakes)
    {
        Snake = Part_of_Snake;
    }
}

void Player::set_start_position()
{
    set_snake_speed(m_snake_size);
    Snakes[0].setPosition(m_x_start_position, m_y_start_position);
    for(size_t i = 1; i < Snakes.size(); i++)
    {
        Snakes[i].setPosition(Snakes[i-1].getPosition().x - m_snake_size, Snakes[i - 1].getPosition().y);
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

void Player::move(int &direction)
{
    sf::Vector2f lastPosition (Snakes[0].getPosition().x, Snakes[0].getPosition().y);
    switch(direction)
    {
        case left:
            Snakes[0].move(-m_speed  , 0.f);
            break;
        case right:
            Snakes[0].move(m_speed , 0.f);
            break;
        case up:
            Snakes[0].move(0.f,-m_speed );
            break;
        case down:
            Snakes[0].move(0.f, m_speed );
            break;
        default:
            break;
    }
    set_snake_position(lastPosition);
}

void Player::set_snake_position(sf::Vector2f &last_head_position)
{
    if (m_speed > 0)
    {
        sf::Vector2f newPosition (last_head_position);
        for(int i = 1; i < Snakes.size(); i++)
        {
            last_head_position = Snakes[i].getPosition();
            Snakes[i].setPosition(newPosition.x , newPosition.y);
            newPosition = last_head_position;
        }
    }
}

void Player::resize_snake()
{
    sf::Vector2f temp_last_part_position (Snakes.back().getPosition());
    Snakes.push_back(Part_of_Snake);
    Snakes.back().setPosition(temp_last_part_position);
}

void Player::draw_snake(sf::RenderWindow &thatWindow, int &direction)
{

    for(size_t i = 0; i < Snakes.size(); i++)
    {
        if (i == 0)
        {
            set_head_snake_texture(Snakes[i], direction);
        }
        else
        {
            set_snake_body_texture(Snakes[i]);
        }
        thatWindow.draw(Snakes[i]);
    }
}














