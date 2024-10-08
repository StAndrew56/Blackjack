/**
 * Project Untitled
 */


#ifndef _USER_H
#define _USER_H

#include <iostream>
#include <string>

using namespace std;

class User {
public:
    int handVal;
    double betVal;
    double balance;

User();

void hit();

void stand();

void split();

void placeBet();

/**
 * @param int handVal
 */
int userHandTotal();

void pay();

void take();
};

#endif //_USER_H
