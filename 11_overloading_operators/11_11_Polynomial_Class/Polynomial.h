// Exercise 11.11: Polynomial.h
// Polynomial class declaration

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Term.h"

class Polynomial{

    friend istream &operator>>( istream &, Polynomial & ); // input overloading
    friend ostream &operator<<( ostream &, const Polynomial &); // output overloading

public:
    explicit Polynomial( const int = 1 ); // constructor
    Polynomial( const Polynomial & ); // copy constructor
    ~Polynomial(); // destructor

    /* ~~~~~ Assigment Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    const Polynomial &operator=( const Polynomial &);
    const Polynomial &operator+=( const Polynomial &);
    const Polynomial &operator-=( const Polynomial &);
    const Polynomial &operator*=( const Polynomial &);

    /* ~~~~~ Arithmetic Operators ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    Polynomial operator+( const Polynomial & ) const;
    Polynomial operator-( const Polynomial & ) const;
    Polynomial operator*( const Polynomial & ) const;

private:
    void reduce(); // simplify and organize the expression

    Term *ptr; // pointer to use dynamic memory
    int size; // number of terms
};

#endif //POLYNOMIAL_H
