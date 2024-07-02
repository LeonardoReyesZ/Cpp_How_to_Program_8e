// HourlyWorker.h
// HourlyWorker class derived from Employee
#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H


#include "Employee.h"

class HourlyWorker : public Employee
{
public:
    HourlyWorker( const string &, const string &, const string &, const double, const double );

    void setWage( double );
    double getWage() const;
    void setHours( double );
    double getHours() const;

    // keyword virtual signals intent to override
    virtual double earnings() const; // calculate earnings
    virtual void print() const; // print HourlyWorker object

private:
    double wage; // employee's wage per hour
    double hours; // hours worked
};


#endif //HOURLYWORKER_H
