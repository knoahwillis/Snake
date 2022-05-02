#pragma once
#include <SDL2/SDL.h>
#include <vector>

class Snake {
    // direction of movement (1 for right, -1 for left, -2 for up, 2 for down)
    int move = 1;

public:
    // snake itself (queue of rects, moving forward pops the last rect and adds a new one in front of it)
    std::vector<SDL_Rect> snake;

    // boolean to see if snake has died
    bool died = false;

    // creates snake in the middle of the board
    Snake();
    ~Snake();

    // changes the direction of the snake
    void move_right();
    void move_left();
    void move_up();
    void move_down();

    // deletes the rect and adds a new one
    void move_snake();

    // eats a fruit
    void extend_snake();

    // checks if the snake has run into itself
    void snake_died();
};