/**
 * Project Untitled
 */


#ifndef _DEALER_H
#define _DEALER_H

#include "Deck.h" //For interaction with main Deck
#include "Cards.h" //To create a vector of cards as a Dealer's hand
#include "User.h" //To get User's hand value
#include <iostream>
#include <string>
#include <vector> //Dealer uses vectors

using namespace std;


class Dealer : public QObject{
    Q_OBJECT

private:
    int dealerHandVal;
    int userHandVal;
    vector<Cards> dealerHand; //Dealer's hand vector of cards
    int dealerAceCount = 0;
    Deck mainDeck;
    const int down = 1;
    const int up = 0;

public:



    Dealer(); //Constructor

    //TEXT OUTPUT MEMBER FUNCTIONS-----------------
    void printRankDealer(Rank cardRank);
    void printSuitDealer(Suit suit);
    void printDealerHand();
    void trueRank();
    //TEXT OUTPUT MEMBER FUNCTIONS-----------------

    //Param: User's hand, deck
    void dealCards(vector<Cards>& playerHand, vector<Cards>& deck, User* user);
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

    int getUserHandVal(User&);

    //void setUserHandVal();
    string compareCards(vector<Cards>& deck, User&);

    void gameLoop(vector<Cards>& deck, User&);

    string hit(vector<Cards>& deck);

    void stand();


    void bust(User& user);

    int getHandValue();
    bool hitIfNeeded(std::vector<Cards>& deck);

    vector<Cards>& getDealerHand();

    int getDealerHandVal() const;

    //For testing purposes
    void setDealerHandValue(int);



signals:
    void endGame();

};

#endif //_DEALER_H
