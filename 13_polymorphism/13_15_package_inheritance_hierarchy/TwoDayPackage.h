// TwoDayPackage.h
// TwoDayPackage class derived from Package

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H


#include "Package.h"

class TwoDayPackage : public Package
{
public:
    TwoDayPackage( const info &, const info &, const double, const double, const double );
    virtual double calculateCost() const;
    virtual void print() const;

private:
    double fee; // extra fee
};


#endif //TWODAYPACKAGE_H
