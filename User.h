/**
 * Project Untitled
 */


#ifndef _USER_H
#define _USER_H

#include "Deck.h"
#include "Cards.h"
#include "Suit.h"
#include <iostream>
#include <string>

using namespace std;

class User {
public:
    int handVal;
    vector<Cards> userHand;
    double betVal;
    double balance = 5000;

User();

void printRankUser(Rank cardRank);

void printSuitUser(Suit suit);

void printUserHand();

void hit(Deck& deck);

void stand();

void split();

void placeBet(int bet);

void printUserHandTotal();

void pay();

void clearUserHand();

int getUserHandTotal();

void trueRank();

void takeBet();

};

#endif //_USER_H
