// Fig 11.11: Array.cpp
// Array class member- and friend-function definitions
#include <iostream>
#include <iomanip>
#include <cstdlib> // exit function prototype
#include "Array.h" // Array class definition
using namespace std;

// default constructor for class Array (default size 10)
Array::Array( int arraySize ){
    // validate arraySize
    if( arraySize>0)
        size = arraySize;
    else
        throw invalid_argument("Array size must be greater than 0");

    ptr = new int[size]; // create space for pointer-based array

    for( int i=0; i<size; ++i)
        ptr[i] = 0; // set pointer-based array element
} // end Array default constructor

// copy constructor for class Array;
// must receive a reference to prevent infinite recursion
Array::Array( const Array &arrayToCopy )
    : size( arrayToCopy.size ){
    ptr = new int[size]; // create space for pointer-based array

    for( int i=0; i<size; ++i )
        ptr[i] = arrayToCopy.ptr[i]; // copy into object
} // end Array copy constructor

// destructor for class Array
Array::~Array(){
    delete [] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
int Array::getSize() const{
    return size; // number of elements in Array
} // end function getSize

// overloaded assigment operator;
// const return avoids: ( a1 == a2) = a3
const Array &Array::operator=( const Array &right ){
    if( &right != this ){ // avoid self-assignment
        // for Arrays of different sizes, deallocate original
        // left-side array, then allocate new left-side array
        if( size != right.size ){
            delete [] ptr; // release space
            size = right.size; // resize this object
            ptr = new int[size]; // create space for array copy
        } // end inner if

        for( int i=0; i<size; ++i)
            ptr[i] = right.ptr[i]; // copy array into object
    } // end outer if

    return *this; // enables x = y = z, for example
} // end function operator=

// determine if two Arrays are equal and
// return true, otherwise return false
bool Array::operator==( const Array &right ) const{
    if( size != right.size )
        return false; // arrays of different number of elements

    for( int i=0; i<size; ++i)
        if( ptr[i] != right.ptr[i])
            return false; // Array contents are not equal

    return true; // Arrays are equal
} // end function operator==

// determine if two Arrays are not equal
bool Array::operator!=(const Array &right) const {
    return !( *this==right ); // invokes Array::operator==
} // end function operator!=

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
int &Array::operator[]( int subscript ){
    // check for subscript out-of-range error
    if( subscript<0 || subscript>=size )
        throw out_of_range("Subscript out of range");

    return ptr[subscript]; // reference return
} // end function operator[]

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int Array::operator[]( int subscript ) const{
    // check for subscript out-of-range error
    if( subscript<0 || subscript>=size )
        throw out_of_range("Subscript out of range");

    return ptr[subscript]; // returns copy of this element
} // end function operator[]

// overloaded input operator for class Array;
// inputs values for entire Array
istream &operator>>( istream &input, Array &a ){
    for( int i=0; i<a.size; ++i )
        input >> a.ptr[i];

    return input; // enables cin >> x >> y;
} // end function operator>>

// overloaded output operator for class Array
ostream &operator<<( ostream &output, const Array &a ){
    int i;

    // output private ptr-based array
    for( i=0; i<a.size; ++i ){
        output << setw(12) << a.ptr[i];

        if( (i+1)%4 == 0) // four numbers per row of output
            output << endl;
    }

    if( i%4 != 0 ) // end last line of output
        output << endl;

    return output; // enables cout << x << y;
} // end function operator<<
