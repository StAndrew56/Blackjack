#include "mainwindow.h"

#include <QApplication>

#include "Game.h"
#include "Deck.h"
#include "User.h"
#include "Cards.h"
#include "Suit.h"
#include "Game.h"
#include "Dealer.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWindow w;


    User user;
    Deck deck;
    deck.createDeck();
    deck.shuffle();
    Dealer dealer;//Creates Dealer object & starts game loop from there
    //Deals initial cards
    dealer.dealCards(user.userHand, deck.deckOfCards);
    bool test = true;
    //Actual
    while(user.balance > 0 && test == false){
        //User's turn
        //Button actions available
        //Dealer's turn
        dealer.gameLoop(deck.deckOfCards, user);
    }
    //Dealer test cases
    while(test == true){
        dealer.printDealerHand();
        //dealer.addCard(deck.deckOfCards);
        test = false;
    }

    w.show();
    return a.exec();
}
