cmake_minimum_required(VERSION 3.1)

project(SNAKE)
include_directories(./include)
## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SNAKE src/main.cpp include/collision.h src/collision.cpp include/informations.h src/informations.cpp src/score_board.cpp include/score_board.h include/game_menu.h src/game_menu.cpp
        src/game.cpp include/game.h src/player.cpp include/player.h src/food.cpp include/food.h)
target_link_libraries(SNAKE sfml-graphics sfml-audio)
