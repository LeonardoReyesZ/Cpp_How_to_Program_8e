// Exercise 9.23: Card.h
// Member functions defined in Card.cpp
#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

static const size_t FSIZE{13}; // Face size {A,2,3,4,5,6,7,8,9,10,J,Q,K}
static const size_t SSIZE{4};  // Suit size {Clubs, Diamonds, Hearts, Spades}

enum class Face{ Deuce, Three, Four, Five, Six, Seven, Eight,
                 Nine, Ten, Jack, Queen, King, Ace };
enum class Suit{ Clubs, Diamonds, Hearts, Spades };

static const string FACES[FSIZE]{
        "Deuce", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
static const string SUITS[SSIZE]{
        "Clubs", "Diamonds", "Hearts", "Spades" };

class Card{
public:
    explicit Card( const Face& = Face(0), const Suit& = Suit(0) ); // constructor default values
    string toString() const; // convert to string
    size_t getFace() const; // return face
    size_t getSuit() const; // return suit
private:
    size_t face;
    size_t suit;
};

#endif //CARD_H
