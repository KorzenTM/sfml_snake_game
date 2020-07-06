#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "game.cpp"
#include <ctime>

int main()
{
    std::srand(time(NULL));
    const int WIDTH = 800;
    const int HEIGHT = 600;
    Game_Window game(WIDTH, HEIGHT);
    game.Show_Window();
}