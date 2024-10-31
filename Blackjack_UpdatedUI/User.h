/**
 * Project Untitled
 */


#ifndef _USER_H
#define _USER_H

#include "Deck.h"
#include "Cards.h"
#include "Suit.h"
#include <iostream>
#include <string>
#include <QString>
#include <QObject>

using namespace std;

class User : public QObject{
    Q_OBJECT
public:

    int handVal;
    vector<Cards> userHand;
    double betVal;
    double balance = 1000;
    vector<Cards> splitHand;
    int splitBetVal;

User();

void printRankUser(Rank cardRank);

void printSuitUser(Suit suit);

void printUserHand();

void printUserSplitHand();

void doubleDown();

void hit(Deck& deck);

void stand();

void split();

void placeBet(int bet);

void printUserHandTotal();

void pay();

void clearUserHand();

int getUserHandTotal();

void trueRank();

void takeBet();

void submitBet(int bet);

void increaseBet(int amount);

void clearBet();

signals:

void actionError(const QString &message);

void betPlaced(int bet);

void balanceUpdated(int newBalance);
};

#endif //_USER_H
