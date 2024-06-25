// Triangle.cpp
// Triangle class member-function
// This class simulates an equilateral triangle
#include <iostream>
#include <cmath>
# include "Triangle.h"
using namespace std;

// constructor
Triangle::Triangle( const int len ) : TwoDimensionalShape(len)
{ // empty body
} // end constructor

// get Area
double Triangle::getArea() const
{
    return sqrt(3)/4 * pow(Shape::getLength(),2);
} // end getArea

// print
void Triangle::print() const
{
    cout << "Triangle is a ";
    TwoDimensionalShape::print(); // reuse code
    cout << "\nIts area is: " << getArea() << endl;
} // end print