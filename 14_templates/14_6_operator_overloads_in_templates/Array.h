// Fig 11.10: Array.h
// Array class definition with overloaded operators
#ifndef INC_14_TEMPLATES_ARRAY_H
#define INC_14_TEMPLATES_ARRAY_H

#include <iostream>
using namespace std;

class Array{
    friend ostream &operator<<( ostream &, const Array & );
    friend istream &operator>>( istream &, Array & );

public:
    Array( int = 10 ); // default constructor
    Array( const Array & ); // copy constructor
    ~Array(); // destructor
    int getSize() const; // return size

    const Array &operator=( const Array & ); // assigment operator
    bool operator==( const Array & ) const; // equality operator
    bool operator!=( const Array & ) const; // inequality operator; returns opposite of == operator

    // subscript operator for non-const objects returns modifiable lvalue
    int &operator[]( int );

    // subscript operator for const objects returns lvalue
    int operator[]( int ) const;

private:
    int size; // pointer-based array size
    int *ptr; // pointer to first element of pointer-based array
}; // end class Array

#endif //INC_14_TEMPLATES_ARRAY_H