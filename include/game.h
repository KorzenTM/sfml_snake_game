#ifndef SFMLTEST_GAME_H
#define SFMLTEST_GAME_H

#include <SFML/Graphics.hpp>
#include <string>

class Game_Board
{
public:
    Game_Board();
    void show_game_board(sf::RenderWindow &thatWindow);
    ~Game_Board() {};
};
#endif //SFMLTEST_GAME_H
