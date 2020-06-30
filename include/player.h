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
    void move(int direction = 1);
    void snake_control(sf::Event &event, sf::RenderWindow &thatWindow);
    void set_start_position();
    void set_position(double head_x_position, double head_y_position);
    void boundaries_cross(double window_width, double window_height);
    void draw_snake(sf::RenderWindow &thatWindow);
    ~Player() {};

private:
    int m_snake_length;
    double m_x_start_position, m_y_start_position;
    const int x_snake_size = 20;
    const int y_snake_size = 20;
    sf::RectangleShape Part_of_Snake;
    std::vector<sf::RectangleShape> Snakes;
};
#endif //SFMLTEST_PLAYER_H
