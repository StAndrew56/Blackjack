#include "dealerLogicTest.h"
#include "Dealer.h"
#include "User.h"
#include "Deck.h"

void TestDealerLogic::testDealer() {
    Dealer dealer;
    Deck deck;
    deck.createDeck();
    deck.shuffle();
    User user;
    //QCOMPARE(dealer.compareCards(2, 3), 5); // Expected: 5
    //QCOMPARE(logic.add(-1, 1), 0); // Expected: 0
}

void TestDealerLogic::testDealerCardCompare() {
    Dealer dealer; //Need
    Deck deck; //May not need based on params later
    deck.createDeck();
    deck.shuffle();
    User user; //Need

    dealer.setDealerHandValue(18);
    user.handVal = 19;
    // Expected: "User" (Means user wins round)
    QCOMPARE(dealer.compareCards(deck.deckOfCards, user), "User");

    dealer.setDealerHandValue(19);
    user.handVal = 19;
    // Expected: "Tie"
    QCOMPARE(dealer.compareCards(deck.deckOfCards, user), "Tie");

    dealer.setDealerHandValue(20);
    user.handVal = 19;
    // Expected: "Dealer" (Means user wins round)
    QCOMPARE(dealer.compareCards(deck.deckOfCards, user), "Dealer");
}
/*
void TestMyLogic::testAdd() {
    MyLogic logic;
    QCOMPARE(logic.add(2, 3), 5); // Expected: 5
    QCOMPARE(logic.add(-1, 1), 0); // Expected: 0
}

void TestMyLogic::testIsPalindrome() {
    MyLogic logic;
    QVERIFY(logic.isPalindrome("radar")); // True for palindrome
    QVERIFY(!logic.isPalindrome("hello")); // False for non-palindrome
}
*/
// Run the test
QTEST_MAIN(TestDealerLogic)
//#include "dealerLogicTest.moc"

//If user variables become private variables,
//test values will need set functions.
//May change first few cards of deckOfCards vector instead later.
