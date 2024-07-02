// PieceWorker.h
// PieceWorker class derived from employee
#ifndef PIECEWORKER_H
#define PIECEWORKER_H


#include "Employee.h"

class PieceWorker : public Employee
{
public:
    PieceWorker( const string &, const string &, const string &, const double, const double );

    void setWage( double );
    double getWage() const;
    void setPieces( double );
    double getPieces() const;

    // keyword virtual signals intent to override
    virtual double earnings() const; // calculate earnings
    virtual void print() const; // print PieceWorker object

private:
    double wage; // employee's wage per piece
    double pieces; // number of pieces produced
};


#endif //PIECEWORKER_H