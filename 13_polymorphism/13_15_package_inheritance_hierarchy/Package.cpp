// Package.cpp
// Base-class Package member-function definitions
#include "Package.h"
#include <iostream>
using namespace std;

// constructor
Package::Package(const info &_sender, const info &_recipient, const double _weight, const double _cost)
        : sender{_sender}, recipient{_recipient}, weight{_weight>0 ? _weight : throw "Weight must be > 0"},
          costPerOunce{_cost>0 ? _cost : throw "Cost must be > 0"}
{ // empty body
} // end constructor

// return the weight of the package
double Package::getWeight() const
{
    return weight;
} // end getWeight

// return cost per ounce
double Package::getCostPerOunce() const
{
    return costPerOunce;
} // end getCostPerOunce

// return sender's full address
string Package::getSendersAddress() const
{
    return sender.address + " " + sender.city + " " + sender.state + " " + sender.zipCode;
} // end getSendersAddress

// return recipient's full address
string Package::getRecipientsAddress() const
{
    return recipient.address + " " + recipient.city + " " + recipient.state + " " + recipient.zipCode;
} // end getRecipientsAddress

// return the cost of the package
double Package::calculateCost() const
{
    return weight * costPerOunce;
} // end calculateCost

// print package data
void Package::print() const
{
    cout << "package information: " << endl
         << "Sender's address: " << getSendersAddress() << endl
         << "Recipient's address: " << getRecipientsAddress() << endl
         << "cost of the package: $" << calculateCost() << endl;
} // end print