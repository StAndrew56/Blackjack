/**
 * Project Untitled
 */


#ifndef _DECK_H
#define _DECK_H
#include <iostream>
#include <string>

using namespace std;

class Deck {
public:
    int cardCount;

Deck();

void shuffle();

void drawCard();
};

#endif //_DECK_H
