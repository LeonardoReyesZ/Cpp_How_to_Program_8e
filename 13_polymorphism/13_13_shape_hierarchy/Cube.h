// Cube.h
// Cube class derived from ThreeDimensionalShape

#ifndef CUBE_H
#define CUBE_H


#include "ThreeDimensionalShape.h"

class Cube : public ThreeDimensionalShape
{
public:
    Cube( const int ); // constructor
    virtual double getArea() const;
    virtual double getVolume() const;
    virtual void print() const;
};


#endif //CUBE_H