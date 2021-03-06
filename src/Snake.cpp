#include "Snake.hpp"
#include "Util.hpp"
#include <iostream>

Snake::Snake() {
    snake.push_back(SDL_Rect{350, 350, 10, 10});
    snake.push_back(SDL_Rect{360, 350, 10, 10});
    snake.push_back(SDL_Rect{370, 350, 10, 10});
    snake.push_back(SDL_Rect{380, 350, 10, 10});
    snake.push_back(SDL_Rect{390, 350, 10, 10});
}

Snake::~Snake() {}

void Snake::move_right() {
    // if (move == -1) {
    //     died = true;
    // }
    move = 1;
}

void Snake::move_left() {
    if (move == 1) {
        // died = true;
    }
    move = -1;
}

void Snake::move_up() {
    if (move == 2) {
        // died = true;
    }
    move = -2;
}

void Snake::move_down() {
    if (move == -2) {
        // died = true;
    }
    move = 2;
}

void Snake::move_snake() {
    SDL_Rect next_pos = snake.back();
    if (move == 1 || move == -1) {
        next_pos.x += move * 10;
    } else {
        next_pos.y += (move / 2) * 10;
    }
    snake.erase(snake.begin());
    snake.push_back(next_pos);
}

void Snake::extend_snake() {
    SDL_Rect next_pos = snake.back();
    if (move == 1 || move == -1) {
        next_pos.x += move * 10;
    } else {
        next_pos.y += (move / 2) * -10;
    }
    snake.insert(snake.begin(), next_pos);
}

void Snake::snake_died() {
    SDL_Rect head = snake.back();
    if (head.x < 0 || head.x + head.w > 700 || head.y < 0 || head.y + head.h > 700) {
        died = true;
    }
    for (int i = 0; i < snake.size() - 1; i++) {
        if (collision(head, snake[i])) {
            died = true;
        }
    }
}