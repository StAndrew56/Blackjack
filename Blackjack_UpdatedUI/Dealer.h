/**
 * Project Untitled
 */


#ifndef _DEALER_H
#define _DEALER_H

#include "Deck.h" //For interaction with main Deck
#include "Cards.h" //To create a vector of cards as a Dealer's hand
#include <iostream>
#include <string>
#include <vector> //Dealer uses vectors

using namespace std;

class Dealer {

private:
    int dealerHandVal;
    int UserHandVal;
    vector<Cards> dealerHand; //Dealer's hand vector of cards
    Deck mainDeck;

public:
    Dealer(); //Constructor

    //Param: Player+Dealer count
    void dealCards(vector<Cards>& playerHand, vector<Cards>& deck);
    //Set 2 cards each from Deck vector into:
    //Dealer's hand vector - One set to visible in UI
    //Player's hand vector

    /**
         * @param Player player
         * @param double amount
         */
    //void pay(); //Not needed for now at least
    //Dealer adds extra currency to bet currency
    //& gives resulting new currency value to winner
    //If Dealer wins, Dealer takes bet currency
    //(Bet currency total set to 0)

    void removeCards();

    //Param: Pass by ref. the hand getting a card
    void addCard(vector<Cards>& currHand, vector<Cards>& deck);
    //Called when adding cards from Deck to hands

    void getUserHandVal();

    void setUserHandVal();
};

#endif //_DEALER_H
