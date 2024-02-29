//  Exercise 11.10: Rational.h
//  Rational class declaration

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational{

    friend ostream &operator<<( ostream &, const Rational & ); // output overloading

public:
    Rational( int = 1, int = 1 ); // default constructor

    void reduce(); // simplify the fraction

    /* ~~~~~ Arithmetic Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    // addition operator+; Rational+Rational
    Rational operator+( const Rational & ) const;
    // addition operator; Rational+int
    Rational operator+( int ) const;

    // subtraction operator-; Rational-Rational
    Rational operator-( const Rational & ) const;
    // subtraction operator; Rational-int
    Rational operator-( int ) const;

    // multiplication operator*; Rational*Rational
    Rational operator*( const Rational & ) const;
    // multiplication operator; Rational*int
    Rational operator*( int ) const;

    // division operator/; Rational/Rational
    Rational operator/( const Rational & ) const;
    // division operator Rational/int
    Rational operator/( int ) const;

    /* ~~~~~ Relational Operators   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    bool operator==( const Rational & ) const;
    bool operator==( int ) const;

    bool operator!=(const Rational & ) const;
    bool operator!=( int ) const;

    bool operator<( const Rational & ) const;
    bool operator<( int ) const;

    bool operator>( const Rational & ) const;
    bool operator>( int ) const;

    bool operator<=( const Rational & ) const;
    bool operator<=( int ) const;

    bool operator>=( const Rational & ) const;
    bool operator>=( int ) const;

private:
    int numerator;
    int denominator;
};

#endif //RATIONAL_H
