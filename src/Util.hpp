#pragma once
#include <SDL2/SDL.h>

void pause_game(SDL_Renderer* rend);

bool collision(SDL_Rect pos1, SDL_Rect pos2);