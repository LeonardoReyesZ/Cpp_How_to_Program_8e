// Square.cpp
// Square class member-definitions
#include <iostream>
#include <iomanip>
#include "Square.h"
using namespace std;

// constructor
Square::Square( const int len, const char _fill, const int _position ) : TwoDimensionalShape(len)
{
    fill = _fill;
    position = _position;
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
} // end print

// draw
void Square::draw() const
{
    // set the start position to draw the shape
    int startPos = position; // left or center alignment

    if (position >= 80) // right alignment
        startPos = position - (Shape::getLength()*2) +1; // make space to draw

    for (int i=0; i<Shape::getLength(); ++i)
    {
        cout << setw(startPos);
        for (int j = 0; j<Shape::getLength(); ++j)
            if (i==0 || i==Shape::getLength()-1 || j==0 || j==Shape::getLength()-1)
                cout << fill << " ";
            else
                cout << "  ";

        if (position<80) cout << endl;
    }
} // end draw