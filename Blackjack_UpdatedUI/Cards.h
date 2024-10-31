/**
 * Project Untitled
 */


#ifndef _CARDS_H
#define _CARDS_H
#include <iostream>
#include <string>
#include <QString>
#include "Suit.h"


using namespace std;

enum class Rank{
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING

};

class Cards{

public:
    Suit suit;
    Rank cardRank;
    int value;

    void getCardValue();

    void getSuit();

    void toString();

    QString getCardImagePath() const;

};

#endif //_CARDS_H
