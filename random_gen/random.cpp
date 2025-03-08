//random.cpp
#include "random.h"


//Random constructor
//blank since nothing needed
Random::Random(){
    index = 0;
    
}

Random::Random(int seed){
    stateCreate(seed);
}
//genrandom
//attempts to generate a nearly entirely new random number
//the range is [x, y] so it is inclusive
int Random::genrandom(int x, int y){
    //if(y <= x) return x; //if not correctly done, return

    //firstly, need to create a distribution and figure out how many bits we need
    //we are using a uniform distribution
    unsigned int range = y - x + 1;
    unsigned int reqbits = logbasetwoceil(range);
    unsigned int scale = power(2, reqbits) - ((int)(power(2, reqbits)) % range);

    //our while loop tries to get a value for attempt which is within the allocated scale
    unsigned int attempt;
    do{
        //get a raw value from the mersenne twister, and attempt to scale
        unsigned int rawVal = getMVal();
        attempt = rawVal & ((1 << reqbits) - 1);
    }while(attempt >= scale);

    return (attempt % range) + x;
}

void Random::stateCreate(unsigned int seed){
    state[0] = seed;
    for(short i = 1; i < STATEBLOCK; i++){
        state[i] = ((PRIME * (state[i-1] ^ (state[i-1] >> 30))) + i) % PWR32;
    }
    index = 0;
}

//twist
//applies mersenne twist onto the state array
void Random::twist(){
    //twisting loop
    for(short i = 0; i < STATEBLOCK; i++){
        //need to and both values, the second uses mod to prevent segfaults
        unsigned long x = (state[i]&TWISTA) + (state[(i+1)%STATEBLOCK] & TWISTB);
        //xor with x, and again mod used to prevent seg faults
        state[i] = state[(i+TOFFSET)%STATEBLOCK] ^ (x >> 1);
        //finally, if x is odd then xor with XOR mask
        if(x%2) state[i] ^= XMASK;
    }
    index = 0; //reset the index
}

//temper
//follows the temping algorithm
unsigned int Random::temper(unsigned int y){
    y ^= (y >> FIRSTTEMP);
    y ^= (y << SECONDTEMP) & TEMPA;
    y ^= (y << THIRDTEMP) & TEMPB;
    y ^= (y >> FINALTEMP);
    return y;
}

//getMValue
//Returns a value from our Mersenne Twister
unsigned int Random::getMVal(){
    //if our value gets larger than the block, use the twist, then/otherwise return the temper
    if(index >= STATEBLOCK) twist();
    return temper(state[index++]);
}