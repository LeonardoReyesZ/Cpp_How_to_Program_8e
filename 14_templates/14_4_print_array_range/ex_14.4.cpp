// Exercise 14.4: ex_14.4.cpp -> implementing a template function
// Using function-template specializations.
#include <iostream>
using namespace std;

// function template printArray definition
template< typename T >
void printArray( const T * const array, int size )
{
    for ( int i=0; i<size; ++i )
        cout << array[i] << ' ';

    cout << endl;
} // end function template printArray

// overloaded function template
template< typename T >
int printArray( const T * const array, int size, int lowSubscript, int highSubscript )
{
    if ( lowSubscript<0 || highSubscript>=size || highSubscript<=lowSubscript )
    {
        cout << "Invalid subscripts" << endl;
        return 0;
    }

    int count = 0;

    for( int i=lowSubscript; i<=highSubscript; ++i, ++count )
        cout << array[i] << ' ';

    cout << endl;

    return count;
}


int main()
{
    const int aSize = 5; // size of array a
    const int bSize = 7; // size of array b
    const int cSize = 6; // size of array c

    int a[aSize] = {1,2,3,4,5};
    double b[bSize] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7};
    char c[cSize] = "HELLO"; // 6th position for null

    cout << "Array a contains:" << endl;
    // call integer function-template specialization
    printArray(a, aSize);

    cout << "Array b contains:" << endl;
    // call double function-template specialization
    printArray(b, bSize);

    cout << "Array c contains:" << endl;
    // call character function-template specialization
    printArray(c, cSize);

    cout << "\n\nArray a[1-4] contains: " << endl
    // call integer function-template specialization
        << printArray(a, aSize, 1, 4)
        << " elements" << endl;

    cout << "Array b[2-6] contains:" << endl
    // call double function-template specialization
        << printArray(b, bSize, 2, 6)
        << " elements" << endl;

    cout << "Array c[2-4] contains:" << endl
    // call character function-template specialization
        << printArray(c, cSize, 2, 4)
        << " elements" << endl;
}
