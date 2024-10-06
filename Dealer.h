/**
 * Project Untitled
 */


#ifndef _DEALER_H
#define _DEALER_H

class Dealer {
public: 
    void int dealerHandVal;
    void Cards card;
    void int UserHandVal;
    
/**
 * @param int dealerHandVal
 * @param Cards card
 */
void Dealer(void int dealerHandVal, void Cards card);
    
/**
 * @param Cards card
 */
void void dealCards(void Cards card);
    
/**
 * @param Player player
 * @param double amount
 */
return void void pay(void Player player, void double amount);
    
/**
 * @param Cards card
 */
void void removeCards(void Cards card);
    
/**
 * @param Cards card
 */
void void addCard(void Cards card);
    
/**
 * @param Cards card
 */
int int getUserHandVal(void Cards card);
    
/**
 * @param Cards card
 */
void void setUserHandVal(void Cards card);
};

#endif //_DEALER_H