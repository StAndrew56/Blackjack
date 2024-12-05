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
    w.setWindowTitle("Blackjack");


    User user;
    Deck deck;
    deck.createDeck();
    deck.shuffle();



    w.show();
    return a.exec();
}
