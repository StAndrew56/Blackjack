/**
 * Project Untitled
 */


#include "Cards.h"
#include "Deck.h"
#include "Suit.h"


#include <string>
#include <iostream>
#include <QString>
using namespace std;

/**
 * Cards implementation
 */

void Cards::getCardValue() {

}

void Cards::getSuit() {

}

void Cards::toString() {

}


QString Cards::getCardImagePath() const {
    // Follows card filenames like "suit_rank.png"
    QString suitStr;
    QString rankStr;

    // Convert suit enum to a string for png reasons
    switch (suit) {
    case Suit::Hearts:   suitStr = "hearts"; break;
    case Suit::Spades:   suitStr = "spades"; break;
    case Suit::Diamonds: suitStr = "diamonds"; break;
    case Suit::Clubs:    suitStr = "clubs"; break;
    }

    // Convert rank enum to a string for png reasons
    switch (cardRank) {
    case Rank::ACE:   rankStr = "A"; break;
    case Rank::TWO:   rankStr = "2"; break;
    case Rank::THREE: rankStr = "3"; break;
    case Rank::FOUR:  rankStr = "4"; break;
    case Rank::FIVE:  rankStr = "5"; break;
    case Rank::SIX:   rankStr = "6"; break;
    case Rank::SEVEN: rankStr = "7"; break;
    case Rank::EIGHT: rankStr = "8"; break;
    case Rank::NINE:  rankStr = "9"; break;
    case Rank::TEN:   rankStr = "10"; break;
    case Rank::JACK:  rankStr = "J"; break;
    case Rank::QUEEN: rankStr = "Q"; break;
    case Rank::KING:  rankStr = "K"; break;
    }

    // Construct the full image path with ":/cards/" prefix
    return QString(":/cards/%1_%2.png").arg(suitStr).arg(rankStr);
}
