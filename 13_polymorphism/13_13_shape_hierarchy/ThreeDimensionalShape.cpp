// ThreeDimensionalShape.cpp
// ThreeDimensionalShape class member-definitions
#include <iostream>
#include "ThreeDimensionalShape.h"
using namespace std;


// constructor
ThreeDimensionalShape::ThreeDimensionalShape( const int len ) : Shape(len)
{ // empty body
} // end constructor

// print
void ThreeDimensionalShape::print() const
{
    cout << "three dimensional shape ";
} // end function print