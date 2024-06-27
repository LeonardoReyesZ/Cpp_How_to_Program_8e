// TwoDimensionalShape.cpp
// TwoDimensionalShape class member-definitions
#include <iostream>
#include "TwoDimensionalShape.h"
using namespace std;

// constructor
TwoDimensionalShape::TwoDimensionalShape( const int len ) : Shape(len)
{ // empty body
}

// function print
void TwoDimensionalShape::print() const{
    cout << "two dimensional shape" ;
} // end function print