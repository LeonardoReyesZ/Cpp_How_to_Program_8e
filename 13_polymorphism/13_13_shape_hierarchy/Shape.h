// Shape.h
// Shape abstract class
#ifndef SHAPE_H
#define SHAPE_H


class Shape{
public:
    Shape( const int ); // constructor
    void setLength(const int); // set length

    // virtual function
    virtual int getLength() const;
    // pure virtual function
    virtual void print() const = 0;

private:
    int length;
};


#endif //SHAPE_H