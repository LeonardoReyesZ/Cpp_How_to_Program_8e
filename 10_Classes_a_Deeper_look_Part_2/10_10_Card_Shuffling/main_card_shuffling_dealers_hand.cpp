// Exercise 10.13:
// Card Shuffling, Dealing and determine the dealer's hand

#include <iostream>
#include "Hand.h"
using namespace std;


int main(){
    DeckOfCards deck; // create de deck of cards
    deck.shuffle(); // shuffle deck

    Hand dealer( deck ); // deal 5 cards to the dealer

    cout << "Dealer's hand: " << endl;
    dealer.show(); cout << endl;

    dealer.changeCardsDiler(deck); // change useless cards
    dealer.show(); cout << endl;

    return 0;
}
