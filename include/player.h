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
    std::vector<sf::RectangleShape> & get_snakes_table() {return Snakes;};
    std::vector<sf::RectangleShape>  get_snakes_table() const {return Snakes;};
    ~Player() {};

private:
    int m_snake_length;
    double m_x_start_position, m_y_start_position;
    const double snake_size = 20.0;
    double speed;
    sf::RectangleShape Part_of_Snake;
    std::vector<sf::RectangleShape> Snakes;
    sf::Text collision_text;
    sf::Text key_press_information;
    sf::Font font;
};
#endif //SFMLTEST_PLAYER_H
