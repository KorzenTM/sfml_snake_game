#include "score_board.h"

Score_Board::Score_Board(std::string font_localization, int start_points) :
m_font_localization(font_localization), m_points(start_points)
{
    if (!font.loadFromFile(m_font_localization))
    {
        throw std::invalid_argument("No font file in the specified location");
    }
}

void Score_Board::create_score_board(int width, int height)
{
    m_score_board.setFont(font);
    m_score_board.setString("Score = " + std::to_string(m_points));
    m_score_board.setCharacterSize(18);
    m_score_board.setFillColor(sf::Color::Red);
    m_score_board.setPosition(width / 2 - 50.f, height - 20.f);
    m_score_board.setStyle(sf::Text::Bold);
}

void Score_Board::add_score()
{
    m_points += 10;
}

void Score_Board::reset_points()
{
    m_points = 0;
}

void Score_Board::draw_score_board(sf::RenderWindow &thatWindow)
{
    thatWindow.draw(m_score_board);
}


