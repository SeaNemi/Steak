#ifndef CARDS_H
#define CARDS_H

#include "random_gen/random.h"
#include <iostream>

inline const short DECKNUM = 52;

class Card{
    public:
    Card();
    Card(char, short, char);
    char getsuit();
    char getface();

    //value is the only modifiable one (based on game played)
    short value;

    private:
    char suit;
    char face;
    friend class Deck;
};

//Deck of Cards class, public
class Deck{
    public:
    Deck();
    Card randcard(Random);
    Card deck[DECKNUM];
    void test();
};


#endif