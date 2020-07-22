#include <SFML/Graphics.hpp>
#include <vector>

#ifndef SNAKE_COLLISION_H
#define SNAKE_COLLISION_H

class Collision
{
private:
    double p_snake_size;
    sf::Vector2f p_snake_head_position;
public:
    Collision();
    void if_snake_out_of_window(sf::RenderWindow &thatWindow, std::vector<sf::RectangleShape> &Snakes);
    bool if_snakes_with_body_collision(const std::vector<sf::RectangleShape> &Snakes);
    ~Collision() {};
};

#endif //SNAKE_COLLISION_H
