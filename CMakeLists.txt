cmake_minimum_required(VERSION 3.29)
project(snake)

set(CMAKE_CXX_STANDARD 11)

include_directories(/opt/homebrew/include/SDL2) # Update the path to match your environment. / Yolu sisteminize uyacak şekilde güncelleyin.
link_directories(/opt/homebrew/lib) # Update the path to match your environment. / Yolu sisteminize uyacak şekilde güncelleyin.

add_executable(snake main.cpp
        snake.cpp
        snake.h)

target_link_libraries(snake SDL2 SDL2_ttf)
