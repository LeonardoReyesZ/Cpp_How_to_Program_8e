// Sphere.cpp
// Sphere class member-definitions
#include <iostream>
#include <cmath>
#include "Sphere.h"
using namespace std;

// constrctor
Sphere::Sphere( const int radius ) : ThreeDimensionalShape( radius )
{ // empty body
} // end constructor

// get Area
double Sphere::getArea() const
{
    return pi*( pow(Shape::getLength(),2)); // area = pi*(radius^2)
} // end getArea

// getVolume
double Sphere::getVolume() const
{
    return (4.0/3.0) * pi * pow(Shape::getLength(), 3)  ;
} // end getVolume

// print
void Sphere::print() const
{
    cout << "Sphere is a ";
    ThreeDimensionalShape::print(); // reuse code
    cout << "\nIts area is: " << getArea() << endl
         << "Its volume is: " << getVolume() << endl;
}