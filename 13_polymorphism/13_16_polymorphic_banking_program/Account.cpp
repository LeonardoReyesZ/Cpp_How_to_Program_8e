// Account.cpp
// Base-class Account member-function definitions
#include <iostream>
#include "Account.h"
using namespace std;

// constructor
Account::Account( double B )
{
    if ( B >= 0.0 )
        balance = B;
    else
    {
        balance = 0.0;
        cout << "Incorrect initial balance" << endl;
    }
} // end constructor

// member function credit
void Account::credit( double amount )
{
    if (amount >= 0.0) balance += amount; // add credit to the balance
    else cout << "Incorrect credit amount" << endl;
} // end credit

// member function debit
void Account::debit( double amount )
{
    if (amount <= balance) balance -= amount;
    else cout << "Debit amount exceeded account balance" << endl;
} // end debit

// member function getBalance
double Account::getBalance() const
{
    return balance;
} // end getBalance