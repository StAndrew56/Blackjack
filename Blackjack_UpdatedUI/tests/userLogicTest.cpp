#include "userLogicTest.h"
//#include "Dealer.h"
#include "User.h"
#include "Deck.h"

/*void TestDealerLogic::testDealer() {
    Dealer dealer;
    Deck deck;
    deck.createDeck();
    deck.shuffle();
    User user;
    //QCOMPARE(dealer.compareCards(2, 3), 5); // Expected: 5
    //QCOMPARE(logic.add(-1, 1), 0); // Expected: 0
}
*/

void TestUserLogic::testUserPlaceBet() {
    User user; //Need

    user.betVal = 0;
    qDebug() << "Comparing user bet value to expected";
    qDebug() << "Expected: 100";
    user.placeBet(100);
    qDebug() << "Got: " << user.betVal;
    QCOMPARE(user.betVal, 100);

    user.betVal = 0;
    qDebug() << "Expected: 0";
    user.placeBet(2000);
    qDebug() << "Got: " << user.betVal;
    QCOMPARE(user.betVal, 0);
}
/*
void TestDealerLogic::testDealerHandDelete() {
    Dealer dealer;
    // SET DEALER'S HAND HERE
    size_t startCapacity = dealer.getDealerHand().size();
    dealer.removeCards()
    QCOMPARE(dealer.getDealerHand().size(), size_t(0);// Expected: 0
    QVERIFY(dealer.getDealerHand().capacity()==0);// Expected: 0
}
*/
void TestUserLogic::testUserHit() {
    User user;
    Deck deck;

    //Set up - Hit
    deck.createDeck(); //Creates deck cards
    int originalSize = user.userHand.size(); //Should be 0 here
    user.handVal = 10; //To prevent trueRank() recalculation
    qDebug() << "User hand val(Before hit()): " << user.handVal;
    user.hit(deck); //Result of hit with deck containing cards & userHandVal < 21
    qDebug() << "User hand val: " << user.handVal;
    //Test
    QCOMPARE(user.userHand.size(), originalSize+1);// Expected: 1
    qDebug() << "Hit is successful";

    //Set up - 21
    //deck.killDeck(); //Makes deck empty
    user.clearUserHand(); //Makes User's hand empty & size 0
    originalSize = user.userHand.size(); //Should be 0 here
    user.handVal = 21; //handVal of 21 set
    qDebug() << "User hand val(Before hit()): " << user.handVal;
    user.hit(deck); //Result of hit function when user has 21
    qDebug() << "User hand val: " << user.handVal;
    //Test
    QCOMPARE(user.userHand.size(), originalSize);// Expected: 0
    qDebug() << "Stand due to 21 response message is successful";

    //Set up - deckEmpty
    /*
    deck.killDeck(); //Makes deck empty
    user.clearUserHand(); //Makes User's hand empty
    originalSize = user.userHand.size(); //Should be 0 here
    user.handVal = 20; //handVal of 20 set
    user.hit(deck); //Result of hit function when user has 21
    //Test
    QCOMPARE(user.userHand.size(), originalSize);// Expected: 0
    qDebug() << "Stand due to 21 response message is successful";
    //qDebug() << "Hit refusal due to Deck empty is successful";
*/
}

// Run the test
//QTEST_MAIN(TestUserLogic)
