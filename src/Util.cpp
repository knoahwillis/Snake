#include "Util.hpp"

// void funtion to pause the game (just renders rectangles for now)
void pause_game(SDL_Renderer* rend) {
    // first rectangle on left
    SDL_Rect pause1;
    // second rectangle on right
    SDL_Rect pause2;

    pause1.x = 275;
    pause2.x = 375;
    pause1.y = 225;
    pause2.y = 225;

    pause1.h = 250;
    pause2.h = 250;
    pause1.w = 50;
    pause2.w = 50;

    // render the rectangles
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 0);
    SDL_RenderFillRect(rend, &pause1);
    SDL_RenderFillRect(rend, &pause2);
}

// checks for a collision
bool collision(SDL_Rect pos1, SDL_Rect pos2) {
    if (pos1.x < pos2.x + pos2.w && pos1.x + pos1.w > pos2.x && pos1.y < pos2.y + pos2.h && pos1.y + pos1.h > pos2.y) {
        return true;
    }
    return false;
}