// Exercise 9.24: Hand.cpp
// Hand class member-function definitions
#include <iostream>
#include "Hand.h"
using namespace std;

// explicit constructor
Hand::Hand( DeckOfCards& D ){
    deal(D); // deal cards from the deck(D) to the hand
}

// deal HandSize cards from the deck to the hand
void Hand::deal( DeckOfCards& D ){
    for( auto& card: hand ) // for each card in hand
        card = D.dealCard(); // set card to the hand | card=D.dealCard(); == hand[cardIndex]=D.dealCard();
}

// show possible plays
void Hand::show(){
    for( const auto& card : hand ) // for each card in hand
        cout << card.toString() << endl; // print hand of cards

    // print possible plays
    cout << "\nThe hand contains high card"
         << ( pair() ? ", a pair" : "" )
         << ( pairs() ? ", two pairs" : "" )
         << ( three() ? ", three of a kind" : "" )
         << ( four() ? ", four of a kind" : "" )
         << ( flush() ? ", flush" : "" )
         << ( straight() ? ", straight" : "" ) << endl << endl;

    // relevance of the cards
    /*cout << "Relevance of the cards: \n\n";
    for( int i{}; i<HSIZE; i++){
        cout << i << ": " << cardRelevance[i] << endl;
    }*/
}

bool Hand::pair(){
    for( size_t i{}; i<HSIZE-1; ++i )
        for( size_t j{i+1}; j<HSIZE; ++j )
            if( hand[i].getFace() == hand[j].getFace() ){ // if a pair is found
                // the relevance of these cards is going to be added in the functions pairs()
                return true;
            }
    return false;
}

bool Hand::pairs(){
    short counter[FSIZE]{};
    bool found{}; // false by default

    for( size_t card{}; card<HSIZE; ++card ){ // for each card in hand
        if (++counter[hand[card].getFace()] == 2) // increment the counter face of each card till find a pair
            if(found){
                for( size_t cardi{}; cardi<HSIZE; ++cardi)
                    if( hand[cardi].getFace() == hand[card].getFace() )
                        ++cardRelevance[cardi]; // increment the relevance of a pair card
                return true;    // second pair found -> end
            } else{
                for( size_t cardi{}; cardi<HSIZE; ++cardi)
                    if( hand[cardi].getFace() == hand[card].getFace() )
                        ++cardRelevance[cardi]; // increment the relevance of a pair card
                found = true;   // first pair found -> continue
            }
    }

    return false; // no pairs found
}

bool Hand::three(){
    short counter[FSIZE]{};
    for( size_t card{}; card<HSIZE; ++card ) // for each card in hand
        if( ++counter[hand[card].getFace()] == 3 ) {// increment the counter face of each card till find? a third of cards
            for( size_t cardi{}; cardi<HSIZE; cardi++ )
                if( hand[cardi].getFace() == hand[card].getFace() )
                    ++cardRelevance[cardi]; // increment the relevance of the three card
            return true; // third of cards found
        }
    return false; // no third of cards found
}

bool Hand::four(){
    short counter[FSIZE]{};
    for( size_t card{}; card<HSIZE; ++card ) // for each card in hand
        if ( ++counter[hand[card].getFace()] == 4 ) {// increment the counter face of each card till find? a fourth of cards
            for( size_t cardi{}; cardi<HSIZE; cardi++ )
                if( hand[cardi].getFace() == hand[card].getFace() )
                    ++cardRelevance[cardi]; // increment the relevance of the fourth card
            return true; // fourth of cards found
        }
    return false; // no fourth of cards found
}

bool Hand::flush(){
    for ( size_t card{}; card<HSIZE-1; ++card )
        if( hand[card].getSuit() != hand[card+1].getSuit() )
            return false; // no flush found

    for( size_t card{}; card<HSIZE; card++ )
        ++cardRelevance[card]; // increment the relevance of the flush card
    return true; // flush found -> all the cards has the same suit
}

bool Hand::straight(){
    bool f[FSIZE]{};
    for( size_t card{}; card<HSIZE; ++card ) // for each card in hand
        f[hand[card].getFace()] = true; // tick the faces that match with the cards in hand
    for( size_t i{}; i<=FSIZE-HSIZE; ++i )
        if( f[i] && f[i+1] && f[i+2] && f[i+3] && f[i+4] ) { // check if there is a straight play
            for( size_t cardi{}; cardi<HSIZE; cardi++ )
                ++cardRelevance[cardi]; // increment the relevance of the straight card
            return true; // straight play found
        }
    return false; // no straight play found
}

Card Hand::getHighestCard(){
    size_t maximum{0};
    size_t face{0}; // assume 0 is the highest face

    for( size_t card{}; card<HSIZE; card++ ){
        if( hand[card].getFace() < 12 && hand[card].getFace()>face){ // 11 highest card -> king
            face = hand[card].getFace();
            maximum = card;
        }
    }

    return hand[maximum]; // return highest card
}

void Hand::changeCardsDiler( DeckOfCards& D ){
    for( size_t card{}, counter{}; card<HSIZE && counter<3; card++ ) // only 3 cards for exchange are allowed
        if( cardRelevance[card] == 0 ){
            // analise if this card could be use for a potential move ???

            hand[card] = D.dealCard(); // change card for a new one
            counter++;
        }
}

void Hand::changeCardsPlayer( DeckOfCards& D ){
    int id{}, counter{};
    cout << "Enter the index of the card that you want to change (-1) to finish";

    while( counter<3 ){
        cout << "\nid: ";
        cin >> id;
        if( id>=0 && id<5 ){
            hand[id] = D.dealCard(); // change card for a new one
            counter++;
        } else
            break;
    }
}
