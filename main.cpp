#include "Game.h"
#include "Deck.h"
#include "User.h"
#include "Cards.h"
#include "Suit.h"
#include "Game.h"
#include "Dealer.h"
#include <iostream>
#include <string>
using namespace std;




int main(){

    User user;
    bool flag = true;

    cout << "Welcome to Blackjack! Newest home of all your money!" << endl << endl;
    cout << "Want to try your luck? Type y for yes and n for no." << endl;
    char answer;
    cin >> answer;
    switch(answer){
        case 'n':
            flag = false;
            break;
        case 'N':
            flag = false;
            break;
        case 'y':
            flag = true;
            break;
        case 'Y':
            flag = true;
            break;
        default:
            flag = false;
            break;
    }

    while(flag){

        //creates the deck and shuffles
        Deck deck;
        deck.createDeck();
        deck.shuffle();
        //for testing
        deck.printDeck();

        cout << endl << endl;
        cout << "Your current Balance is: " << user.balance << endl << endl;
        cout << "Please wager your bet now!" << endl << endl;

        //takes the users bet
        user.takeBet();
        cout << endl << endl;
        //for testing bet
        cout << "New balance after bet: " << user.balance << endl << endl;
        bool lose;
        int result = 0;
        bool bust = false;
        while(!bust){
            lose = false;
            //deal 2 cards to player and dealer
            //also display them


            //-----------------------
            cout << "Type h to hit or s to stand. Anything else to quit game. Money will not be returned!" << endl;
            //-----------------------


            char hitOrStand;
            cin >> hitOrStand;


                switch(hitOrStand){

                    case 'h':
                        user.hit(deck);
                        cout << "Your hand is now: " << endl;
                        user.printUserHand();
                        cout << endl;
                        cout << "Your hand total is: ";
                        user.printUserHandTotal();
                        cout << endl << endl;
                        break;

                    case 'H':
                        user.hit(deck);
                        cout << "Your hand is now: " << endl;
                        user.printUserHand();
                        cout << endl;
                        cout << "Your hand total is: ";
                        user.printUserHandTotal();
                        cout << endl << endl;
                        break;

                    case 's'://this case makes it the next person/dealers turn
                        user.stand();
                        bust = true;
                        break;

                    case 'S'://this case makes it the next person/dealers turn
                        user.stand();
                        bust = true;
                        break;

                    default:

                        flag = false;
                        bust = true;
                        break;

                }
                //bust mechanic for user
                result = user.getUserHandTotal();
                if(result > 21){
                    bust = true;
                    lose = true;
                    break;
                }
                else if(result == 21){
                    bust = true;
                }
        }
        cout << endl;
        //determine winner here, and pay user if they won.
        //if user lost no action necessary.
        //------------------------
        if(result == 21){
            cout << "WOW 21! Beginners luck..." << endl;
        }
        else if(lose == false){
            user.pay();
            cout << "Congratulations you beat the dealer >.< We WONT let it happen again." << endl << endl;
            cout << "Your new balance after winning is: " << user.balance << endl;
        }
        else{
            cout << "Lookout! Big LOSER coming through!" << endl;
            cout << "Your new balance after losing is: " << user.balance << endl;
        }
        //------------------------
        user.clearUserHand();
        cout << "Another hand?" << endl;
        cout << "Type y for yes and n for no." << endl;

        char again;
        cin >> again;
        switch(again){
        case 'n':
            flag = false;
            break;
        case 'N':
            flag = false;
            break;
        case 'y':
            flag = true;
            break;
        case 'Y':
            flag = true;
            break;
    }
    }




    //dead testing zone...........

    //Deck deck;

    //deck.createDeck();
    //deck.shuffle();
    //deck.printDeck();



    //user.hit(deck);
    //cout << user.balance << endl;
    //cout << "before bet " << endl;
    //user.takeBet();

    //cout << "after bet " << endl;
    //cout << user.balance << endl;

    //deck.printDeck();
    //cout << endl;

    //cout << "now printing user hand";
    //user.printUserHand();
}
