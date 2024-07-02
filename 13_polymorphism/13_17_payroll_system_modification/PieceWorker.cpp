// PieceWorker.cpp
// PieceWorker class member-function definitions
#include <iostream>
#include "PieceWorker.h"

// constructor
PieceWorker::PieceWorker( const string &_first, const string &_last, const string &_ssn,
                          const double _wage, const double _pieces )
                          : Employee(_first, _last, _ssn)
{
    setWage( _wage );
    setPieces( _pieces );
} // end PieceWorker constructor

// set wage
void PieceWorker::setWage( const double _wage )
{
    wage =  _wage>0 ? _wage : throw invalid_argument("Invalid wage");
} // end setWage

// return wage
double PieceWorker::getWage() const
{
    return wage;
} // end getWage

// set number of pieces
void PieceWorker::setPieces( const double _pieces )
{
    pieces = _pieces>0 ? _pieces : throw invalid_argument("Invalid number of pieces");
} // end setPieces

// return number of pieces
double PieceWorker::getPieces() const
{
    return pieces;
} // end getPieces

// override earnings
double PieceWorker::earnings() const
{
    return wage * pieces;
} // end earnings

// print PieceWorker's information
void PieceWorker::print() const
{
    cout << "PieceWorker Employee: ";
    Employee::print(); // code reuse
    cout << "\nwage per piece: " << getWage()
         << "; number of pieces produced: " << getPieces();
} // end print
