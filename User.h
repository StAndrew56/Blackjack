/**
 * Project Untitled
 */


#ifndef _USER_H
#define _USER_H

class User {
public: 
    void int handVal;
    void double betVal;
    void double balance;
    
/**
 * @param int handVal
 * @param double balance
 */
void User(void int handVal, void double balance);
    
/**
 * @param int handVal
 */
void void hit(void int handVal);
    
void void stand();
    
/**
 * @param int handVal
 * @param double balance
 */
void void split(void int handVal, void double balance);
    
/**
 * @param double balance
 */
void void placeBet(void double balance);
    
/**
 * @param int handVal
 */
return int int userHandTotal(void int handVal);
    
/**
 * @param double balance
 */
void void pay(void double balance);
    
/**
 * @param double balance
 */
void void take(void double balance);
};

#endif //_USER_H