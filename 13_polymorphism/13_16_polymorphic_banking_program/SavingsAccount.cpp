// SavingsAccount.cpp
// SavingsAccount member-function definitions
#include "SavingsAccount.h"

// constructor
SavingsAccount::SavingsAccount(double B, double R)
               : Account(B), rate{R>0.0 ? R : throw "Incorrect rate"}
{ // empty body
} // end constructor

// function to calculate interest
double SavingsAccount::calculateInterest() const
{
    return getBalance() * rate/100;
} // end calculateInterest