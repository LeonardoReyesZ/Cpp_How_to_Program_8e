// Exercise 9.23: DeckOfCards.cpp
// DeckOfCards class member-function definitions
#include <ctime>
#include <random>
#include "DeckOfCards.h"
using namespace std;

default_random_engine generator{static_cast<unsigned>( time(0)) };

// constructor
DeckOfCards::DeckOfCards() : currentCard(0){
    for( size_t f{}; f<FSIZE; ++f )
        for( size_t s{}; s<SSIZE; ++s )
            deck[currentCard++] = Card{ Face(f), Suit(s) }; // set the card value to the deck
    currentCard = 0;
}

void DeckOfCards::shuffle(){
    uniform_int_distribution<int> uid{currentCard,DSIZE-1 }; // uniform probability distribution

    for( int card{currentCard}; card<DSIZE; ++card ){
        const int RAND{ uid(generator) };

        const Card TEMP{ deck[card] }; // hold the value of deck[card]
        deck[card] = deck[RAND]; // change the value
        deck[RAND] = TEMP; // set the hold value
    }
}

// return the next deal card
Card DeckOfCards::dealCard(){
    if( moreCards() ) // if there are still cards left in the deck
        return deck[currentCard++]; // deal next card
    else throw( "invalid card" );
}

bool DeckOfCards::moreCards() const {
    return currentCard<DSIZE; // if there are still cards left in the deck
}