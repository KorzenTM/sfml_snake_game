cmake_minimum_required(VERSION 3.1)

project(SNAKE)
include_directories(./include)
## If you want to link SFML statically
set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(SNAKE src/main.cpp include/collision.h src/collision.cpp)
target_link_libraries(SNAKE sfml-graphics sfml-audio)
