#include "player.h"
enum direction{left, right, up, down};

Player::Player(int snake_length, double x_start_position, double y_start_position) :
                m_snake_length(snake_length), m_x_start_position(x_start_position), m_y_start_position(
                y_start_position)
{
    assert(snake_length > 0);

    Part_of_Snake.setSize(sf::Vector2f(x_snake_size, y_snake_size));
    Part_of_Snake.setFillColor(sf::Color(100,100,100));
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
        Snakes[i].setPosition(Snakes[i-1].getPosition().x - x_snake_size, Snakes[i - 1].getPosition().y);
    }
}

void Player::draw_snake(sf::RenderWindow &thatWindow)
{
    for(auto & Snake : Snakes)
    {
        thatWindow.draw(Snake);
    }
}

void Player::move(int direction)
{
    double head_x_position = Snakes[0].getPosition().x;
    double head_y_position = Snakes[0].getPosition().y;
    switch(direction)
    {
        case 0:
            Snakes[0].move(-20,0);
            set_position(head_x_position, head_y_position);
            boundaries_cross(800,600);
            break;
        case 1:
            Snakes[0].move(20,0);
            set_position(head_x_position, head_y_position);
            boundaries_cross(800,600);
            break;
        case 2:
            Snakes[0].move(20,0);
            set_position(head_x_position, head_y_position);
            boundaries_cross(800,600);
            break;
        case 3:
            Snakes[0].move(20,0);
            set_position(head_x_position, head_y_position);
            boundaries_cross(800,600);
            break;
    }
}

void Player::snake_control(sf::Event &event, sf::RenderWindow &thatWindow)
{
    double head_x_position = Snakes[0].getPosition().x;
    double head_y_position = Snakes[0].getPosition().y;
    if(event.key.code==sf::Keyboard::W)
    {
        move(up);
        Snakes[0].move(0,-20);
        set_position(head_x_position, head_y_position);
    }
    if(event.key.code==sf::Keyboard::S)
    {
        move(down);
        Snakes[0].move(0,20);
        set_position(head_x_position, head_y_position);
    }
    if(event.key.code==sf::Keyboard::D)
    {
        move(right);
        Snakes[0].move(20,0);
        set_position(head_x_position, head_y_position);
    }
    if(event.key.code==sf::Keyboard::A)
    {
        move(left);
        Snakes[0].move(-20,0);
        set_position(head_x_position, head_y_position);
    }
    double window_width = thatWindow.getSize().x;
    double window_height = thatWindow.getSize().y;
    boundaries_cross(window_width, window_height);
}

void Player::set_position(double head_x_position, double head_y_position)
{
    double next_x_position, next_y_position;
    for(int i = 1; i < Snakes.size(); i++)
    {
        next_x_position = Snakes[i].getPosition().x;
        next_y_position = Snakes[i].getPosition().y;
        Snakes[i].setPosition(head_x_position, head_y_position);
        head_x_position = next_x_position;
        head_y_position = next_y_position;
    }
}

void Player::boundaries_cross(double window_width, double window_height)
{
    double head_x_position = Snakes[0].getPosition().x;
    double head_y_position = Snakes[0].getPosition().y;
    if(head_x_position + x_snake_size > window_width)
    {
        Snakes[0].setPosition(0.0, head_y_position);
    }
    if(head_x_position < 0.0)
    {
        Snakes[0].setPosition(window_width - x_snake_size, head_y_position);
    }
    if(head_y_position + y_snake_size > window_height)
    {
        Snakes[0].setPosition(head_x_position, 0.0);
    }
    if(head_y_position < 0.0 )
    {
        Snakes[0].setPosition(head_x_position, window_height - y_snake_size);

    }
}








