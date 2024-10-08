/**
 * Project Untitled
 */
using namespace std;
#include <iostream>
#include "Suit.h"

string toString(Suit suit){//string of the suit.

    switch(suit){//takes arg of suit.

        case Suit::Hearts:

            return "Hearts";

        case Suit::Spades:

            return "Spades";


        case Suit::Clubs:

            return "Clubs";

        case Suit::Diamonds:

            return "Diamonds";

        default://default named flag if suit isn't one of 4 above.

            return "flag";

    }
}
