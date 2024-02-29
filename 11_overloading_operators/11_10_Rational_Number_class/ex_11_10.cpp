// Exercise 11.10: ex_11_10.cpp
// Rational class; overload arithmetic and relational operators
#include <iostream>
#include "Rational.h"
using namespace std;

int main(){
    Rational a(3,5), b(7,26), c(a), d;
    Rational e(14,52), f(21,78), g(9,1);

    cout << "a = " << a << endl
         << "b = " << b << endl
         << "c = " << c << "\n\n";

    /* ~~~~  Arithmetic operators tests    ~~~~~~~~~~ ~~~~~~~ ~~~~~~~~~ */
    // addition operator tests
    d = a+b; // implicit assigment
    cout << "Arithmetic operations\n\n"
         << a << " + " << b << " = " << d << endl
         << a << " + " << 20 << " = " << (a+20) << endl
         << b << " + " << c << " + " << 3 << " = " << (b+c+3) << "\n\n";

    // subtraction operator tests
    cout << a << " - " << b << " = " << (a-b) << endl
         << a << " - " << 20 << " = " << (a-20) << endl
         << b << " - " << c << " - " << 3 << " = " << (b-c-3) << "\n\n";

    // multiplication operator tests
    cout << a << " * " << b << " = " << (a*b) << endl
         << a << " * " << 20 << " = " << (a*20) << endl
         << b << " * " << c << " * " << 3 << " = " << (b*c*3) << "\n\n";

    // division operator tests
    cout << a << " / " << b << " = " << (a/b) << endl
         << a << " / " << 20 << " = " << (a/20) << endl
         << b << " / " << c << " / " << 3 << " = " << (b/c/3) << "\n\n";

    /* ~~~~  Relational operators tests    ~~~~~~~~~~ ~~~~~~~ ~~~~~~~~~ */
    // equal operator tests
    cout << "Relational operators\n\n"
         << a << " == " << b << " : " << (a==b ? "True" : "False") << endl
         << b << " == " << e << " : " << (b==e ? "True" : "False") << endl
         << f << " == " << 3 << " : " << (f==3 ? "True" : "False") << endl
         << g << " == " << 9 << " : " << (g==9 ? "True" : "False") << "\n\n";

    // unequal operator tests
    cout << a << " != " << b << " : " << (a!=b ? "True" : "False") << endl
         << b << " != " << e << " : " << (b!=e ? "True" : "False") << endl
         << f << " != " << 3 << " : " << (f!=3 ? "True" : "False") << endl
         << g << " != " << 9 << " : " << (g!=9 ? "True" : "False") << "\n\n";

    // less than operator tests
    cout << a << " < " << b << " : " << (a<b ? "True" : "False") << endl
         << b << " < " << e << " : " << (b<e ? "True" : "False") << endl
         << f << " < " << 3 << " : " << (f<3 ? "True" : "False") << endl
         << g << " < " << 9 << " : " << (g<9 ? "True" : "False") << "\n\n";

    // higher than operator tests
    cout << a << " > " << b << " : " << (a>b ? "True" : "False") << endl
         << b << " > " << e << " : " << (b>e ? "True" : "False") << endl
         << f << " > " << 3 << " : " << (f>3 ? "True" : "False") << endl
         << g << " > " << 9 << " : " << (g>9 ? "True" : "False") << "\n\n";

    // less or equal than operator tests
    cout << a << " <= " << b << " : " << (a<=b ? "True" : "False") << endl
         << b << " <= " << e << " : " << (b<=e ? "True" : "False") << endl
         << f << " <= " << 3 << " : " << (f<=3 ? "True" : "False") << endl
         << g << " <= " << 9 << " : " << (g<=9 ? "True" : "False") << "\n\n";

    // higher or equal than operator tests
    cout << a << " >= " << b << " : " << (a>=b ? "True" : "False") << endl
         << b << " >= " << e << " : " << (b>=e ? "True" : "False") << endl
         << f << " >= " << 3 << " : " << (f>=3 ? "True" : "False") << endl
         << g << " >= " << 9 << " : " << (g>=9 ? "True" : "False") << "\n\n";


    return 0;
} // end main
