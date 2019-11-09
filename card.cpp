#include <iostream>
#include "card.h"
#include <string>
#include <cstdlib>


using namespace std;

// default, ace of spades
Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

// return string version e.g. Ac 4h Js
string Card::toString() const{
    string suit, rank;
    suit = suitString(mySuit);
    rank = rankString(myRank);
    return(rank+suit);


}

// true if suit same as c

bool Card::sameSuitAs(const Card& c) const{
    if(mySuit == c.mySuit){
        return(true);
    }
    else{
        return(false);
    }

}

// return rank, 1..13
int  Card::getRank() const{
    return(myRank);
}

// return "s", "h",...
string Card::suitString(Suit s) const{
    string retString;
    switch(mySuit){
        case spades: retString = retString + 's';
            break;
        case hearts: retString = retString + 'h';
            break;
        case clubs: retString = retString + 'c';
            break;
        case diamonds: retString = retString + 'd';
    }
    return(retString);
}

// return "A", "2", ..."Q"
string Card::rankString(int r) const{
    string retString;
    switch(myRank){
        case 1: retString = 'A';
            break;
        case 2: retString = '2';
            break;
        case 3: retString = '3';
            break;
        case 4: retString = '4';
            break;
        case 5: retString = '5';
            break;
        case 6: retString = '6';
            break;
        case 7: retString = '7';
            break;
        case 8: retString = '8';
            break;
        case 9: retString = '9';
            break;
        case 10: retString = "10";
            break;
        case 11: retString = 'J';
            break;
        case 12: retString = 'Q';
            break;
        case 13: retString = 'K';
            break;
    }
    return(retString);
}


bool Card::operator == (const Card& rhs) const{
    return(myRank == rhs.myRank);
}

bool Card::operator != (const Card& rhs) const{
    return(myRank != rhs.myRank);
}

