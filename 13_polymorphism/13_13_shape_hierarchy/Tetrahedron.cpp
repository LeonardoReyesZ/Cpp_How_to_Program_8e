// Tetrahedron.cpp
// Tetrahedron class member-definitions
#include <iostream>
#include <cmath>
#include "Tetrahedron.h"
using namespace std;

// constructor
Tetrahedron::Tetrahedron( const int len ) : ThreeDimensionalShape(len )
{ // empty body
} // end constructor

// get Area
double Tetrahedron::getArea() const
{
    return sqrt(3)/4 * pow(Shape::getLength(),2);
} // end getArea

// getVolume
double Tetrahedron::getVolume() const
{
    return pow(Shape::getLength(),3) / (6*sqrt(2)) ;
} // end getVolume

// print
void Tetrahedron::print() const
{
    cout << "Tetrahedron is a ";
    ThreeDimensionalShape::print(); // reuse code
    cout << "\nIts area is: " << getArea() << endl
         << "Its volume is: " << getVolume() << endl;
}