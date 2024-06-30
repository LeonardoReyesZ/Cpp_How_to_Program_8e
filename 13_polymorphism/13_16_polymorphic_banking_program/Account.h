// Account.h
// Account base class
#ifndef ACCOUNT_H
#define ACCOUNT_H


class Account
{
public:
    Account( double = 0.0 );
    virtual void debit( double );
    virtual void credit( double );
    double getBalance() const;

private:
    double balance;
};


#endif //ACCOUNT_H