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
    dealer.gameLoop(user.userHand, deck.deckOfCards);


    w.show();
    return a.exec();
}
