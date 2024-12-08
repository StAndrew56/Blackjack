#include "dealerLogicTest.h"
#include "Dealer.h"
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

void TestDealerLogic::testDealerCardCompare() {
    Dealer dealer; //Need
    Deck deck; //May not need based on params later
    deck.createDeck();
    User user; //Need

    dealer.setDealerHandVal(18);
    user.handVal = 19;
    qDebug() << "Comparing cards: User hand value:" << user.handVal << ", Dealer hand value:" << dealer.getDealerHandVal();
    // Expected: "User" (Means user wins round)
    QCOMPARE(dealer.compareCards(deck.deckOfCards, user), "User"); //user.trueRank function is making this difficult

    dealer.setDealerHandVal(19);
    user.handVal = 19;
    // Expected: "Tie"
    QCOMPARE(dealer.compareCards(deck.deckOfCards, user), "Tie");

    dealer.setDealerHandVal(20);
    user.handVal = 19;
    // Expected: "Dealer" (Means user wins round)
    QCOMPARE(dealer.compareCards(deck.deckOfCards, user), "Dealer");
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
void TestDealerLogic::testDealerHit() {
    Dealer dealer;
    Deck deck;

    //Set up
    deck.createDeck(); //Creates deck cards
    int originalSize = dealer.getDealerHand().size(); //Should be 0 here
    string hitResult = dealer.hit(deck.deckOfCards); //Result of hit with deck containing cards
    //Test
    QCOMPARE(hitResult, "Hit"); //Expected: "Hit"
    if(hitResult == "Hit"){ //Tests Dealer's hand after
        QCOMPARE(dealer.getDealerHand().size(), originalSize+1);// Expected: 1
    }
    qDebug() << "Hit is successful";

    //Set up
    deck.killDeck(); //Makes deck empty
    dealer.removeCards(); //Makes Dealer's hand empty
    //Test
    QCOMPARE(dealer.hit(deck.deckOfCards), "Empty"); //Checks for deck empty response
    if(hitResult == "Hit"){ //Tests Dealer's hand after
        QCOMPARE(dealer.getDealerHand().size(), originalSize);//Expected: 0
    }
    qDebug() << "Hit refusal due to Deck empty is successful";
}

// Run the test
QTEST_MAIN(TestDealerLogic)
//#include "dealerLogicTest.moc"

//If user variables become private variables,
//test values will need set functions.
//May change first few cards of deckOfCards vector instead later.
