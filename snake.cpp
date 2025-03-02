//
// Created by Berkay  Sarıca on 14.01.2025.
//

#include "snake.h"

#include <iostream>


snake::snake(SDL_Surface* surface, const int row = 25, const int col = 34) {
    this->row = row;
    this->col = col;

    body.emplace_back(2,12);
    body.emplace_back(1,12);
    update_body(surface);
    draw_grid(surface);
}

void snake::draw_grid(SDL_Surface* surface) {
    for (int i = 0; i < col; ++i) {
        SDL_Rect rect = {i*cell_size, 0, 1, SCREEN_HEIGHT};
        SDL_FillRect(surface, &rect, 0x282e2d);
    }
    for (int j = 0; j < row; ++j) {
        SDL_Rect rect = {0, j*cell_size, SCREEN_WIDTH, 1};
        SDL_FillRect(surface, &rect, 0x282e2d);
    }
}

void snake::update_body(SDL_Surface* surface) {
    if (body.at(0) == apple) {
        body.insert(body.begin(), apple);
        score += 5;

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distribX(0, col - 1);
        std::uniform_int_distribution<> distribY(0, row - 1);

        bool isCrossing = false;
         do {
             isCrossing = false;
             apple.first = distribX(gen);
             apple.second = distribY(gen);
             for (const auto & i : body) {
                 if (i == apple) {
                     isCrossing = true;
                     break;
                 }
             }
        } while (isCrossing);
    }
    body.pop_back();
    std::pair<int,int> head = body.at(0);
    if (direction == "U") {
        body.insert(body.begin(), {head.first, (head.second == 0 ? row-1 : head.second - 1)});
    } else if (direction == "R") {
        body.insert(body.begin(), {(head.first == col-1 ? 0 : head.first + 1), head.second});
    } else if (direction == "D") {
        body.insert(body.begin(), {head.first, (head.second == row-1 ? 0 : head.second + 1)});
    } else if (direction == "L") {
        body.insert(body.begin(), {(head.first == 0 ? col-1 : head.first - 1), head.second});
    }

    for (int i = 1; i < body.size(); ++i) {
        if (body.at(0) == body.at(i)) {
            gameOver = true;
            break;
        }
    }

    SDL_FillRect(surface, nullptr, 0x00000000);
    draw_grid(surface);

    if (!gameOver) {
        const SDL_Rect appleRect = {apple.first * 20, apple.second * 20, 20, 20};
        SDL_FillRect(surface, &appleRect, 0xf00707);

        for (auto & i : body) {
            SDL_Rect snakeRect = {i.first * 20, i.second * 20, 20, 20};
            SDL_FillRect(surface, &snakeRect, 0x245205);
        }
    }
}

void snake::reset(SDL_Surface* surface) {
    apple = {5,10};
    body.clear();
    body.emplace_back(2,12);
    body.emplace_back(1,12);
    direction = "R";
    update_body(surface);
    draw_grid(surface);
}



