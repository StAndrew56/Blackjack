/**
 * Project Untitled
 */


#ifndef _CARDS_H
#define _CARDS_H

class Cards {
public: 
    void string suit;
    void int value;
    
/**
 * @param Suit s
 * @param int value
 */
void Cards(void Suit s, void int value);
    
int int getCardValue();
    
string string getSuit();
    
string string toString();
};

#endif //_CARDS_H