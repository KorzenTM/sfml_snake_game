#ifndef SFMLTEST_PLAYER_H
#define SFMLTEST_PLAYER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <cassert>

class Player
{
public:
    Player(int snake_length, double x_start_position, double y_start_position);
    void resize_snake();
    void move(int &direction);
    void set_direction(sf::Event &event, int &direction);
    void set_start_position();
    void set_snake_position(sf::Vector2f &last_head_position);
    void draw_snake(sf::RenderWindow &thatWindow);

    void set_snake_speed(double speed) {m_speed = speed;};
    std::vector<sf::RectangleShape> & get_snakes_table() {return Snakes;};
    std::vector<sf::RectangleShape>  get_snakes_table() const {return Snakes;};
    sf::FloatRect get_snake_global_bounds() {return Snakes[0].getGlobalBounds();};
    ~Player() {};

private:
    int m_snake_length;
    double m_x_start_position, m_y_start_position;
    const double snake_size = 20.0;
    double m_speed;
    sf::RectangleShape Part_of_Snake;
    std::vector<sf::RectangleShape> Snakes;
};
#endif //SFMLTEST_PLAYER_H
