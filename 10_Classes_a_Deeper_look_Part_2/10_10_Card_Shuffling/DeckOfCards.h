// Exercise 9.23: DeckOfCards.h
// Member functions defined in DeckOfCards.cpp
#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include "Card.h"

static const size_t DSIZE{ FSIZE*SSIZE }; // 52 cards
static const size_t HSIZE{5}; // hand size -> cards per hand

class DeckOfCards{
public:
    DeckOfCards(); // default constructor
    void shuffle();
    Card dealCard(); // return the next deal card
    bool moreCards() const;

private:
    Card deck[DSIZE];
    int currentCard;
};

#endif //DECKOFCARDS_H
