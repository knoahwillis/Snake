#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    // size of the window
    static int win = 1000;

    // checks for errors initializing SDL
    if (SDL_Init == 0) {
        std::cout << "Error: " << SDL_GetError();
    }

    // creates the window
    SDL_Window* window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win, win, 0);

    // creates the renderer
    SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);



    return 0;
}