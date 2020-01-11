#pragma once
#include <SFML/Graphics.hpp>

#define WIDTH 800
#define HEIGHT 600

class Game
{
    public:
    Game();
    void run();

    private:
    void update();
    void render();

    sf::RenderWindow window;
};
