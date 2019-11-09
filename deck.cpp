#include <iostream>
#include "deck.h"
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

// pristine, sorted deck
Deck::Deck() {
    int index = 51;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            Card c(j+1, (Card::Suit) i);
            myCards[index] = c;
            index--;
        }
    }
    myIndex = 51;
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);  //seed the random number generator
}

// get a card, after 52 are dealt, fail
Card Deck::dealCard() {
    int temp = myIndex;
    myIndex--;
    return(myCards[temp]);
}

// shuffle the deck, all 52 cards present
void Deck::shuffle(){
    int numCards = 52;
    Card tempCard;
    for(int i = 0; i<numCards*3; i++){
        int rand1 = rand() % numCards;
        int rand2 = rand() % numCards;
        tempCard = myCards[rand1];
        myCards[rand1] = myCards[rand2];
        myCards[rand2] = tempCard;
    }
}

// # cards left in the deck
int Deck::size() const{
    return(myIndex+1);
}