// Exercise 9.25: ex_09_25.cpp
// Card Shuffling, Dealing and determine best hand
#include <iostream>
#include "Hand.h"
using namespace std;

bool betterHand(const Hand&, const Hand&);

int main(){
    DeckOfCards deck; // create de deck of cards
    deck.shuffle(); // shuffle deck

    Hand player1( deck ); // deal 5 cards to the player1
    Hand player2( deck ); // deal 5 cards to the player2
    player1.show(); cout << endl;
    player2.show();

    cout << endl << (betterHand(player1,player2) ? "player1" : "player2")
         << " has the best hand" << endl;

    return 0;
}

/*****  Definition Of Functions   *************************************************************************/
// function to compare two hands and determine which is better
bool betterHand( const Hand& player1, const Hand& player2){
    if( player1.four() && !player2.four() )
        return true;
    else if( player2.four() && !player1.four() )
        return false;

    if( player1.flush() && !player2.flush() )
        return true;
    else if( player2.flush() && !player1.flush() )
        return false;

    if( player1.straight() && !player2.straight() )
        return true;
    else if( player2.straight() && !player1.straight() )
        return false;

    if( player1.three() && !player2.three() )
        return true;
    else if ( player2.three() && !player1.three() )
        return false;

    if( player1.pairs() && !player2.pairs() )
        return true;
    else if( player2.pairs() && !player1.pairs() )
        return false;

    if( player1.pair() && !player2.pair() )
        return true;
    else if ( player2.pair() && !player1.pair() )
        return false;
}