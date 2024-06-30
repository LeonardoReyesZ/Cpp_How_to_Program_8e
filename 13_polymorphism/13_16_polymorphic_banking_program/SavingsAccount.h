// SavingsAccount.h
// SavingsAccount derived from Account
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H


#include "Account.h"

class SavingsAccount : public Account
{
public:
    SavingsAccount( double = 0.0, double = 0.0 );
    double calculateInterest() const;

private:
    double rate; // interest rate
};


#endif //SAVINGSACCOUNT_H