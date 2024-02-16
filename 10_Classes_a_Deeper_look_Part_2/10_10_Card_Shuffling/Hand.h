// Exercise 9.24: Hand.h
// Member functions defined in Hand.cpp
#ifndef HAND_H
#define HAND_H

#include "DeckOfCards.h"

class Hand{
public:
    explicit Hand( DeckOfCards& ); // explicit constructor
    void deal( DeckOfCards& ); // deal cards from the deck to the hand
    void show(); // show hand of cards
    void changeCardsDiler( DeckOfCards& ); // evaluate and change dialer's useless cards
    void changeCardsPlayer( DeckOfCards& ); // evaluate and change player's useless cards
    Card getHighestCard();

    // functions to find possible plays
    bool pair();
    bool pairs();
    bool three();
    bool four();
    bool flush();
    bool straight();

private:
    Card hand[HSIZE]; // create the hand of HandSize cards
    int cardRelevance[HSIZE]{0}; // array of int to identify te relevance of each card in the hand
};

#endif //HAND_H
