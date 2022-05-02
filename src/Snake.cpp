#include "Snake.hpp"
#include <iostream>

Snake::Snake() { 
    snake.push_back(SDL_Rect{350, 350, 10, 10}); 
    snake.push_back(SDL_Rect{340, 350, 10, 10}); 
    snake.push_back(SDL_Rect{330, 350, 10, 10}); 
    snake.push_back(SDL_Rect{320, 350, 10, 10}); 
    snake.push_back(SDL_Rect{310, 350, 10, 10}); 
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
    }
    else {
        next_pos.y += (move / 2) * 5;
    }
    snake.erase(snake.begin());
    snake.push_back(next_pos);
}

void Snake::extend_snake() {
    for (int i = 0; i < 5; i++) {
        SDL_Rect next_pos = snake.back();
        if (move == 1 || move == -1) {
            next_pos.x += move * 5;
        } else {
            next_pos.y += (move / 2) * 5;
        }
        snake.insert(snake.begin(), next_pos);
    }
}

bool Snake::snake_died() {
    SDL_Rect head = snake.back();
    if(head.x < 0 || head.x + head.w > 700 || head.y < 0 || head.y + head.h > 700){
        return true;
    }
    // for (int i = 0; i < snake.size() - 1; i++) {
    //     if (snake[i].x < snake[head].x + snake[head].w && snake[i].x + snake[i].w > snake[head].x && snake[i].y < snake[head].y + snake[head].h &&
    //         snake[i].y + snake[i].h > snake[head].y) {
    //         std::cout << i;
    //         return true;
    //     }
    // }
    return false;
}