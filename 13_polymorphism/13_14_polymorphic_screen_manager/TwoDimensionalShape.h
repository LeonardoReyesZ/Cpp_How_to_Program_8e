// TwoDimensionalShape.h
// TwoDimensionalShape class derived from Shape
#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H


#include "Shape.h"

class TwoDimensionalShape : public Shape{
public:
    TwoDimensionalShape( const int ); // constructor

    // polymorphic functions
    virtual double getArea() const = 0; // pure virtual function
    virtual void print() const;
};


#endif //TWODIMENSIONALSHAPE_H
