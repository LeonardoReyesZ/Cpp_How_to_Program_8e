// Exercise 9.23: Card.cpp
// Card class member-function definitions
#include "Card.h"
using namespace std;

Card::Card( const Face& _face, const Suit& _suit ) {
    face = size_t(_face); // set face
    suit = size_t(_suit); // set suit
}

string Card::toString() const{
    return FACES[face] + " of " + SUITS[suit]; // return string data
}

size_t Card::getFace() const{ return face; }

size_t Card::getSuit() const{ return suit; }

