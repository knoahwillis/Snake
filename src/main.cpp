#include "Fruit.hpp"
#include "Snake.hpp"
#include "Util.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {

    srand(time(NULL));

    // size of the window
    static int win = 700;

    // checks for errors initializing SDL
    if (SDL_Init == 0) {
        std::cout << "Error: " << SDL_GetError();
    }

    // creates the window
    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win, win, 0);

    // creates the renderer
    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // vector containing all of the fruit
    std::vector<Fruit> fruits;

    // the snake
    Snake snake;

    // bool to keep game running
    bool close = false;

    // bool to pause the game
    bool paused = false;

    // bool to end the game if you lose
    bool game_over = false;

    while (!close) {
        SDL_Event e;

        while (SDL_PollEvent(&e)) {
            switch (e.type) {

            // case to end the game
            case SDL_QUIT:
                close = true;
                break;

            // cases to move snake/pause/end game
            case SDL_KEYDOWN:
                switch (e.key.keysym.scancode) {
                case SDL_SCANCODE_W:
                    snake.move_up();
                    break;
                case SDL_SCANCODE_UP:
                    snake.move_up();
                    break;
                case SDL_SCANCODE_S:
                    snake.move_down();
                    break;
                case SDL_SCANCODE_DOWN:
                    snake.move_down();
                    break;
                case SDL_SCANCODE_D:
                    snake.move_right();
                    break;
                case SDL_SCANCODE_RIGHT:
                    snake.move_right();
                    break;
                case SDL_SCANCODE_A:
                    snake.move_left();
                    break;
                case SDL_SCANCODE_LEFT:
                    snake.move_left();
                    break;
                case SDL_SCANCODE_TAB:
                    paused = !paused;
                    break;
                case SDL_SCANCODE_ESCAPE:
                    close = true;
                    break;
                }
            }
        }

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 0);
        SDL_RenderClear(rend);

        if (paused && !game_over) {
            // if the game is paused, nothing happens but the pause
            pause_game(rend);
        } else if (!game_over) {
            // code to generate and render fruit
            int fruit_generator = rand() % 100;
            if (fruit_generator == 1) {
                fruits.push_back(create_fruit());
            }
            for (int i = 0; i < fruits.size(); i++) {
                SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
                SDL_RenderFillRect(rend, &fruits[i].fruit);
            }

            // code to render and move the snake
            snake.move_snake();
            for (int i = 0; i < snake.snake.size(); i++) {
                SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
                SDL_RenderFillRect(rend, &snake.snake[i]);
                for (int j = 0; j < fruits.size(); j++) {
                    if (snake.snake[i].x < fruits[j].fruit.x + fruits[j].fruit.w && snake.snake[i].x + snake.snake[i].w > fruits[j].fruit.x &&
                        snake.snake[i].y < fruits[j].fruit.y + fruits[j].fruit.h && snake.snake[i].y + snake.snake[i].h > fruits[j].fruit.y) {
                        snake.extend_snake();
                        fruits.erase(fruits.begin() + j);
                    }
                }
            }
            game_over = snake.died;
        } else {
            SDL_Rect end_game{350, 350, 300, 300};
            SDL_SetRenderDrawColor(rend, 255, 0, 0, 0);
            SDL_RenderFillRect(rend, &end_game);
        }
        SDL_RenderPresent(rend);

        SDL_Delay(1000 / 30);
    }

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);

    SDL_Quit();


    return 0;
}