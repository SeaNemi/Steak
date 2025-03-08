//random number generator, I attempted to develop a cryptologically secure rng
//the idea is that this code will provide random numbers which are almost truly random to prevent rigging
#ifndef RANDOM_H
#define RANDOM_H

//constants used in the mersenne twister process
inline const short STATEBLOCK = 624;
inline const unsigned int PRIME = 1812433253;
inline unsigned int long PWR32 = 4294967296;

class Random{
    public:
    Random();
    int genrandom(int, int);

    private:
    int seedgen(int seed);
    void twist();
    long state [STATEBLOCK];
};


#endif