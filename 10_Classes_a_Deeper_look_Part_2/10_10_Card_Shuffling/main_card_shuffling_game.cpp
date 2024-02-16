// Exercise 10.14:
// Card Shuffling, Dealing and simulate a game
#include <iostream>
#include "Hand.h"
using namespace std;

bool betterHand( Hand&, Hand&);

int main(){
    DeckOfCards deck; // create de deck of cards
    deck.shuffle(); // shuffle deck

    Hand dealer( deck ); // deal 5 cards to the dealer
    Hand player( deck ); // deal 5 cards to the player

    cout << "\nDealer's hand: " << endl;
    dealer.show(); cout << endl;
    cout << "Player's hand: " << endl;
    player.show(); cout << endl;

    cin.get(); // pause
    dealer.changeCardsDiler(deck); // change useless cards
    cout << "Dealer's hand: " << endl;
    dealer.show(); cout << endl;

    player.changeCardsPlayer(deck); // change useless cards
    cout << "\nPlayer's hand: " << endl;
    player.show(); cout << endl;

    // determine the winner
    cout << endl << (betterHand(dealer, player) ? "Dealer" : "Player")
        << " has the best hand " << endl;


    return 0;
}

/*****  Definition Of Functions   *************************************************************************/
// function to compare two hands and determine which is better
bool betterHand( Hand& player1, Hand& player2){
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

    if( player1.getHighestCard().getFace() > player2.getHighestCard().getFace() )
        return true;
    else if( player2.getHighestCard().getFace() > player1.getHighestCard().getFace() )
        return false;
}