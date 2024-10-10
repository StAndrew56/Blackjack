/**
 * Project Untitled
 */


#ifndef _DECK_H
#define _DECK_H
#include "Cards.h"
#include "Suit.h"
#include <iostream>
#include <string>

using namespace std;

class Deck {

public:

    Cards deckOfCards[52];

Deck();

void printCard();

void printRank(Rank cardRank);

void printSuit(Suit suit);

void printDeck();

void createDeck();

void shuffle();

void drawCard();
};

#endif //_DECK_H
