// Exercise 11.10: Rational.cpp
// Rational class member-function definitions
#include <stdexcept>
#include "Rational.h"
using namespace std;


/** =======  Constructors Definitions  =================== =========================================== ============= ======= */
// default constructor
Rational::Rational( int _numerator, int _denominator ){
    if( _denominator != 0 ){ // if is a valid fraction
        numerator = _numerator; // set the value
        denominator = _denominator; // set the value
        reduce(); // reduce the fraction
    }
    else
        throw invalid_argument("Fraction undefined");
} // end Rational default constructor


/** ==========  Member Function Definitions    ============= ======================= =========================== ============ */
// function to simplify the fraction
void Rational::reduce(){
    if (!numerator) return; // there is no point if the numerator is 0

    if (denominator < 0){ // exchange the negative sign to the numerator
        numerator *= -1;
        denominator *= -1;
    }

    int gcd{ abs(numerator) }; // int gcd = abs(numerator); -> same sentence
    int den{ abs(denominator) };

    while(gcd != den) gcd>den ? gcd-=den : den-=gcd; // find the greatest common divisor

    numerator /= gcd; // reduce numerator
    denominator /= gcd; // reduce denominator
} // end reduce


/** ============  Arithmetic Operators Definitions  ==== ============== ===================== ===================== ======== */
/* ~~~~ Addition Operator Definitions   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
// addition operator+; Rational+Rational
Rational Rational::operator+( const Rational &right ) const{
    Rational result; // object to save the result

    result.denominator = denominator * right.denominator; // common denominator
    result.numerator = (numerator*right.denominator) + (right.numerator*denominator); // sum numerators
    result.reduce(); // simplify the result

    return result; // return the sum
} // end operator+

// addition operator+; Rational+int
Rational Rational::operator+( int right ) const{
    return *this + Rational(right); // invoke operator+(Rational)
} // end operator+

/* ~~~~ Subtraction Operator Definitions   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
// subtraction operator-; Rational-Rational
Rational Rational::operator-( const Rational &right ) const{
    Rational result; // object to save the result

    result.denominator = denominator * right.denominator; // common denominator
    result.numerator = (numerator*right.denominator) - (right.numerator*denominator); // subtract numerators
    result.reduce(); // simplify the result

    return result; // return the difference
} // end operator-

// subtraction operator-; Rational-int
Rational Rational::operator-( int right ) const{
    return *this - Rational(right); // invoke operator-(Rational)
} // end operator-

/* ~~~~ Multiplication Operator Definitions   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
// multiplication operator*; Rational*Rational
Rational Rational::operator*( const Rational &right ) const{
    Rational result;

    result.numerator = numerator * right.numerator; // multiply numerators
    result.denominator = denominator * right.denominator; // multiply denominators
    result.reduce(); // simplify the result

    return result; // return the product
} // end operator*

// multiplication operator*; Rational*int
Rational Rational::operator*( int right ) const{
    return *this * Rational(right); // invoke operator*(Rational)
} // end operator*

/* ~~~~ Division Operator Definitions   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
// division operator/; Rational/Rational
Rational Rational::operator/( const Rational &right ) const{
    Rational result;

    result.numerator = numerator * right.denominator; // get the result's numerator
    result.denominator = denominator * right.numerator; // get the result's denominator
    result.reduce(); // simplify result

    return result; // return the quotient
} // end operator/

// division operator/; Rational/int
Rational Rational::operator/( int right ) const{
    return *this / Rational(right); // invoke operator/(Rational)
} // end operator /


/** ============  Relational Operators Definitions  ==== ============== ===================== ===================== ======== */
/* ~~~~ Operator == Definitions   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
// equal operator==; Rational == Rational
bool Rational::operator==( const Rational &right ) const{
    // compare numerator and denominator
    return (numerator == right.numerator ) && (denominator == right.denominator);
} // end operator==

// equal operator==; Rational == int
bool Rational::operator==( int right ) const{
    return *this == Rational(right); // invoke operator==(Rational)
} // equal operator==

/* ~~~~ Operator != Definitions   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
// unequal operator!=; Rational != Rational
bool Rational::operator!=( const Rational &right ) const{
    return ! (*this == right); // invoke operator==(Rational)
} // end operator!=

// unequal operator!=; Rational != int
bool Rational::operator!=( int right ) const{
    return *this != Rational(right); // invoke operator!=(Rational)
} // end operator!=

/* ~~~~ Operator < Definitions   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
// less than operator<; Rational < Rational
bool Rational::operator<( const Rational &_right ) const{
    double left = numerator/denominator; // get the decimal value of the fraction
    double right = _right.numerator/_right.denominator;

    return (left<right ? true : false ); // if left is less than right
} // end operator<

// less than operator<; Rational < int
bool Rational::operator<( int right ) const {
    return *this < Rational(right); // invoke operator<(Rational)
} // end operator<

/* ~~~~ Operator > Definitions   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
// higher than operator>; Rational > Rational
bool Rational::operator>( const Rational &right) const {
    if (*this == right)
        return false; // object this is not higher than right

    return ! (*this < right); // invoke operator<
} // end operator>

// higher than operator>; Rational > int
bool Rational::operator>( int right ) const{
    return *this > Rational(right); // invoke operator>(Rational)
} // end operator>

/* ~~~~ Operator <= Definitions   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
// less or equal operator<=; Rational <= Rational
bool Rational::operator<=( const Rational &right ) const {
    if (*this == right)
        return true; // objects are equal

    if (*this < right )
        return true; // this is less than right

    return false; // this is higher than right
} // end operator<=

// less than or equal operator<=; Rational <= int
bool Rational::operator<=( int right ) const {
    return *this <= Rational(right); // invoke operator<=(Rational)
} // end operator<=

/* ~~~~ Operator >= Definitions   ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
// higher or equal than operator>=; Rational >= Rational
bool Rational::operator>=( const Rational &right ) const{
    if (*this == right)
        return true; // this is equal than right

    if (*this > right)
        return true; // this is higher than right

    return false; // this is less than right
} // end operator>=

// higher or equal than operator>=; Rational >= int
bool Rational::operator>=( int right ) const {
    return *this >= Rational(right); // invoke operator>=(Rational)
} // end operator>=


/** ============  BitWise Operators Definitions     ===  ============== ===================== ===================== ======== */
// overload output operator
ostream& operator<<( ostream &output, const Rational &fraction ){
    output << fraction.numerator << '/' << fraction.denominator;

    return output;
} // end operator<<