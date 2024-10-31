/**
 * Project Untitled
 */


#include "Dealer.h"
#include "Deck.h" //For interaction with main Deck
#include "User.h" //For interaction with user hand vector


#include <iostream>
#include <string>
//#include <vector> //Dealer uses vectors
//Has vector, Cards.h, Deck.h through Dealer.h

using namespace std;

/**
 * Dealer implementation
 */


Dealer::Dealer() {

}

dealCards() {

}
//Player count never goes above maximum size of vector array ..vector<Cards> mainDeck
void Dealer::dealCards(vector<Cards>& playerHand, vector<Cards>& deck) {

    for(int i = 0; i < 2; i++){
        addCard(playerHand, deck);
        addCard(dealerHand, deck);

    }

}


/**
 * @param Player player
 * @param double amount
 * @return return void
 */
/*
void Dealer::pay() {
    return;
}
*/

void Dealer::removeCards() {

}

void Dealer::addCard(vector<Cards>& currHand, vector<Cards>& deck) {

    currHand.push_back(deck.front());
    deck.erase(deck.begin());
}

void Dealer::getUserHandVal() {

}

void Dealer::setUserHandVal() {

}
