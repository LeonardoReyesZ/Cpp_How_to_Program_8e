// ThreeDimensionalShape.h
// ThreeDimensionalShape derived from Shape

#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H


#include "Shape.h"

class ThreeDimensionalShape : public Shape
{
public:
    ThreeDimensionalShape( const int ); // constructor
    // pure virtual functions
    virtual double getArea() const = 0;
    virtual double getVolume() const = 0;

    virtual void print() const;
};


#endif //THREEDIMENSIONALSHAPE_H