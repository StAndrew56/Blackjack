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
/* Ignore, might be useful code for later
bool sortBySuit(Cards firstC, Cards secondC){
    return(firstC.suit < secondC.suit);
}
bool sortByRank(Cards firstC, Cards secondC){
    return(firstC.cardRank < secondC.cardRank);
}
*/

Dealer::Dealer() {
    mainDeck.createDeck();  // Create the deck of cards
    mainDeck.shuffle();     // Shuffle the deck
}

//Player count never goes above maximum size of vector array ..vector<Cards> mainDeck
void Dealer::dealCards(vector<Cards>& playerHand, vector<Cards>& deck) {
    //Adds a card to each hand twice
    for(int i = 0; i < 2; i++){
        addCard(playerHand, deck);
        //Needs face up & face down visual feature implementation
        //2nd dealer card face down
        //if(i == 0){
        addCard(dealerHand, deck);
        //}
        //if(i == 1){}
    }
}
/**
 * @param Player player
 * @param double amount
 * @return return void
 */
/*May not be needed
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

void Dealer::getUserHandVal(User user) {
    UserHandVal = user.getUserHandTotal();
}
//May not be needed either
//void Dealer::setUserHandVal() {

//}
void Dealer::hit(vector<Cards>& deck){
    addCard(dealerHand, deck);
}

void Dealer::stand(){
    //UI stuff maybe
}
void Dealer::compareCards(vector<Cards>& playerHand, vector<Cards>& deck, User& user){
    //User wins
    if(user.getUserHandTotal() > dealerHandVal){
        user.pay();
    }
    //A tie
    if(user.getUserHandTotal() == dealerHandVal){
        //pay back with no extra, clearBet() does this
        user.clearBet();
    }
    //User loses
    if(user.getUserHandTotal() < dealerHandVal){
        //sets betVal to 0 to clear bet
        //to update without returning bet to balance
        user.betVal = 0;
        user.clearBet();
    }
}
//Dealer's turn loop, called through UI triggered by user choosing "stand"
void Dealer::gameLoop(vector<Cards>& playerHand, vector<Cards>& deck, User& user){
    //Dealer play
    cout << "Dealer's turn";
    //Facedown card faceup, needs ui implementation --------- NEEDS DISCUSSION!!!!
    //Check Dealer val
    if(dealerHandVal < 21){
        //While loop{
        bool dealerTurn = true;
        while(dealerTurn){
            //Check if Dealer did not bust
            if(dealerHandVal < 21){
                //If Dealer val >= 17 then stand
                if(dealerHandVal >= 17){
                    //end Dealer's turn
                    stand();
                    dealerTurn = false;
                }
                //Else Dealer takes a card
                if(dealerHandVal < 17){
                    hit(deck);
                }
            }
            //If Dealer busts
            else{
                user.pay();
            }
        }
    }
    //Compare card values
    compareCards(playerHand, deck, user);
    //Reset Dealer's hand
    removeCards();
}

//Ignore, but might have useful code for later
/*
void Dealer::gameLoop(vector<Cards>& playerHand, vector<Cards>& deck, User& user){
    //While(turns<=turn amount || a currency is empty){
    while(user.balance > 0){
        //Deal initial 2 cards each
        dealCards(playerHand, deck);
        //Signal User turn ----------------------------------------- NEEDS DISCUSSION!!!!
        //If val >= 9 && val <= 11 then "DoubleDown" available
        if(user.getUserHandTotal() >= 9 && user.getUserHandTotal() <= 11){

        }
        //Copy vector of hand to sort
        vector<Cards>temp (playerHand);
        //Sort by suit
        sort(temp.begin(), temp.end(), sortBySuit);
        //If 2 with a suit similarity "Split" becomes available
        bool match = false;
        for(int i = 0; i < temp.size(); i++){
            if(temp[i].suit == temp[i+1].suit){
                match = true;
            }
        }
        //Sort by rank
        sort(temp.begin(), temp.end(), sortByRank);
        //If 2 with a suit similarity "Split" becomes available
        for(int i = 0; i < temp.size(); i++){
            if(temp[i].suit == temp[i+1].suit){
                match = true;
            }
        }
        //Suit availability --------- NEEDS DISCUSSION!!!!
        //while player's turn{
        while(user.getUserHandTotal() < 21){
            string userChoice = "";
            //Get User choice
            //If "Stand" no addCard called
            if(userChoice == "Stand"){
                //user's turn ends
            }
            if(userChoice == "Hit"){
                //user's turn ends
                addCard(playerHand, deck);
            }
            //If "Hit" then call addCard
            //If "Hit" check User val
            //If under 21 signal User play
            //If over 21 User loses bet
        //}
        }

        //Dealer play
        //Facedown card faceup, needs ui implementation --------- NEEDS DISCUSSION!!!!
        //Check Dealer val
        if(dealerHandVal < 21){
            //While loop{
            bool dealerTurn = true;
            while(dealerTurn){
                //If Dealer val >= 17 then stand
                if(dealerHandVal >= 17){
                    //end Dealer's turn
                    dealerTurn = false;
                }
                //Else Dealer takes a card
                if(dealerHandVal < 17){
                    addCard(dealerHand, deck);
                }
            //}
            }
        }
        //Compare card values
        user.pay();
        removeCards();
    //}
    }
}
*/
