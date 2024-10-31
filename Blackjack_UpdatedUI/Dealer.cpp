/**
 * Project Untitled
 */


#include "Dealer.h"
#include "Deck.h" //For interaction with main Deck
#include "User.h" //For interaction with user hand vector


#include <iostream>
#include <string>
#include <QDebug>
//#include <vector> //Dealer uses vectors
//Has vector, Cards.h, Deck.h through Dealer.h

using namespace std;

/**
 * Dealer implementation
 */


Dealer::Dealer() {
    mainDeck.createDeck();  // Create the deck of cards
    mainDeck.shuffle();     // Shuffle the deck
}


//Player count never goes above maximum size of vector array ..vector<Cards> mainDeck
void Dealer::dealCards(vector<Cards>& playerHand, vector<Cards>& deck, User* user) {

    for(int i = 0; i < 2; i++){
        addCard(playerHand, deck);
        addCard(dealerHand, deck);
    }
    //do NOT remove, needed to deal with aces, will count num of
    //aces in playerHand off original deal.
    for(int i = 0; i < playerHand.size(); i++){

        if(playerHand[i].cardRank == Rank::ACE){
            user->aceCount++;
        }
    }
    //do Not remove, needed to deal with aces, will count num of
    //aces in dealerHand off original deal.
    for(int i = 0; i < dealerHand.size(); i++){

        if(dealerHand[i].cardRank == Rank::ACE){
            dealerAceCount++;
        }
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
    dealerHand.clear();
    dealerHand.shrink_to_fit();
}

void Dealer::addCard(vector<Cards>& currHand, vector<Cards>& deck) {

    currHand.push_back(deck.front());
    deck.erase(deck.begin());
}

void Dealer::getUserHandVal() {

}

void Dealer::setUserHandVal() {

}
