// Shape.cpp
// Abstract-base-class Shape member-function definitions
#include "Shape.h"
using namespace std;

// constructor
Shape::Shape( const int len ) : length(len)
{ // empty body
} // end Shape constructor

// set length
void Shape::setLength( const int len ){
    length = len;
} // end setLength

// return length
int Shape::getLength() const{
    return length;
} // end getLength