// OvernightPackage.cpp
// OvernightPackage class member-definitions
#include "OvernightPackage.h"
#include <iostream>
using namespace std;

// constructor
OvernightPackage::OvernightPackage
                 ( const info &_sender, const info &_recipient, const double _weight, const double _cost, const double _fee)
                 : Package(_sender, _recipient, _weight, _cost), fee{ _fee>0 ? _fee : throw "Fee must be > 0"}
{ // empty body
} // end constructor

// calculate cost plus the fee
double OvernightPackage::calculateCost() const
{
    return ( Package::getWeight() * (Package::getCostPerOunce() + fee ));
} // end calculateCost

// print package data
void OvernightPackage::print() const
{
    cout << "Overnight ";
    Package::print(); // reuse code
} // end print