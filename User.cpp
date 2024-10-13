/**
 * Project Untitled
 */


#include "User.h"
#include "Deck.h"
#include "Cards.h"
#include "Suit.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;
/**
 * User implementation
 */
User::User() {

}
void User::printRankUser(Rank cardRank){

    if(cardRank == Rank::ACE){
        cout << "Ace";
    }
    else if(cardRank == Rank::TWO){
        cout << "Two";
    }
    else if(cardRank == Rank::THREE){
        cout << "Three";
    }
    else if(cardRank == Rank::FOUR){
        cout << "Four";
    }
    else if(cardRank == Rank::FIVE){
        cout << "Five";
    }
    else if(cardRank == Rank::SIX){
        cout << "Six";
    }
    else if(cardRank == Rank::SEVEN){
        cout << "Seven";
    }
    else if(cardRank == Rank::EIGHT){
        cout << "Eight";
    }
    else if(cardRank == Rank::NINE){
        cout << "Nine";
    }
    else if(cardRank == Rank::TEN){
        cout << "Ten";
    }
    else if(cardRank == Rank::JACK){
        cout << "Jack";
    }
    else if(cardRank == Rank::QUEEN){
        cout << "Queen";
    }
    else if(cardRank == Rank::KING){
        cout << "King";
    }
}

void User::printSuitUser(Suit suit){

    if(suit == Suit::Hearts){
        cout << "Hearts";
    }
    else if(suit == Suit::Spades){
        cout << "Spades";
    }
    else if(suit == Suit::Clubs){
        cout << "Clubs";
    }
    else if(suit == Suit::Diamonds){
        cout << "Diamonds";
    }

}

void User::printUserHand(){

    for(int i = 0; i < userHand.size(); i++){
        printRankUser(userHand[i].cardRank);
        cout << " of ";
        printSuitUser(userHand[i].suit);
        cout << endl;
    }

}
void User::trueRank(){
    handVal = 0;
    for(int i = 0; i < userHand.size(); i++){

         if(userHand[i].cardRank == Rank::JACK){
            handVal += 10;
         }
         else if(userHand[i].cardRank == Rank::QUEEN){
            handVal += 10;
         }
         else if(userHand[i].cardRank == Rank::KING){
            handVal += 10;
         }
         else{
            handVal += (int)userHand[i].cardRank;
         }
        }
}

void User::hit(Deck& deck) {// fix cardRank
    handVal = 0;
    trueRank();
    if(handVal < 21){

        userHand.push_back(deck.deckOfCards.front());

        deck.deckOfCards.erase(deck.deckOfCards.begin());

        for(int i = 0; i < userHand.size(); i++){
        handVal = (int)userHand[i].cardRank;
        }
    }
    else{
        cout << "you cannot hit!";
    }
}

void User::stand() {

}

void User::split() {

}
//gets called when user places legal bet
//will do the subtraction
void User::placeBet(int bet) {

        balance -= bet;
        betVal = bet;

}

/**
 * @param int handVal
 * @return return int
 */

void User::printUserHandTotal() {
    trueRank();
    cout << handVal;
}
int User::getUserHandTotal() {
    trueRank();

    return handVal;
}
//pays winner.
void User::pay() {

        balance += (betVal * 2);

}
void User::clearUserHand(){
    userHand.clear();
    userHand.shrink_to_fit();
}

//takes users bet, if it is a valid amount will
//subtract the bet from their balance
void User::takeBet(){
    int bet = 0;
    bool flag = true;

    while(flag){
        //button for bet input here
        //------------------------------------------
        int bet;
        cin >> bet;
        if(bet > balance){
            cout << "select valid bet amount";
        }
        //------------------------------------------
        else{
            placeBet(bet);
            flag = false;
        }
    }
}

