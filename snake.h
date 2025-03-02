//
// Created by Berkay  Sarıca on 14.01.2025.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <SDL_surface.h>
#include <vector>
#include <random>

#define SCREEN_WIDTH 680
#define SCREEN_HEIGHT 500

class snake {
public:
    bool gameOver = false;
    int col = 0;
    int row = 0;
    int cell_size = 20;
    std::vector<std::pair<int,int>> body;
    int score = 0;
    std::pair<int,int> apple = {5,10};
    std::string direction = "R";

    snake(SDL_Surface* surface, int row, int col);
    void update_body(SDL_Surface* surface);
    void draw_grid(SDL_Surface* surface);
    void reset(SDL_Surface* surface);
};



#endif //SNAKE_H
