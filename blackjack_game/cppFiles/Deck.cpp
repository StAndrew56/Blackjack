/**
 * Project Untitled
 */
using namespace std;
#include <iostream>
#include <vector>

#include "Deck.h"

class Deck{
private:
    int cardCount = 0;
    Cards card;
public:
    //Declarations
    Deck(int cardCount, Cards card);
    void shuffle();
    int drawCard();
};

Deck::Deck(void int cardCount, void Cards card) {
    
}

/**
 * @return void
 */
void Deck::void shuffle() {
    return;
}

/**
 * @return int
 */
int Deck::int drawCard() {
    return 0;
}
