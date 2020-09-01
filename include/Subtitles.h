#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#ifndef SNAKE_INFORMATIONS_H
#define SNAKE_INFORMATIONS_H

class Subtitles
{
private:
    std::string m_font_localization;
    sf::Font font;
    sf::Text m_collision_information;
    sf::Text m_key_press_information;
    sf::Text m_getting_points_information;
    sf::Text m_game_title_text;
    sf::Text m_quit_button_text;
    sf::Text m_start_button_text;
    sf::Text m_final_points_information;
    int m_window_width;
    int m_window_height;
public:
    Subtitles(std::string font_localization, int window_width, int window_height);
    void set_quit_button_text(sf::FloatRect quit_button_global_bounds);
    void set_start_button_text(sf::FloatRect start_button_global_bounds);
    void show_points_after_collision(int points);
    void show_title();
    void show_collision_information();
    void show_getting_points_information(sf::Vector2f food_position);
    void draw_menu_text(sf::RenderWindow &thatWindow);
    inline void clear_collision_information()
    {
        m_collision_information.setString("");
        m_key_press_information.setString("");
    }
    inline void clear_getting_points_information() {m_getting_points_information.setString("");};
    inline void clear_final_points_information() {m_final_points_information.setString("");};
    void draw_collision_information(sf::RenderWindow &thatWindow);
    void draw_getting_points_information(sf::RenderWindow &thatWindow);
    ~Subtitles() {};
};

#endif //SNAKE_INFORMATIONS_H
