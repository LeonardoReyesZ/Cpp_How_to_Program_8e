// Exercise 14.3: ex_14.3.cpp -> implementing a template function
// Selection sort with pass-by-reference. This program puts values into an
// array, sorts them into ascending order and prints the resulting array.
#include <iostream>
#include <iomanip>
using namespace std;

template< typename T >
void print_sort( T * const, const int ); // prototype

template< typename T >
void selectionSort( T * const, const int ); // prototype

template< typename T >
void swap( T * const, T * const ); // prototype


int main()
{
    const int arraySize = 10;
    const int arraySize2 = 8;
    int intArray[arraySize] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
    float floatArray[arraySize2] = { 8.8, 7.7, 6.6, 2.2,  1.1,3.3, 4.4, 5.5 };

    print_sort(intArray, arraySize);
    cout << "\n\n";

    print_sort( floatArray, arraySize2 );

} // end main


// function to print original and sort array
template< typename T >
void print_sort( T * const array, const int size )
{
    cout << "Data items in original order\n";

    for ( int i = 0; i < size; ++i )
        cout << setw( 4 ) << array[i];

    selectionSort( array, size ); // sort the array

    cout << "\nData items in ascending order\n";

    for ( int j = 0; j < size; ++j )
        cout << setw( 4 ) << array[j];

} // end print_sort


// function to sort an array
template< typename T >
void selectionSort( T * const array, const int size )
{
    int smallest; // index of smallest element

    // loop over size - 1 elements
    for ( int i = 0; i < size - 1; ++i )
    {
        smallest = i; // first index of remaining array

        // loop to find index of smallest element
        for ( int index = i + 1; index < size; ++index )
            if ( array[ index ] < array[ smallest ] )
                smallest = index;

        swap( &array[ i ], &array[ smallest ] );
    } // end if
 } // end function selectionSort

// swap values at memory locations to which
// element1Ptr and element2Ptr point
template< typename T >
void swap( T * const element1Ptr, T * const element2Ptr )
{
    T hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
} // end function swap