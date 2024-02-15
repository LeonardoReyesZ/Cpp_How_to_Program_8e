// Fig 11.17: Hugeint.h
// HugeInt class definition
#ifndef INC_12_WRAP_UP_11_HUGEINT_H
#define INC_12_WRAP_UP_11_HUGEINT_H

#include <iostream>
#include <string>
using namespace std;


class HugeInt{

    friend ostream &operator<<( ostream &, const HugeInt & );

public:
    static const int digits = 30; // maximum digits in a HugeInt

    HugeInt( long = 0 ); // conversion/default constructor
    HugeInt( const string & ); // conversion constructor

    int leadingZeros() const; // get the number of leading zeros

    /*** Unary Operators  ***/
    HugeInt &operator++(); // prefix increment operator

    /*** Assigment Operators  ***/
    const HugeInt &operator-=( const HugeInt & ); // subtract, modify the object
    const HugeInt &operator-=( int ); // subtract, modify the object
    const HugeInt &operator-=( const string & ); // subtract, modify the object

    const HugeInt &operator*=( const HugeInt & ); // subtract, modify the object
    const HugeInt &operator*=( int );   // subtract, modify the object
    const HugeInt &operator*=( const string &); // subtract, modify the object

    /*** Arithmetic Operators  ***/
    // addition operator; HugeInt+HugeInt
    HugeInt operator+( const HugeInt & ) const;
    // addition operator; HugeInt+int
    HugeInt operator+( int ) const;
    // addition operator;
    // HugeInt + string that represents large integer value
    HugeInt operator+( const string & ) const;

    // subtraction operator; HugeInt-HugeInt
    HugeInt operator-( const HugeInt & ) const;
    // subtraction operator; HugeInt-int
    HugeInt operator-( int ) const;
    // subtraction operator; HugeInt-string
    HugeInt operator-( const string & ) const;

    // multiplication operator; HugeInt*HugeInt
    HugeInt operator*( const HugeInt & ) const;
    // multiplication operator; HugeInt*int
    HugeInt operator*( int ) const;
    // multiplication operator; HugeInt*string
    HugeInt operator*( const string & ) const;

    // division operator HugeInt/HugeInt
    HugeInt operator/( const HugeInt & ) const;
    // division operator HugeInt/int
    HugeInt operator/( int ) const;
    // division operator HugeInt/string
    HugeInt operator/( const string & ) const;

    /*** relational operators ***/
    bool operator==( const HugeInt & ) const;
    bool operator==( int ) const;
    bool operator==( const string & ) const;

    bool operator!=( const HugeInt & ) const;
    bool operator!=( int ) const;
    bool operator!=( const string & ) const;

    bool operator<( const HugeInt & ) const;
    bool operator<( int ) const;
    bool operator<( const string & ) const;

    bool operator>( const HugeInt & ) const;
    bool operator>( int ) const;
    bool operator>( const string & ) const;

    bool operator<=( const HugeInt & ) const;
    bool operator<=( int ) const;
    bool operator<=( const string & ) const;

    bool operator>=( const HugeInt & ) const;
    bool operator>=( int ) const;
    bool operator>=( const string & ) const;

private:
    short integer[digits];
}; // end class HugeInt

#endif //INC_12_WRAP_UP_11_HUGEINT_H