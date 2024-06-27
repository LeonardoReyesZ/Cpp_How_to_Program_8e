// Circle.cpp
// Circle class member-definitions
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Circle.h"
using namespace std;

// constructor
Circle::Circle( const int radius, const char _fill, const int _position) : TwoDimensionalShape(radius)
{
    fill = _fill;
    position = _position;
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

// draw
void Circle::draw() const
{
    // specify the radius and the Diameter of the circle
    int radius = Shape::getLength();
    int diameter = 2 * radius;

    int startPos = position; // left or center alignment

    if (position >= 80) // right alignment
        startPos = position - diameter; // make space to draw

    // Loop through each row
    for (int y = 0; y <= diameter; y+=2) {
        // Loop through each column
        cout << setw(startPos); // alignment
        for (int x = 0; x <= diameter; ++x) {
            // Calculate the distance from the center
            float distance = sqrt((x-radius) * (x-radius) + (y-radius) * (y-radius));

            // If the distance is approximately equal to the radius, plot a point
            if (distance > radius-0.5 && distance < radius+0.5)
                cout << fill;
            else
                cout << ' ';
        }
        if (position<80) cout << endl;
    }
} // end draw