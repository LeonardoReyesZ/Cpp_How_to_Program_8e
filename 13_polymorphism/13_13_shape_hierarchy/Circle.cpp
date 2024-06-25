// Circle.cpp
// Circle class member-definitions
#include <iostream>
#include <cmath>
#include "Circle.h"
using namespace std;

// constructor
Circle::Circle( const int radius ) : TwoDimensionalShape(radius)
{ // empty body
} // end constructor

// get Area of a circle
double Circle::getArea() const
{
    return pi*( pow(Shape::getLength(),2)); // area = pi*(radius^2)
} // end getArea

// print
void Circle::print() const
{
    cout << "Circle is a ";
    TwoDimensionalShape::print(); // reuse code
    cout << "\nIts area is: " << getArea() << endl;
} // end print