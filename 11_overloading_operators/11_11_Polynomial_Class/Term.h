// Exercise 11.11: Term.h
// Term class declaration

#ifndef TERM_H
#define TERM_H

#include <iostream>
using namespace std;

class Term{

    friend istream &operator>>( istream &, Term & ); // input overloading
    friend ostream &operator<<( ostream &, const Term & ); // output overloading

public:
    explicit Term(const int = 0, const int = 0 ); // explicit constructor

    void setCoefficient( const int ); // set coefficient value
    void setExponent( const int ); // set exponent value

    int getCoefficient() const; // return coefficient value
    int getExponent() const; // return exponent value

    const Term &operator=( const Term &); // overload assigment operator

private:
    int coefficient;
    int exponent;
    const string variable = "x"; // just one variable for this exercise
};

#endif //TERM_H
