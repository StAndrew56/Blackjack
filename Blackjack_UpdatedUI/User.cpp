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
#include <QString>
#include <QObject>

using namespace std;
/**
 * User implementation
 */
User::User() {

}
//prints the cards rank.
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
//prints the cards suit.
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
//called when you want to print the users hand.
//this will not convert the hand to int.
void User::printUserHand(){

    for(int i = 0; i < userHand.size(); i++){
        printRankUser(userHand[i].cardRank);
        cout << " of ";
        printSuitUser(userHand[i].suit);
        cout << endl;
    }

}
void User::printUserSplitHand(){

    for(int i = 0; i < splitHand.size(); i++){
        printRankUser(splitHand[i].cardRank);
        cout << " of ";
        printSuitUser(splitHand[i].suit);
        cout << endl;
    }

}
//called when you want to set the trueRank of the Users hand.
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
         else if(userHand[i].cardRank == Rank::ACE){
             handVal += 11;
         }
         else{
            handVal += (int)userHand[i].cardRank;
         }
        }
}

//called when the User wants to hit, will add 1 card to their hand.
void User::hit(Deck& deck) {
    //handVal = 0;
    if(handVal == 0){
        trueRank();
    }
    //make sure user doesn't have 21
    if(handVal != 21){
        //add the card to userHand
        userHand.push_back(deck.deckOfCards.front());
        //delete card from deckOfCards
        deck.deckOfCards.erase(deck.deckOfCards.begin());

        //get the last position of userHand(where you just added the card)
        int lastCard = userHand.size() - 1;

        //add the last card's value to handVal
        if(userHand[lastCard].cardRank == Rank::JACK){
            handVal += 10;
        }
        else if(userHand[lastCard].cardRank == Rank::QUEEN){
            handVal += 10;
        }
        else if(userHand[lastCard].cardRank == Rank::KING){
            handVal += 10;
        }
        else if(userHand[lastCard].cardRank == Rank::ACE){
            handVal += 11;
            aceCount++;//if ace add to ace counter, each ace will only be counted once.
        }
        else{
            handVal += (int)userHand[lastCard].cardRank;
        }
        //this block deals with ace's when nessecary. very dpendent on ace counter.
        //ace counter is above and in dealer class(in function dealCards()).
        if(handVal > 21){

            for(int i =0; i < userHand.size(); i++){

                if(userHand[i].cardRank == Rank::ACE){

                    if(handVal != 21){

                        while(handVal > 21 && aceCount > 0){

                            handVal -= 10;//turn the ace into a 1.

                            aceCount--;//ace can't be decremented again.
                        }
                    }

                }
            }
        }
    }
    //user has 21
    else{

        emit actionError("Your already have 21! Press Stand to continue.");
    }

}

//called when user wants to stand.
//a semantic call.
void User::stand() {

}
//splits user hand into 2 hands.
void User::split() {

    if(userHand[0].cardRank == userHand[1].cardRank){
            if(betVal <= balance){
                splitHand[0] = userHand[1];
                splitBetVal = betVal;
                placeBet(splitBetVal);
                userHand.pop_back();

            }
            else{
                cout << "You can't afford to split!" << endl;
            }
        }
    else{
        cout << "You can't split!" << endl;
    }

}
//doubles the players bet value and subtracts from the balance
void User::doubleDown(){
    balance -= betVal;
    betVal = betVal + betVal;

}
void User::blackJack(){

}
//gets called when user places legal bet
//will do the subtraction from the balance
void User::placeBet(int bet) {

    if (bet <= balance) {
        balance -= bet;
        betVal = bet;
        emit betPlaced(bet); // Emit a signal to update the UI
    }
    else {
        emit actionError("Invalid bet amount!");
    }

}

/**
 * @param int handVal
 * @return return int
 */
//called if you want to print the users handVal.
void User::printUserHandTotal() {
    trueRank();
    cout << handVal;
}
//called to get the users handVal.
int User::getUserHandTotal() {
    trueRank();

    return handVal;
}
//pays winner. double the bet and adds that number to the
//users balance.
void User::pay() {

        balance += (betVal * 2);

}
void User::clearUserHand(){
    userHand.clear();
    userHand.shrink_to_fit();
}
void User::bust(){
    betVal = 0;
    aceCount = 0;
    emit betPlaced(betVal);
    emit balanceUpdated(balance);

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

void User::submitBet(int bet) {
    placeBet(bet);
}

void User::increaseBet(int amount) {
    if (balance >= amount) {
        betVal += amount;
        balance -= amount;
        emit betPlaced(betVal); // Emit signal to update the display
        emit balanceUpdated(balance); //Emit signal to update the balance
    }
    else {
        emit actionError("Please choose a valid bet!");
    }
}
void User::clearBet() {
    balance += betVal;  // Add the bet amount back to the balance
    betVal = 0;         // Reset the bet amount to zero
    emit betPlaced(betVal); // Emit signal to update the UI
    emit balanceUpdated(balance); // Emit signal to update balance display if you have that signal
}
