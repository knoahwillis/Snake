#include "Snake.hpp"

Snake::Snake() {
    for (int i = 0; i < 5; i++) {
        snake.push_back(SDL_Rect{350 - (i * 5), 350, 10, 10});
    }
}

Snake::~Snake() {}

void Snake::move_right() { move = 1; }

void Snake::move_left() { move = -1; }

void Snake::move_up() { move = -2; }

void Snake::move_down() { move = 2; }

void Snake::move_snake() {
    SDL_Rect next_pos = snake.back();
    if (move == 1 || move == -1) {
        next_pos.x += move * 5;
    } else {
        next_pos.y += (move / 2) * 5;
    }
    snake.erase(snake.begin());
    snake.push_back(next_pos);
}
