// Triangle.cpp
// Triangle class member-function
// This class simulates an equilateral triangle
#include <iostream>
#include <iomanip>
#include <cmath>
# include "Triangle.h"
using namespace std;

// constructor
Triangle::Triangle( const int len, const char _fill, const int _position ) : TwoDimensionalShape(len)
{
    fill = _fill;
    position = _position;
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

// draw
void Triangle::draw() const
{
    for (int i=0; i<Shape::getLength(); ++i)
    {
        int stars = 2*i + 1; // Number of stars in the current row
        int spaces; // number of spaces for each row

        // set the alignment to start drawing
        if (position == 0 ) // left alignment
            spaces = ((Shape::getLength()*2)-stars)/2;
        else if (position>=80) // right alignment
            spaces = position - ((stars + (Shape::getLength()*2)) / 2);
        else // default -> center alignment
            spaces = ((position*2)-stars)/2;

        string line(spaces, ' '); // Left padding
        line += string(stars, fill); // Stars
        //line += string(spaces, ' '); // Right padding (optional)

        cout << line << endl;
    }
} // end draw