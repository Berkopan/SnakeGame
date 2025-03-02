#include <iostream>
#include <SDL.h>
#include "snake.h"


int main()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Surface* surface = SDL_GetWindowSurface(window);

    bool isRunning = true;
    SDL_Event event;

    snake game = snake(surface, 25,34);
    bool keydown = false;

    SDL_UpdateWindowSurface(window);
    while (isRunning) {
        keydown = false;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            } else if (event.type == SDL_WINDOWEVENT) {
                surface = SDL_GetWindowSurface(window);
            } else if (event.type == SDL_KEYDOWN) {
                if (game.gameOver == false) {
                    keydown = true;
                    if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w) {
                        if (game.direction != "D") {
                            game.direction = "U";
                        }
                        game.update_body(surface);
                    } else if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d) {
                        if (game.direction != "L") {
                            game.direction = "R";
                        }
                        game.update_body(surface);
                    } else if (event.key.keysym.sym == SDLK_DOWN|| event.key.keysym.sym == SDLK_s) {
                        if (game.direction != "U") {
                            game.direction = "D";
                        }
                        game.update_body(surface);
                    } else if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a) {
                        if (game.direction != "R") {
                            game.direction = "L";
                        }
                        game.update_body(surface);
                    }
                }
                if (event.key.keysym.sym == SDLK_r) {
                    game.gameOver = false;
                    game.reset(surface);
                }
            }
        }
        if (!keydown && game.gameOver == false) {
            game.update_body(surface);
        }

        if (game.gameOver) {
            const int G[25][34] = {
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0},
                {0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,1,1,1,1,0,0},
                {0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0},
                {0,0,1,0,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
                {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
                {0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0},
                {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
                {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
                {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
                {0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0},
                {0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
                {0,0,1,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0},
                {0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},
                {0,0,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,1,0,0,0,1,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
            };

            for (int i = 0; i < 25; ++i) {
                for (int j = 0; j < 34; ++j) {
                    if (G[i][j] == 1) {
                        SDL_Rect rect = {j*20,i*20,20,20};
                        SDL_FillRect(surface, &rect, 0xffffffff);
                    }
                }
            }
            SDL_UpdateWindowSurface(window);
        }

        SDL_UpdateWindowSurface(window);
        SDL_Delay(300);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
