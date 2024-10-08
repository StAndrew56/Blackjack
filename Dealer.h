/**
 * Project Untitled
 */


#ifndef _DEALER_H
#define _DEALER_H
#include <iostream>
#include <string>

using namespace std;

class Dealer {

    int dealerHandVal;
    int UserHandVal;

Dealer();

void dealCards();

/**
 * @param Player player
 * @param double amount
 */
void pay();

void removeCards();

void addCard();

void getUserHandVal();

void setUserHandVal();
};

#endif //_DEALER_H
