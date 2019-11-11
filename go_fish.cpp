//
// Created by lwing on 11/7/2019.
//
#include <iostream>
#include "card.h"
#include <string>
#include <cstdlib>
#include "deck.h"
#include "player.h"
#include <fstream>

using namespace std;
int main(){
    ofstream myfile("gofish_results.txt");
    if(myfile.is_open()){
    Card c1;
    Card c2;
    Deck d;

    d.shuffle();
    Player p1("Bob");
    Player p2("Peter");

    myfile << "Player 1 is: " << p1.getName() << endl;
    myfile << "Player 2 is: " << p2.getName() << endl;
    for(int i = 0; i<7; i++){
        p1.addCard(d.dealCard());
        p2.addCard(d.dealCard());
    }
    myfile << p1.getName() << "'s hand: "<< p1.showHand() << endl;
    myfile << p2.getName() << "'s hand: "<< p2.showHand() << endl;
    while ((p1.getHandSize() != 0)&&(p1.checkHandForBook(c1, c2))) {
        p1.bookCards(c1, c2);
    }
    myfile << p1.getName() << "'s books: " << p1.showBooks() << endl;
    while ((p2.getHandSize() != 0)&&(p2.checkHandForBook(c1, c2))) {
        p2.bookCards(c1, c2);
    }
    myfile << p2.getName() << "'s books: " << p2.showBooks() << endl;

    while(!(p1.getHandSize() == 0 && p2.getHandSize() == 0 && d.size() == 0)) {
        myfile << "\n" << p1.getName() << "'s turn" << endl;
        if(p1.getHandSize()!=0) {
            c1 = p1.chooseCardFromHand();
            myfile << p1.getName() << ": Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
            if (p2.cardInHand(c1)) {
                myfile << p2.getName() << ": Yes" << endl;
                c2 = p2.removeCardFromHand(c1);
                p1.addCard(c2);
                while ((p1.getHandSize() != 0)&&(p1.checkHandForBook(c1, c2))) {
                    p1.bookCards(c1, c2);
                }
                myfile << p1.getName() << "'s books: " << p1.showBooks() << endl;
                myfile << p1.getName() << "'s hand: " << p1.showHand() << endl;
            } else {
                myfile << p2.getName() << ": No" << endl;
                p1.addCard((d.dealCard()));
                myfile << p1.getName() << "'s hand: " << p1.showHand() << endl;
                while ((p1.getHandSize() != 0)&&(p1.checkHandForBook(c1, c2))) {
                    p1.bookCards(c1, c2);
                }
            }
            myfile << p2.getName() << "'s hand: " << p2.showHand() << endl;
        }
        else {
            if (d.size() != 0) {
                p1.addCard((d.dealCard()));
                myfile << p1.getName() << "'s hand: " << p1.showHand() << endl;
                myfile << p1.getName() << "'s books: " << p1.showBooks() << endl;
            }
        }

        if(!(p1.getHandSize() == 0 && p2.getHandSize() == 0 && d.size() == 0)) {
            myfile << "\n" << p2.getName() << "'s turn" << endl;
        }

        if(p2.getHandSize()!=0) {
            c1 = p2.chooseCardFromHand();
            myfile << p2.getName() << ": Do you have a " << c1.rankString(c1.getRank()) << "?" << endl;
            if (p1.cardInHand(c1)) {
                myfile << p1.getName() << ": Yes" << endl;
                c2 = p1.removeCardFromHand(c1);
                p2.addCard(c2);
                while ((p2.getHandSize() != 0)&&(p2.checkHandForBook(c1, c2))) {
                    p2.bookCards(c1, c2);
                }
                myfile << p2.getName() << "'s books: " << p2.showBooks() << endl;
                myfile << p2.getName() << "'s hand: " << p2.showHand() << endl;
            } else {
                myfile << p1.getName() << ": No" << endl;
                p2.addCard((d.dealCard()));
                myfile << p2.getName() << "'s hand: " << p2.showHand() << endl;
                while ((p2.getHandSize() != 0)&&(p2.checkHandForBook(c1, c2))) {
                    p2.bookCards(c1, c2);
                }
            }
            myfile << p1.getName() << "'s hand: " << p1.showHand() << endl;
        }
        else{
            if (d.size() != 0) {
                p2.addCard((d.dealCard()));
                myfile << p2.getName() << "'s hand: " << p2.showHand() << endl;
                myfile << p2.getName() << "'s books: " << p2.showBooks() << endl;
            }
        }
    }
    myfile << "\n" << endl;
    myfile << p1.getName() << "'s books: " << p1.showBooks() << endl;
    myfile << p2.getName() << "'s books: " << p2.showBooks() << endl;
    if (p1.getBookSize() > p2.getBookSize()) {
        myfile << p1.getName() << " wins!" << endl;
    } else if (p2.getBookSize() > p1.getBookSize()) {
        myfile << p2.getName() << " wins!" << endl;
    } else {
        myfile << "It's a draw!" << endl;
    }
      myfile.close();
   }
   else cout << "Unable to open file";
    return(EXIT_SUCCESS);
}
