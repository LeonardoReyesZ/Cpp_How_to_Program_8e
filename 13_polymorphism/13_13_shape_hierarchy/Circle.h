// Circle.h
// Circle class derived from TwoDimensionalShape

#ifndef CIRCLE_H
#define CIRCLE_H


#include "TwoDimensionalShape.h"

class Circle : public TwoDimensionalShape{
public:
    Circle( const int ); // constructor
    virtual double getArea() const;
    virtual void print() const;
private:
    // length is the radius
    const double pi = 3.1416;
};


#endif //13_CIRCLE_H