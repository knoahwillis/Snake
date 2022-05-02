#pragma once
#include <ctime>
#include <random>

// structure containing fruit, all it needs is x, y position
struct Fruit {
    int pos[2];
};

// creates a fruit at a random posiition
Fruit create_fruit();