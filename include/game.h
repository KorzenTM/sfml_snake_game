#ifndef SFMLTEST_GAME_H
#define SFMLTEST_GAME_H

#include <SFML/Graphics.hpp>
#include <string>

class Game_Board
{
private:
    sf::RenderWindow window;
    const int m_width;
    const int m_height;
public:
    Game_Board(int WIDTH, int HEIGHT);
    void show_game_board();
    ~Game_Board() {};
};
#endif //SFMLTEST_GAME_H
