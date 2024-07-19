// Exercise 14.6: ex_14.6.cpp -> implementing a template function
// equally operator for user-defined class type
#include <iostream>
#include "Array.h"
using namespace std;

template< typename T >
bool isEqualTo( const T a, const T b)
{
    return a==b;
} // end isEqualTo


int main(){
    Array integers1(7); // seven-element array
    Array integers2; // 10-element Array by default

    // print integers1 size and contents
    cout << "Size of Array integers1 is "
         << integers1.getSize()
         << "\nArray after initialization:\n" << integers1;

    // print integers2 size and contents
    cout << "Size of Array integers2 is "
         << integers2.getSize()
         << "\nArray after initialization:\n" << integers2;

    // input and print integers1 and integers2
    cout << "\nEnter 17 integers:" << endl;
    cin >> integers1 >> integers2;

    cout << "\nAfter input, the Arrays contain:\n"
         << "integers1:\n" << integers1
         << "integers2:\n" << integers2;

    cout << "\n\nintegers1 == integer2 ? " << isEqualTo(integers1, integers2) << endl;


    Array integers3(integers2);

    cout << "\nintegers2 == integers3 ? " << isEqualTo(integers2, integers3) << endl;

} // end main