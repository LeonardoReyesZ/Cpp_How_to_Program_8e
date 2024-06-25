// Tetrahedron.h
// Tetrahedron class derived from ThreeDimensionalShape


#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H


#include "ThreeDimensionalShape.h"

class Tetrahedron : public ThreeDimensionalShape
{
public:
    Tetrahedron( const int ); // constructor
    virtual double getArea() const;
    virtual double getVolume() const;
    virtual void print() const;
};


#endif //TETRAHEDRON_H
