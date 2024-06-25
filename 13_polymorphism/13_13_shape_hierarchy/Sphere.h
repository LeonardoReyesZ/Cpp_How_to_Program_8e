// Sphere.h
// Sphere class derived from ThreeDimensionalShape

#ifndef SPHERE_H
#define SPHERE_H

#include "ThreeDimensionalShape.h"

class Sphere : public ThreeDimensionalShape
{
public:
    Sphere( const int ); // constructor
    virtual double getArea() const;
    virtual double getVolume() const;
    virtual void print() const;
private:
    const double pi = 3.1416;
};


#endif //SPHERE_H
