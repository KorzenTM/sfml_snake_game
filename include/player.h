#ifndef SFMLTEST_PLAYER_H
#define SFMLTEST_PLAYER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <cassert>

class Player
{
public:
    Player(int snake_length, double x_start_position, double y_start_position);
    void Resize_Snake();
    void move(int &direction);
    void set_direction(sf::Event &event, int &direction);
    void set_start_position();
    void set_position(sf::Vector2f &last_head_position, int direction);
    void boundaries_cross(double window_width, double window_height);
    void draw(sf::RenderWindow &thatWindow);
    ~Player() {};

private:
    int m_snake_length;
    double m_x_start_position, m_y_start_position;
    const double snake_size = 20.0;
    const double speed = 20.0;
    sf::RectangleShape Part_of_Snake;
    std::vector<sf::RectangleShape> Snakes;
};
#endif //SFMLTEST_PLAYER_H
