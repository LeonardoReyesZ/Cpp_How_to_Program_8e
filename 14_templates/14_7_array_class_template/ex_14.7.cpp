// Exercise 14.7: ex_14.7.cpp -> implementing a template function
// Array class template
#include <iostream>
#include "ArrayT.h"
using namespace std;


int main(){
    Array<int> array1(5);
    Array<double> array2(5);
    Array<char> array3(5);

    // input arrays
    cout << "\nEnter 5 integers:" << endl;
    cin >> array1;

    cout << "\nEnter 5 doubles:" << endl;
    cin >> array2;

    cout << "\nEnter 5 char types:" << endl;
    cin >> array3;

    cout << "\nThe first array contains: " << endl
         << array1 << endl
         << "\nThe second array contains: " << endl
         << array2 << endl
         << "\nThe third array contains: " << endl
         << array3<< endl;

} // end main