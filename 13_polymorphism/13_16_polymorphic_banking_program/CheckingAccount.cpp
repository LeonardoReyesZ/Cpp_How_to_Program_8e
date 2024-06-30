// CheckingAccount.cpp
// CheckingAccount member-function definitions
#include "CheckingAccount.h"

// constructor
CheckingAccount::CheckingAccount(double B, double F)
                : Account(B), fee{F>0.0 ? F : throw "Invalid fee"}
{ // empty body
} // end constructor

// override credit function
void CheckingAccount::credit( double amount )
{
    Account::credit( amount-fee );
} // end credit

// override debit function
void CheckingAccount::debit( double amount )
{
    Account::debit( amount+fee );
} // end debit