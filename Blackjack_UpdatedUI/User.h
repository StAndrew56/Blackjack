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
    double balance = 0;
    vector<Cards> splitHand;
    int splitBetVal;
    int aceCount = 0;
    int splitHandVal = 0;
    int initalBet = 0;



    User();

    void printRankUser(Rank cardRank);

    void printSuitUser(Suit suit);

    void printUserHand();

    void printUserSplitHand();

    void doubleDown();
    void doubleDownSplit();

    void hit(Deck& deck);

    void stand();

    void split();

    void blackJack();

    void placeBet(int bet);

    void printUserHandTotal();

    void pay();

    void clearUserHand();

    void bust();

    int getUserHandTotal();

    void trueRank();

    void takeBet();

    void submitBet(int bet);

    void increaseBet(int amount);

    void clearBet();

    void clearBetForStand();

    void displayUserHandVal();



    void hitSplit(Deck& deck);

    int getSplitHandTotal();
    int calculateHandTotal(vector<Cards>& hand);


signals:

void actionError(const QString &message);

void betPlaced(int bet);

void balanceUpdated(int newBalance);
void betUpdated(int newBet);
void updateUserHandVal(int val);
};

#endif //_USER_H
