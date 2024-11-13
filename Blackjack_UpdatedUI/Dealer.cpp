/**
 * Project Untitled
 */

#include "Dealer.h"
#include "Deck.h" //For interaction with main Deck
#include "User.h" //For interaction with user hand vector
//#include <algorithm> //For sort()
#include <iostream>

//Qt UI includes
#include <QString>
#include <QObject>

using namespace std;

/**
 * Dealer implementation
 */
/* Ignore, may be useful later if using sort() function --- FOR SORTING HANDS
 * Sorting hands may be best for finding similar suits or ranks
 * by putting same suits or ranks next to each other
 *
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
//TEXT OUTPUT MEMBER FUNCTIONS START------------------------------------------
//prints the cards rank.
void Dealer::printRankDealer(Rank cardRank){

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
void Dealer::printSuitDealer(Suit suit){

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
//called when you want to print the Dealer's hand.
//this will not convert the hand to int.
void Dealer::printDealerHand(){

    for(int i = 0; i < dealerHand.size(); i++){
        printRankDealer(dealerHand[i].cardRank);
        cout << " of ";
        printSuitDealer(dealerHand[i].suit);
        cout << endl;
    }

}

//called when you want to set the trueRank of the Dealer's hand.
void Dealer::trueRank(){
    dealerHandVal = 0;
    for(int i = 0; i < dealerHand.size(); i++){

        if(dealerHand[i].cardRank == Rank::JACK){
            dealerHandVal += 10;
        }
        else if(dealerHand[i].cardRank == Rank::QUEEN){
            dealerHandVal += 10;
        }
        else if(dealerHand[i].cardRank == Rank::KING){
            dealerHandVal += 10;
        }
        else{
            dealerHandVal += (int)dealerHand[i].cardRank;
        }
    }
}
//TEXT OUTPUT MEMBER FUNCTIONS END--------------------------------------------

//Dealer deals cards - 1 to User then 1 to Dealer performed 2 times
void Dealer::dealCards(vector<Cards>& playerHand, vector<Cards>& deck, User* user) {
    //Adds a card to each hand twice
    for(int i = 0; i < 2; i++){
        addCard(playerHand, deck);
        //Needs face up & face down visual feature implementation
        //2nd dealer card face down
        if(i == 0){
        addCard(dealerHand, deck);
        }
        if(i == 1){
            addCard(dealerHand, deck);
            //Toggle card face down here
            ////emit toggleCardImage(down);
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
}
/**
 * @param Player player
 * @param double amount
 * @return return void
 */
/*May not be needed due to User object having member function pay()
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

int Dealer::getUserHandVal(User& user) {
    userHandVal = user.getUserHandTotal();
}
//May not be needed either
//void Dealer::setUserHandVal() {

//}

string Dealer::handState(){
    if(dealerHandVal >= 17){
        return "stand";
    }
    else if(dealerHandVal < 17){
        return "hit";
    }
    else{
        return "----INCORRECT VALUE IN HANDSTATE----";
    }
}

//Dealer hit
void Dealer::hit(vector<Cards>& deck){
    //Add card to Dealer's hand
    addCard(dealerHand, deck);
}

//Dealer stand - Function may be needed
//void Dealer::stand(){
    //Dealer's turn is going to end
    //UI stuff maybe
//}

bool Dealer::isBust(){
    if(dealerHandVal <= 21){
        return false;
    }
    else if(dealerHandVal > 21){
        return true;
    }
    //Should never run - but satisfies guarantee of return bool
    else{
        return true;
    }

}

//Dealer hand value is over 21
void Dealer::bust(User& user){
    //Dealer's turn is going to end
    //Dealer calls pay function to double bet val and add this to balance
    user.pay();
    //user.pay() should have betVal = 0 after adding to balance
    //user.pay() should have emit betPlaced(betVal);
    //user.pay() should have emit balanceUpdated(balance);

    //Dealer doesn't need to update these since
    //User already does this in other User member functions
}

//Card comparison - Which is closer to 21?
void Dealer::compareCards(vector<Cards>& deck, User& user){

    //User wins
    if(getUserHandVal(user) > dealerHandVal){
        //Dealer calls pay function to double bet val and add this to balance
        user.pay();
        //user.pay() should have betVal = 0 after adding to balance
        //user.pay() should have emit betPlaced(betVal);
        //user.pay() should have emit balanceUpdated(balance);

        //Dealer doesn't need to update these since
        //User already does this in other User member functions
    }

    //A tie
    if(getUserHandVal(user) == dealerHandVal){
        //pay back with no extra, clearBet() does this
        user.clearBet();
    }

    //User loses
    if(getUserHandVal(user) < dealerHandVal){
        //sets betVal to 0 to clear bet
        //to update without returning bet to balance
        user.betVal = 0;
        //clearBet() already emits for UI updates
        user.clearBet();
    }
}

//Dealer's turn loop, called through UI triggered by user choosing "stand"
//Parameters:
//----- deck to add cards to hands from deck - dealCards() & addCard()
//----- user to compare hands of Dealer & User, & to handle user pay result
void Dealer::gameLoop(vector<Cards>& deck, User& user){
    //Dealer play
    cout << "Dealer's turn";
    //Facedown card faceup, needs ui implementation --------- NEEDS DISCUSSION!!!!
    //Check Dealer val
    if(dealerHandVal < 21){
        bool dealerTurn = true;
        //Toggle card face up here
        ////emit toggleCardImage(up);
        //While loop for Dealer's turn until Dealer stands{
        while(dealerTurn){
            //Check if Dealer did not bust
            if(isBust() == false){
                //If Dealer val >= 17 then stand
                if(handState() == "stand"){
                    //end Dealer's turn
                    //stand(); //Function may be needed
                    dealerTurn = false;
                }
                //Else Dealer takes a card
                if(handState() == "hit"){
                    hit(deck);
                }
            }
            //If Dealer busts
            else{
                bust(user);
                dealerTurn = false;
            }
        }
    }
    if(isBust() == false){
        //Compare card values
        compareCards(deck, user);
    }
    else{
        //Who busted first?

    }
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
//Code for using sort() to sort hand temporarily
//for finding similar suits & ranks
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
//
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
