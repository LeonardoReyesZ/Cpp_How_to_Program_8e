// HourlyWorker.cpp
// HourlyWorker class member-function definitions
#include <iostream>
#include "HourlyWorker.h"

// constructor
HourlyWorker::HourlyWorker(const string &_first, const string &_last, const string &_ssn,
                           const double _wage, const double _hours )
                           : Employee( _first, _last, _ssn )
{
    setWage( _wage );
    setHours( _hours );
} // end HourlyWorker constructor

// set wage
void HourlyWorker::setWage( const double _wage )
{
    wage = _wage>0 ? _wage : throw invalid_argument("Invalid wage");
} // end setWage

// return wage
double HourlyWorker::getWage() const
{
    return wage;
} // end getWage

// set number of hours
void HourlyWorker::setHours( const double _hours )
{
    hours = _hours>0 ? _hours : throw invalid_argument("Invalid number of hours");
} // end SetHours

// return number of hours
double HourlyWorker::getHours() const
{
    return hours;
} // end getHours

// override earnings
double HourlyWorker::earnings() const
{
    double total = hours * wage; // get the salary per hour

    if (hours>40) // if there is overtime hours
        total += (hours-40) * (wage*0.5); // add overtime salary

    return total;
} // end earnings

// print HourlyWorker's information
void HourlyWorker::print() const
{
    cout << "HourlyWorker Employee: ";
    Employee::print(); // reuse code
    cout << "\nwage per hour: " << getWage()
         << "; hours worked: " << getHours();
} // end print