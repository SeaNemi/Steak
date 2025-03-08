#include "cards/cards.h"
#include "random_gen/random.h"
#include <iostream>

//main
int main(){
    Random ran(7);
    long deck[52] = {0};

    for(unsigned long i = 0; i < 52000000; i++){
        int j = ran.genrandom(0, 51);
        deck[j]++;
    }

    for(int i = 0; i < 52; i++){
        std::cout << "Value of" << i << ": " << deck[i] << std::endl;
    }
    return 0;
}