#include "Fruit.hpp"


// creates fruit at a random position
Fruit create_fruit(){
    srand(time(0));

    Fruit ret;
    ret.fruit.x = rand() % 700;
    ret.fruit.y = rand() % 700;
    ret.fruit.h = 5;
    ret.fruit.w = 5;
    
    return ret;
}