#include "userLogicTest.h"
#include "Dealer.h"
#include "User.h"
#include "Deck.h"
#include <vector>
#include <QTest>
#include <QString>
#include <QtTest>


void TestUserLogic::testHit_AddCard(){

    Dealer dealer;
    Deck deck;
    deck.createDeck();
    deck.shuffle();
    User user;

    user.hit(deck);

    QCOMPARE(user.userHand.size(), 1); // one card should be added to user hand
    QCOMPARE(deck.deckOfCards.size(), 51); // one card removed from deck
}

void TestUserLogic::testIncreaseBet_Valid(){
    User user;
    user.balance = 1000;
    user.betVal = 0;
    int amount = 100;

    user.increaseBet(amount);

    QCOMPARE(user.betVal, 100); // bet should be increase from 0 to 100
    QCOMPARE(user.balance, 900); // balance should decrease by 100
}

void TestUserLogic::testIncreaseBet_NotValid(){
    User user;
    user.balance = 1000;
    user.betVal = 0;
    int amount = 10000;

    user.increaseBet(amount);

    QCOMPARE(user.betVal, 0); // bet should be rejected
    QCOMPARE(user.balance, 1000); // balance should not change
}

void TestUserLogic::testBlackJack(){
    User user;
    user.balance = 1000;
    user.betVal = 100;

    user.blackJack();

    QCOMPARE(user.balance, 1250); // balance should be 1250 after getting blackjack
}

void TestUserLogic::testDoubleDown(){
    User user;
    user.balance = 1000;
    int amount = 100;

    user.increaseBet(amount); // balance should decrease to 900 & betVal increases to 100
    user.doubleDown();

    QCOMPARE(user.balance, 800); // balance should decrease to 800
    QCOMPARE(user.betVal, 200); // betVal should increase to 200

}
