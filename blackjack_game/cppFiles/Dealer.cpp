/**
 * Project Untitled
 */


#include "Dealer.h"
<<<<<<< Updated upstream
=======
#include "Deck.h" //For interaction with main Deck
#include "User.h" //For interaction with user hand vector
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream

dealCards() {

=======
//Player count never goes above maximum size of vector array ..vector<Cards> mainDeck
void Dealer::dealCards(vector<Cards>& playerHand) {
    for(int i = 0; i < 2; i++){
        addCard(playerHand);
        addCard(dealerHand);
    }
>>>>>>> Stashed changes
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

void Dealer::addCard(vector<Cards>& currHand) {

    currHand.push_back(mainDeck.deckOfCards.front());
    mainDeck.deckOfCards.erase(mainDeck.deckOfCards.begin());
}

void Dealer::getUserHandVal() {

}

void Dealer::setUserHandVal() {

}
