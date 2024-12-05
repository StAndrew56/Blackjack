/**
 * Project Untitled
 */

#include "Cards.h"
#include "Deck.h"
#include "Suit.h"

#include <chrono>
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

/**
 * Deck implementation
 */


Deck::Deck() {

}
//will create the create of 52 cards

void Deck::createDeck(){

    //iterate through all suits
    for(int i = (int)Suit::Hearts; i <=(int)Suit::Diamonds; i++){

        //iterate through all cardRanks(ace, two, three, etc...)
        for(int j =(int)Rank::ACE; j<=(int)Rank::KING; j++){

            Cards card;//create a card
            card.suit = (Suit)i;//give the card suit at i
            card.cardRank = (Rank)j;//give the card cardRank at j

            //if cardRank is jack,queen,king, set value to 10(this is blackjack specific)
            if(card.cardRank == Rank::JACK){
                card.value = 10;
            }
            else if(card.cardRank == Rank::QUEEN){
                card.value = 10;
            }
            else if(card.cardRank == Rank::KING){
                card.value = 10;
            }
            //all other cards take the enum value which starts at 1 for ACE's.
            else{
                card.value = (int)card.cardRank;
            }
            //
            //cout << (int)card.cardRank << " of " << (int)card.suit << " it's value is " << card.value << endl;

            int index = (13 * i) + j - 1;

            deckOfCards.push_back(card);

        }
    }


}


 //FOR TESTING SPLIT
/*
void Deck::createDeck() {
    deckOfCards.clear();

    // Add specific test cards for the player at the top of the deck
    Cards playerCard1;
    playerCard1.suit = Suit::Hearts;
    playerCard1.cardRank = Rank::JACK;
    playerCard1.value = 6;

    Cards playerCard2;
    playerCard2.suit = Suit::Clubs;
    playerCard2.cardRank = Rank::JACK;
    playerCard2.value = 6;

    // Add specific cards for the dealer next
    Cards dealerCard1;
    dealerCard1.suit = Suit::Diamonds;
    dealerCard1.cardRank = Rank::ACE;
    dealerCard1.value = 10;

    Cards dealerCard2;
    dealerCard2.suit = Suit::Spades;
    dealerCard2.cardRank = Rank::ACE;
    dealerCard2.value = 10;

    // Push the test cards in the correct dealing order
    deckOfCards.push_back(playerCard1); // Player's first card
    deckOfCards.push_back(dealerCard1); // Dealer's first card
    deckOfCards.push_back(playerCard2); // Player's second card
    deckOfCards.push_back(dealerCard2); // Dealer's second card

    // Add the rest of the deck normally
    for (int suit = (int)Suit::Hearts; suit <= (int)Suit::Diamonds; ++suit) {
        for (int rank = (int)Rank::ACE; rank <= (int)Rank::KING; ++rank) {
            Cards card;
            card.suit = static_cast<Suit>(suit);
            card.cardRank = static_cast<Rank>(rank);
            card.value = (rank >= (int)Rank::JACK) ? 10 : rank;
            deckOfCards.push_back(card);
        }
    }

    shuffle();  // Shuffle the remaining cards (optional, but useful for testing)
}
*/


//called when you want to print the suit of the card.
void Deck::printSuit(Suit suit){

    if(suit == Suit::Hearts){
        cout << "Hearts";
    }
    else if(suit == Suit::Spades){
        cout << "Spades";
    }
    else if(suit == Suit::Clubs){
        cout << "Clubs";
    }
    else if(suit == Suit::Diamonds){
        cout << "Diamonds";
    }

}
void Deck::printCard(){
    for(int i = (int)Suit::Hearts; i <=(int)Suit::Diamonds; i++){

        //iterate through all cardRanks(ace, two, three, etc...)
        for(int j =(int)Rank::ACE; j<=(int)Rank::KING; j++){

            int index = (13 * i) + j - 1;

            printRank(deckOfCards[index].cardRank);
            cout << " of ";
            printSuit(deckOfCards[index].suit);
            cout << endl;

        }
    }
}
//called when you want to print the rank(int value as a string associated
//with the name of the card, Jack = Ten).
void Deck::printRank(Rank cardRank){

    if(cardRank == Rank::ACE){
        cout << "Ace";
    }
    else if(cardRank == Rank::TWO){
        cout << "Two";
    }
    else if(cardRank == Rank::THREE){
        cout << "Three";
    }
    else if(cardRank == Rank::FOUR){
        cout << "Four";
    }
    else if(cardRank == Rank::FIVE){
        cout << "Five";
    }
    else if(cardRank == Rank::SIX){
        cout << "Six";
    }
    else if(cardRank == Rank::SEVEN){
        cout << "Seven";
    }
    else if(cardRank == Rank::EIGHT){
        cout << "Eight";
    }
    else if(cardRank == Rank::NINE){
        cout << "Nine";
    }
    else if(cardRank == Rank::TEN){
        cout << "Ten";
    }
    else if(cardRank == Rank::JACK){
        cout << "Jack";
    }
    else if(cardRank == Rank::QUEEN){
        cout << "Queen";
    }
    else if(cardRank == Rank::KING){
        cout << "King";
    }
}
//prints the deck of cards.
void Deck::printDeck(){

    printCard();
}

//Shuffles the deck of cards. This implementation is modified version
//of the "Fisher-Yates" Shuffle algorithm.

void Deck::shuffle() {
    unsigned int seed = std::random_device{}() + static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());
    default_random_engine rng(seed);
    for(int i = 51; i > 0; i--){
        uniform_int_distribution<int> distribution(0, i);
        int j = distribution(rng);
        swap(deckOfCards[i], deckOfCards[j]);
    }
}




//FOR TESTING SPLIT
/*
void Deck::shuffle() {
    if (!testingMode) {
        std::random_shuffle(deckOfCards.begin(), deckOfCards.end());
    }
}
*/
void Deck::printSize(){
    cout << "Deck Size: " << deckOfCards.size();

}
void Deck::killDeck(){

    deckOfCards.clear();
    deckOfCards.shrink_to_fit();

}

//this is not the actual main it is for testing the class only.
//int main(){

   //Deck deck;

    //deck.createDeck();

    //cout << endl;

    //deck.printDeck();

    //deck.shuffle();
    //cout << endl;
    //cout << endl;
    //cout << "----------------------------------------------------------------" <<endl;
    //cout << "After Shuffling the Deck, This is the order," << endl;
    //cout << "First line is the first card in the vector that makes up the deck" << endl;
    //cout << "----------------------------------------------------------------" << endl;
    //deck.printDeck();

//}
