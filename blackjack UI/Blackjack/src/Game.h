/**
 * Project Untitled
 */


#ifndef _GAME_H
#define _GAME_H

#include "Deck.h"
#include "User.h"
#include "Dealer.h"

#include <iostream>
#include <string>

using namespace std;

class Game {
public:
    Dealer dealer;
    User player;
    Deck deck;

void startGame();

void resetGame();

void playerTurn();

void dealerTurn();

void determineWinner();
};

#endif //_GAME_H
