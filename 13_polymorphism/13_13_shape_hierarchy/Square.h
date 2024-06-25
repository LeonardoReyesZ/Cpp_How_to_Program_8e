// Square.h
// Square class derived from TwoDimensionalShape

#ifndef SQUARE_H
#define SQUARE_H


#include "TwoDimensionalShape.h"

class Square : public TwoDimensionalShape{
public:
    Square( const int ); // constructor
    virtual double getArea() const;
    virtual void print() const;
};


#endif //SQUARE_H
