// Cube.cpp
// Cube class member definition
#include <iostream>
#include "Cube.h"
using namespace std;

// constructor
Cube::Cube( const int radius ) : ThreeDimensionalShape(radius)
{ // empty body
} // end constructor

// get Area
double Cube::getArea() const
{
    return Shape::getLength() * Shape::getLength();
} // end getArea

// get Volume
double Cube::getVolume() const
{
    return Shape::getLength() * Shape::getLength() * Shape::getLength();
} // end getVolume

// print
void Cube::print() const
{
    cout << "Cube is a ";
    ThreeDimensionalShape::print(); // reuse code
    cout << "\nIts area is: " << getArea() << endl
         << "Its volume is: " << getVolume() << endl;
}