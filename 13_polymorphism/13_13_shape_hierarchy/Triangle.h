// Triangle.h
// Triangle class derived from TwoDimensionalShape
// This class simulates an equilateral triangle

#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "TwoDimensionalShape.h"

class Triangle : public TwoDimensionalShape{
public:
    Triangle( const int ); // constructor
    virtual double getArea() const;
    virtual void print() const;
};

#endif //TRIANGLE_H
