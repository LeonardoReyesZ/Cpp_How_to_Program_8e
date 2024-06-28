// TwoDayPackage.cpp
// TwoDayPackage class member-definitions
#include "TwoDayPackage.h"
#include <iostream>
using namespace std;

// constructor
TwoDayPackage::TwoDayPackage( const info &_sender, const info &_recipient, const double _weight, const double _cost, const double _fee )
              : Package(_sender, _recipient, _weight, _cost), fee( _fee>0 ? _fee : throw "Flat fee must be > 0")
{ // empty body
} // end constructor

// calculate cost of the package plus flat fee
double TwoDayPackage::calculateCost() const
{
    return ( (Package::getWeight() + fee) * Package::getCostPerOunce() );
} // end calculateCost

// print two day package data
void TwoDayPackage::print() const
{
    cout << "Two day ";
    Package::print(); // reuse code
} // end print