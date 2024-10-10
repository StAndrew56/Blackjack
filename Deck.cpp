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
using namespace std;

/**
 * Deck implementation
 */


Deck::Deck() {

}

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

            deckOfCards[index] = card;

        }
    }


}

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

//this is not the actual main it is for testing the class only.
int main(){




    Deck deck;

    deck.createDeck();

    cout << endl;

    deck.printDeck();

    deck.shuffle();
    cout << endl;
    cout << endl;
    cout << "----------------------------------------------------------------" <<endl;
    cout << "After Shuffling the Deck, This is the order," << endl;
    cout << "First line is the first card in the array that makes up the deck" << endl;
    cout << "----------------------------------------------------------------" << endl;
    deck.printDeck();

}
