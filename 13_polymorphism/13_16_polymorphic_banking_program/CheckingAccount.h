// CheckingAccount.h
// CheckingAccount derived from Account
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H


#include "Account.h"

class CheckingAccount : public Account
{
public:
    CheckingAccount( double = 0.0, double = 0.0 );
    virtual void credit( double );
    virtual void debit( double );

private:
    double fee;
};


#endif //CHECKINGACCOUNT_H
