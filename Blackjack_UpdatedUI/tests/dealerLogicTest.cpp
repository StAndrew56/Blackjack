#include "dealerLogicTest.h"
#include "Dealer.h"
#include "User.h"
#include "Deck.h"
#include <vector>
#include <QTest>
#include <QString>
#include <QtTest>


void TestDealerLogic::testDealCards() {
    Dealer dealer;
    Deck deck;
    deck.createDeck();
    deck.shuffle();
    User user;

    dealer.dealCards(user.userHand, deck.deckOfCards, &user); // Deal the cards

    QCOMPARE(user.userHand.size(), 2); // Player should have 2 cards
    QCOMPARE(dealer.getDealerHand().size(), 2); // Dealer should have 2 cards
}

void TestDealerLogic::testDealerCardCompareWin() {
    Dealer dealer;
    Deck deck;
    deck.createDeck();
    User user;

    dealer.setDealerHandVal(18);
    user.handVal = 19;
    user.betVal = 100;
    user.balance = 900;
    //bool hasSplit = false;

    qDebug() << "Comparing cards: User hand value:" << user.handVal << ", Dealer hand value:" << dealer.getDealerHandVal();
    dealer.compareCards(deck.deckOfCards, user);
    // Expected: 1100
    QCOMPARE(user.balance, 1100);
}

void TestDealerLogic::testDealerCardCompareTie() {
    Dealer dealer;
    Deck deck;
    deck.createDeck();
    User user;

    dealer.setDealerHandVal(19);
    user.handVal = 19;
    user.betVal = 100;
    user.balance = 900;
    //bool hasSplit = false;

    qDebug() << "Comparing cards: User hand value:" << user.handVal << ", Dealer hand value:" << dealer.getDealerHandVal();
    // Expected: 1000
    dealer.compareCards(deck.deckOfCards, user);
    QCOMPARE(user.balance, 1000);
}

void TestDealerLogic::testDealerCardCompareLose() {
    Dealer dealer;
    Deck deck;
    deck.createDeck();
    User user;

    dealer.setDealerHandVal(20);
    user.handVal = 19;
    user.betVal = 100;
    user.balance = 900;

    qDebug() << "Comparing cards: User hand value:" << user.handVal << ", Dealer hand value:" << dealer.getDealerHandVal();
    dealer.compareCards(deck.deckOfCards, user);
    // Expected: 900
    QCOMPARE(user.balance, 900);
}




//QTEST_MAIN(TestDealerLogic)

