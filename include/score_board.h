#include <SFML/Graphics.hpp>
#include <string>

#ifndef SNAKE_SCORE_BOARD_H
#define SNAKE_SCORE_BOARD_H

class Score_Board
{
private:
    sf::Font font;
    sf::Text m_score_board;
    int m_points;
    std::string m_font_localization;
public:
    Score_Board(std::string font_localization, int start_points);
    void create_score_board(int width, int height);
    void reset_points();
    void draw_score_board(sf::RenderWindow &thatWindow);
    ~Score_Board() {};

    void add_score();
};

#endif //SNAKE_SCORE_BOARD_H
