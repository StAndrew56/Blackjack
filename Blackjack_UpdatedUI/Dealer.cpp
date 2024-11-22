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
#include <QTimer>
#include <QMessageBox>
#include <QThread>

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
    mainDeck.createDeck();
    mainDeck.shuffle();
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
        else if(dealerHand[i].cardRank == Rank::ACE){
            dealerHandVal += 11;
        }
        else{
            dealerHandVal += (int)dealerHand[i].cardRank;
        }
    }
}
//TEXT OUTPUT MEMBER FUNCTIONS END--------------------------------------------

//Dealer deals cards - 1 to User then 1 to Dealer performed 2 times
void Dealer::dealCards(vector<Cards>& playerHand, vector<Cards>& deck, User* user)  {
    for(int i = 0; i < 2; i++){
        addCard(playerHand, deck);
        addCard(dealerHand, deck);
    }
        //Adds a card to each hand twice
        //do NOT remove, needed to deal with aces, will count num of
        //aces in playerHand off original deal.
        for(int i = 0; i < playerHand.size(); i++){

            if(playerHand[i].cardRank == Rank::ACE){
                user->aceCount++;
            }
            //case for 2 ace's dealt
            if(user->aceCount == 2){
                user->handVal -= 10;
                user->aceCount --;
                user->displayUserHandVal();
            }
        }
        //do Not remove, needed to deal with aces, will count num of
        //aces in dealerHand off original deal.
        for(int i = 0; i < dealerHand.size(); i++){

            if(dealerHand[i].cardRank == Rank::ACE){
                dealerAceCount++;
            }
            //case for 2 ace's dealt
            if(dealerAceCount == 2){
                dealerHandVal -= 10;
                dealerAceCount --;
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
    return user.getUserHandTotal();  // This ensures user's hand value is used accurately in comparisons
}
//May not be needed either
//void Dealer::setUserHandVal() {

//}

//Dealer hit
void Dealer::hit(vector<Cards>& deck) {
    if (deck.empty()) {
        qDebug() << "Error: Deck is empty, cannot hit!";
        return;
    }
    //qDebug() << "Dealer hitting, adding card from deck.";
    //qDebug() << "Dealer hand size after hit:" << dealerHand.size();

    //make sure dealer doesn't have 21
    if(dealerHandVal != 21){
        //add the card to dealerHand
        dealerHand.push_back(deck.front());
        //delete card from deckOfCards
        deck.erase(deck.begin());

        //get the index of dealerHand(where you just added the card)
        int lastCard = dealerHand.size() - 1;

        //add the last card's value to dealerHandVal
        if(dealerHand[lastCard].cardRank == Rank::JACK){
            dealerHandVal += 10;
        }
        else if(dealerHand[lastCard].cardRank == Rank::QUEEN){
            dealerHandVal += 10;
        }
        else if(dealerHand[lastCard].cardRank == Rank::KING){
            dealerHandVal += 10;
        }
        else if(dealerHand[lastCard].cardRank == Rank::ACE){
            dealerHandVal += 11;
            dealerAceCount++;//if ace add to ace counter, each ace will only be counted once.
        }
        else{
            dealerHandVal += (int)dealerHand[lastCard].cardRank;
        }

        //this block deals with ace's when nessecary. very dpendent on ace counter.
        //ace counter is above and in dealer class(in function dealCards()).
        if(dealerHandVal > 21){

                if(dealerHandVal != 21){

                    while(dealerHandVal > 21 && dealerAceCount > 0){

                        dealerHandVal -= 10;//turn the ace into a 1.

                        dealerAceCount--;//ace can't be decremented again.

                        if(dealerHandVal < 21){
                                return;
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



//Dealer stand
void Dealer::stand(){
    //Dealer's turn is going to end
    //UI stuff maybe
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
void Dealer::compareCards(vector<Cards>& deck, User& user) {
    int userHandValue = getUserHandVal(user);  // Get the user’s hand value for comparison

    qDebug() << "Comparing cards: User hand value:" << userHandValue << ", Dealer hand value:" << dealerHandVal;

    // User wins
    if (userHandValue > dealerHandVal || dealerHandVal > 21) {
        user.pay();
        qDebug() << "User wins. Balance updated.";
    }
    // Tie condition
    else if (userHandValue == dealerHandVal) {
        user.clearBetForStand();
        user.balance += user.betVal;
        qDebug() << "It's a tie. Bet cleared.";
    }
    // Dealer wins
    else {
        user.betVal = 0;
        user.clearBetForStand();  // Clear the bet with no payout
        qDebug() << "Dealer wins. Bet cleared, user loses.";
    }
}


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
                bust(user);
            }
        }
    }
    //Compare card values
    compareCards(deck, user);
    //Reset Dealer's hand
    removeCards();
}




int Dealer::getHandValue() {
    trueRank();  // Calculate the hand value
    return dealerHandVal;
}


void Dealer::displayDealerHandVal(){
    int val = getDealerHandVal();
    emit updateDealerHandVal(val);
}

int Dealer::getDealerHandSize() {
    return dealerHand.size();
}

vector<Cards>& Dealer::getDealerHand() {
    return dealerHand;
}

int Dealer::getDealerHandVal() const {
    return dealerHandVal;
}
void Dealer::setDealerHandVal(int val){
    dealerHandVal = val;
}


