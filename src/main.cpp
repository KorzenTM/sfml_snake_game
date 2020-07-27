#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_menu.h"
#include <ctime>

int main()
{
    std::srand(time(NULL));
    const int WIDTH = 800;
    const int HEIGHT = 600;
    Game_Menu game(WIDTH, HEIGHT);
    game.show_menu();
}