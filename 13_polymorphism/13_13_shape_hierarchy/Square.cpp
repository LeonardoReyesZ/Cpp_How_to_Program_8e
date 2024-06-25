// Square.cpp
// Square class member-definitions
#include <iostream>
#include "Square.h"
using namespace std;

// constructor
Square::Square( const int len ) : TwoDimensionalShape(len)
{ // empty body
} // end constructor

// get Area
double Square::getArea() const
{
    return Shape::getLength() * Shape::getLength();
} // end getArea

// print
void Square::print() const
{
    cout << "Circle is a ";
    TwoDimensionalShape::print(); // reuse code
    cout << "\nIts area is: " << getArea() << endl;
}