//
// Created by lwing on 11/7/2019.
//
#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "player.h"
#include <cstdlib>
#include <ctime>

using namespace std;

//adds a card to the hand
void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2) {
    for (int i = 0; i < myHand.size()-1; i++) {
        for (int j = i+1; j < myHand.size(); j++) {
            if (myHand[i] == myHand[j]) {
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    int rand1 = rand() % (myHand.size());
    return myHand[rand1];
}

bool Player::cardInHand(Card c) const {
    for (Card c1 : myHand) {
        if (c1 == c) {
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    for (int i = 0; i < myHand.size(); i++) {
        if (myHand[i] == c) {
            Card c1 = myHand[i];
            myHand.erase(myHand.begin() + i);
            return c1;
        }
    }
}

string Player::showHand() const{
    string retString;
    for(Card c1 : myHand){
        retString = retString + " " +c1.toString();
    }
    return(retString);
}


string Player::showBooks() const{
    string retString;
    for(Card c1 : myBook){
        retString = retString + " " +c1.toString();
    }
    return(retString);
}

int Player::getHandSize() const{
    return(myHand.size());
}


int Player::getBookSize() const{
    return(myBook.size()/2);
}
