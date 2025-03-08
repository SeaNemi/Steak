//random.cpp
#include "random.h"


//Random constructor
//blank since nothing needed
Random::Random(){}

//genrandom
//attempts to generate a nearly entirely new random number
//the range is [x, y) so y isn't included
int Random::genrandom(int x, int y){

}

int Random::seedgen(int seed){
    state[0] = seed;
    for(short i = 1; i < STATEBLOCK; i++){
        state[i] = ((PRIME * (state[i-1] ^ (state[i-1] >> 30))) + i) % PWR32;
    }
}

void Random::twist(){

}