#include "Fruit.hpp"


// creates fruit at a random position
Fruit create_fruit(){
    srand(time(0));

    Fruit ret;
    ret.pos[0] = int(rand() % 1000);
    ret.pos[1] = int(rand() % 1000);
    
    return ret;
}