//random number generator, I attempted to develop a cryptologically secure rng
//the idea is that this code will provide random numbers which are almost truly random to prevent rigging
#ifndef RANDOM_H
#define RANDOM_H

#include "common/common.h"

//constants used in the mersenne twister process
inline const short STATEBLOCK = 624;
inline const unsigned int PRIME = 1812433253;
inline const unsigned long PWR32 = 4294967296;

//twist values, usually hexadecimals but used ints for consistency
inline const unsigned int TWISTA = 2147483648;
inline const unsigned int TWISTB = 2147483647;
inline const unsigned int TOFFSET = 397;
inline const unsigned int XMASK = 2567483615;

//tempering constants
inline const unsigned int FIRSTTEMP = 11;
inline const unsigned int SECONDTEMP = 7;
inline const unsigned int THIRDTEMP = 15;
inline const unsigned int FINALTEMP = 18;
inline const unsigned int TEMPA = 2636928640;
inline const unsigned int TEMPB = 4022730752;

class Random{
    public:
    Random();
    Random(int);
    int genrandom(int, int);

    private:
    void seedgen(int seed);
    void stateCreate(unsigned int);
    void twist();
    unsigned int temper(unsigned int);
    unsigned int getMVal();
    unsigned int state[STATEBLOCK];
    short index;
};


#endif