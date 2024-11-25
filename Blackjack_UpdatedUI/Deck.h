/**
 * Project Untitled
 */


#ifndef _DECK_H
#define _DECK_H
#include "Cards.h"
#include "Suit.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Deck {

public:

    vector<Cards> deckOfCards;
    //bool testingMode = true;  // Enable this as well as 2 other functions in Deck.cpp to test split


Deck();

void printCard();

void printRank(Rank cardRank);

void printSuit(Suit suit);

void printDeck();

void createDeck();

void shuffle();

void drawCard();

void printSize();

void killDeck();



};

#endif //_DECK_H
