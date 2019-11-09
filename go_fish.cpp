//
// Created by lwing on 11/7/2019.
//
#include <iostream>
#include "card.h"
#include <string>
#include <cstdlib>
#include "deck.h"
#include "player.h"
using namespace std;
int main(){
    Card c1;
    Card c2;
    Deck d;

    d.shuffle();
    Player p1("Bob");
    Player p2("Peter");

    cout << p1.getName() << endl;
    cout << p2.getName() << endl;
    for(int i = 0; i<7; i++){
        p1.addCard(d.dealCard());
        p2.addCard(d.dealCard());
    }
    cout << p1.getName() << " hand: "<< p1.showHand() << endl;
    cout << p2.getName() << " hand: "<< p2.showHand() << endl;
    while ((p1.getHandSize() != 0)&&(p1.checkHandForBook(c1, c2))) {
        p1.bookCards(c1, c2);
    }
    cout << p1.getName() << " books: " << p1.showBooks() << endl;
    while ((p2.getHandSize() != 0)&&(p2.checkHandForBook(c1, c2))) {
        p2.bookCards(c1, c2);
    }
    cout << p2.getName() << " books: " << p2.showBooks() << endl;

    while(!(p1.getHandSize() == 0 && p2.getHandSize() == 0 && d.size() == 0)) {
        if(p1.getHandSize()!=0) {
            c1 = p1.chooseCardFromHand();
            cout << p1.getName() << ": Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
            if (p2.cardInHand(c1)) {
                cout << p2.getName() << ": Yes" << endl;
                c2 = p2.removeCardFromHand(c1);
                p1.addCard(c2);
                while ((p1.getHandSize() != 0)&&(p1.checkHandForBook(c1, c2))) {
                    p1.bookCards(c1, c2);
                }
                cout << p1.getName() << " books: " << p1.showBooks() << endl;
            } else {
                cout << p2.getName() << ": No" << endl;
                p1.addCard((d.dealCard()));
                cout << p1.getName() << " hand: " << p1.showHand() << endl;
                while ((p1.getHandSize() != 0)&&(p1.checkHandForBook(c1, c2))) {
                    p1.bookCards(c1, c2);
                }
            }
        }
        else {
            if (d.size() != 0) {
                p1.addCard((d.dealCard()));
                cout << p1.getName() << " hand: " << p1.showHand() << endl;
                cout << p1.getName() << " books: " << p1.showBooks() << endl;
            }
        }

        cout << p2.getName() << " hand: " << p2.showHand() << endl;
        if(p2.getHandSize()!=0) {
            c1 = p2.chooseCardFromHand();
            cout << p2.getName() << ": Do you have " << c1.rankString(c1.getRank()) << "?" << endl;
            if (p1.cardInHand(c1)) {
                cout << p1.getName() << ": Yes" << endl;
                c2 = p1.removeCardFromHand(c1);
                p2.addCard(c2);
                while ((p2.getHandSize() != 0)&&(p2.checkHandForBook(c1, c2))) {
                    p2.bookCards(c1, c2);
                }
                cout << p2.getName() << " books: " << p2.showBooks() << endl;
            } else {
                cout << p1.getName() << ": No" << endl;
                p2.addCard((d.dealCard()));
                cout << p2.getName() << " hand: " << p2.showHand() << endl;
                while ((p2.getHandSize() != 0)&&(p2.checkHandForBook(c1, c2))) {
                    p2.bookCards(c1, c2);
                }
            }
            cout << p1.getName() << " hand: " << p1.showHand() << endl;
        }
        else{
            if (d.size() != 0) {
                p2.addCard((d.dealCard()));
                cout << p2.getName() << " hand: " << p2.showHand() << endl;
                cout << p2.getName() << " books: " << p2.showBooks() << endl;
            }
        }
    }

    return(EXIT_SUCCESS);
}
