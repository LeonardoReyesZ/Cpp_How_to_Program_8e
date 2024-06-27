// Square.h
// Square class derived from TwoDimensionalShape

#ifndef SQUARE_H
#define SQUARE_H


#include "TwoDimensionalShape.h"

class Square : public TwoDimensionalShape{
public:
    Square( const int = 1, const char = '*', const int = 0); // constructor
    virtual double getArea() const;
    virtual void print() const;
    virtual void draw() const;
private:
    char fill;
    int position;
};


#endif //SQUARE_H
