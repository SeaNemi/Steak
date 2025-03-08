#include "cards.h"

Card::Card(){}
//Card Memeber variables
Card::Card(char f, short v, char s){
    face = f;
    value = v;
    suit = s;
}
char Card::getsuit(){
    return suit;
}
char Card::getface(){
    return face;
}


Deck::Deck(){
    //creates deck
    //clubs, diamonds, hearts, spades
    char suit = 'c';
    char face = 'n';
    short value = 1;
    for(short i = 0; i < DECKNUM; i++){
        //switch suit based on value:
        if(i == 13) suit = 'd';
        if(i == 26) suit = 'h';
        if(i == 39) suit = 's';

        //now need to figure out card value and if face card or not
        if(!(i % 13)) value = 1;
        else if (i % 13 < 10) value = (i%13)+1;
        else if (i % 13 == 10) value = 10, face = 'j';
        else if (i % 13 == 11) value = 10, face = 'q';
        else value = 10, face = 'k';

        Card card(face, value, suit);
        deck[i] = card;
        face = 'n';
    }
}

//randcard
//generates a random card
Card Deck::randcard(Random ran){

}

void Deck::test(){
    for(char i = 0; i < DECKNUM; i++){
        std::cout << "Value : " << deck[i].value <<  " S: " << deck[i].suit << " F:" << deck[i].face << std::endl;
    }
}