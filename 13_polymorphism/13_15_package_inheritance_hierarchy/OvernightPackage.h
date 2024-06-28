// OvernightPackage.h
// OvernightPackage class derived from Package

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H


#include "Package.h"

class OvernightPackage : public Package
{
public:
    OvernightPackage(const info &, const info &, const double, const double, const double);
    virtual double calculateCost() const;
    virtual void print() const;
private:
    double fee; // extra fee
};


#endif //OVERNIGHTPACKAGE_H