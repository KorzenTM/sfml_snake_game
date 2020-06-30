#ifndef SFMLTEST_GAME_H
#define SFMLTEST_GAME_H

#include <SFML/Graphics.hpp>

class Game_Window
{
public:
    Game_Window(int WIDTH, int HEIGHT);

    Game_Window();

    void Show_Window();
    ~Game_Window() {};

private:
    sf::RenderWindow window;
    const int m_width;
    const int m_height;
};
#endif //SFMLTEST_GAME_H
