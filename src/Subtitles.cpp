#include "Subtitles.h"
#include <iostream>

Subtitles::Subtitles(std::string font_localization, int window_width, int window_height):
m_font_localization(font_localization), m_window_width(window_width), m_window_height(window_height)
{
    if (!font.loadFromFile(m_font_localization))
    {
        throw std::invalid_argument("No font file in the specified location");
    }
    else if ((m_window_height < 0) or (m_window_width < 0))
    {
        throw std::invalid_argument("Wrong resolution");
    }
}

void Subtitles::show_collision_information()
{
    m_collision_information.setFont(font);
    m_collision_information.setString("Impact detected.\n     Try again!");
    m_collision_information.setCharacterSize(24);
    m_collision_information.setFillColor(sf::Color::Red);
    m_collision_information.setStyle(sf::Text::Bold);
    m_collision_information.setPosition((m_window_width / 2.f) - (m_collision_information.getLocalBounds().width / 2.f),
                                 (m_window_height / 4.f) - (m_collision_information.getLocalBounds().height));

    m_key_press_information.setFont(font);
    m_key_press_information.setString("Press enter to continue.\nEscape to return to menu.");
    m_key_press_information.setCharacterSize(24);
    m_key_press_information.setFillColor(sf::Color::Red);
    m_key_press_information.setStyle(sf::Text::Bold);
    m_key_press_information.setPosition((m_window_width / 2.f) - (m_key_press_information.getLocalBounds().width / 2.f),
                                        (m_window_height - (m_window_height / 4.f)) - (m_key_press_information.getLocalBounds().height));
}

void Subtitles::show_getting_points_information(sf::Vector2f food_position)
{
    m_getting_points_information.setFont(font);
    m_getting_points_information.setString("10 points for you!");
    m_getting_points_information.setCharacterSize(14);
    m_getting_points_information.setFillColor(sf::Color::Red);
    m_getting_points_information.setStyle(sf::Text::Bold);
    m_getting_points_information.setPosition((food_position.x - m_getting_points_information.getLocalBounds().width), \
    (food_position.y + m_getting_points_information.getLocalBounds().height));

}

void Subtitles::show_title()
{
    m_game_title_text.setFont(font);
    m_game_title_text.setString("SNAKE");
    m_game_title_text.setCharacterSize(80);
    m_game_title_text.setFillColor(sf::Color::Blue);
    m_game_title_text.setStyle(sf::Text::Bold);
    m_game_title_text.setPosition((m_window_width / 2.f) - (m_game_title_text.getLocalBounds().width / 2.f),
                            (m_window_height / 4.f) - (m_game_title_text.getLocalBounds().height / 2.f));

}

void Subtitles::set_quit_button_text(sf::FloatRect quit_button_global_bounds)
{
    m_quit_button_text.setFont(font);
    m_quit_button_text.setString("QUIT");
    m_quit_button_text.setCharacterSize(40);
    m_quit_button_text.setFillColor(sf::Color::White);
    m_quit_button_text.setStyle(sf::Text::Bold);
    m_quit_button_text.setPosition(((quit_button_global_bounds.left + quit_button_global_bounds.width / 2.f) - (m_quit_button_text.getGlobalBounds().width / 2.f)),
                                   ((quit_button_global_bounds.top + quit_button_global_bounds.height / 2.f) - (m_quit_button_text.getGlobalBounds().height / 1.2f)));
}

void Subtitles::set_start_button_text(sf::FloatRect start_button_global_bounds)
{
    m_start_button_text.setFont(font);
    m_start_button_text.setString("PLAY");
    m_start_button_text.setCharacterSize(50);
    m_start_button_text.setFillColor(sf::Color::White);
    m_start_button_text.setStyle(sf::Text::Bold);
    m_start_button_text.setPosition((start_button_global_bounds.left + start_button_global_bounds.width / 2.f) - (m_start_button_text.getLocalBounds().width / 2.f),
                                    (start_button_global_bounds.top + start_button_global_bounds.height / 2.f) - (m_start_button_text.getLocalBounds().height / 1.2f));
}

void Subtitles::show_points_after_collision(int points)
{
    m_final_points_information.setFont(font);
    m_final_points_information.setString("Your final score = " + std::to_string(points));
    m_final_points_information.setCharacterSize(24);
    m_final_points_information.setFillColor(sf::Color::Red);
    m_final_points_information.setStyle(sf::Text::Bold);
    m_final_points_information.setPosition((m_window_width / 2.f) - (m_final_points_information.getLocalBounds().width / 2.f),
                                           (m_window_height - (m_window_height / 4.f) - (m_key_press_information.getLocalBounds().height))
                                           - (m_final_points_information.getLocalBounds().height));
}

void Subtitles::draw_menu_text(sf::RenderWindow &thatWindow)
{
    thatWindow.draw(m_game_title_text);
    thatWindow.draw(m_quit_button_text);
    thatWindow.draw(m_start_button_text);
}

void Subtitles::draw_collision_information(sf::RenderWindow &thatWindow)
{
    if (m_collision_information.getCharacterSize() > 0 and m_key_press_information.getCharacterSize() > 0
    and m_final_points_information.getCharacterSize() > 0) //draw only if text exists
    {
        thatWindow.draw(m_collision_information);
        thatWindow.draw(m_key_press_information);
        thatWindow.draw(m_final_points_information);
    }
    else return;
}

void Subtitles::draw_getting_points_information(sf::RenderWindow &thatWindow)
{
    if (m_getting_points_information.getCharacterSize() > 0)
    {
        thatWindow.draw(m_getting_points_information);
    }
    else return;
}




