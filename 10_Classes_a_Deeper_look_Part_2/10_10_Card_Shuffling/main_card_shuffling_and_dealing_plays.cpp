// Exercise 9.24: ex_09_24.cpp
// Card Shuffling and Dealing
#include "Hand.h"
using namespace std;

int main() {
    DeckOfCards Deck; // Create deck of cards
    Deck.shuffle(); // shuffle the deck

    Hand Player{Deck}; // deal the cards to the player
    Player.show(); // show hand of cards of the player

    return 0;
}