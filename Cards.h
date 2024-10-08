/**
 * Project Untitled
 */


#ifndef _CARDS_H
#define _CARDS_H
#include <iostream>
#include <string>

using namespace std;

class Cards {
public:
    string suit;
    int value;

Cards();

void getCardValue();

void getSuit();

void toString();
};

#endif //_CARDS_H
