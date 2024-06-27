// Triangle.h
// Triangle class derived from TwoDimensionalShape
// This class simulates an equilateral triangle

#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "TwoDimensionalShape.h"

class Triangle : public TwoDimensionalShape{
public:
    Triangle( const int = 1, const char = '*', const int = 0); // constructor
    virtual double getArea() const;
    virtual void print() const;
    virtual void draw() const;
private:
    char fill;
    int position;
};

#endif //TRIANGLE_H
