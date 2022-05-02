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

    // bool to keep game running
    bool close = false;

    // bool to pause the game
    bool paused = false;

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
                    break;
                case SDL_SCANCODE_UP:
                    break;
                case SDL_SCANCODE_S:
                    break;
                case SDL_SCANCODE_DOWN:
                    break;
                case SDL_SCANCODE_D:
                    break;
                case SDL_SCANCODE_RIGHT:
                    break;
                case SDL_SCANCODE_A:
                    break;
                case SDL_SCANCODE_LEFT:
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
        if (paused) {
            pause_game(rend);
        } else {
            int fruit_generator = rand() % 1000;
            if (fruit_generator == 1) {
                fruits.push_back(create_fruit());
            }
            for (int i = 0; i < fruits.size(); i++) {
                SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
                SDL_RenderFillRect(rend, &fruits[i].fruit);
            }
        }

        SDL_RenderPresent(rend);

        SDL_Delay(1000 / 60);

        std::cout << fruits.size();
    }

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);

    SDL_Quit();


    return 0;
}