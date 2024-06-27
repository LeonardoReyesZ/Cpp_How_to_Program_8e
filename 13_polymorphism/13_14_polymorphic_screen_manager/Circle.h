// Circle.h
// Circle class derived from TwoDimensionalShape

#ifndef CIRCLE_H
#define CIRCLE_H


#include "TwoDimensionalShape.h"

class Circle : public TwoDimensionalShape{
public:
    Circle( const int = 1, const char = '*', const int = 0); // constructor
    virtual double getArea() const;
    virtual void print() const;
    virtual void draw() const;
private:
    // length is the radius
    const double pi = 3.1416;
    int position; // position to start drawing
    char fill; // symbol to draw
};


#endif //CIRCLE_H