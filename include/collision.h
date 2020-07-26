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
    bool if_food_generate_on_snake(std::vector<sf::RectangleShape> &Snakes, sf::FloatRect food_bounds);
    void if_snake_out_of_window(sf::RenderWindow &thatWindow, std::vector<sf::RectangleShape> &Snakes);
    bool if_snakes_with_body_collision(std::vector<sf::RectangleShape> &Snakes);
    bool if_snake_eat_food(sf::FloatRect food_bounds, sf::FloatRect snake_bounds);
    ~Collision() {};
};

#endif //SNAKE_COLLISION_H
