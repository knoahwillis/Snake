#pragma once
#include <ctime>
#include <random>
#include <SDL2/SDL.h>


// structure containing fruit, all it needs is x, y position
struct Fruit {
    SDL_Rect fruit;
};

// creates a fruit at a random posiition
Fruit create_fruit();