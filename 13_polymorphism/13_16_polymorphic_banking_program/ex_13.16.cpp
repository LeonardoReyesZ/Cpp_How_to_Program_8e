#include <iostream>
#include <vector>
#include <typeinfo>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

int main(){
    // vector of two base-class pointers
    vector <Account *> accounts
    {
        new SavingsAccount{2000, 2},
        new CheckingAccount{4000, 1}
    };

    // polymorphically interact with each element in vector accounts
    for (int i{0}, temp; i<accounts.size(); ++i)
    {
        cout << typeid( *accounts[i] ).name() << endl
             << "current balance: $" << accounts[i]->getBalance() << endl
             << "withdraw amount: $";
        cin >> temp;
        accounts[i]->debit(temp);
        cout << "deposit amount: $";
        cin >> temp;
        accounts[i]->credit(temp);

        // calculate and add interest if the element points to a SavingsClass object
        SavingsAccount *derivedPtr = dynamic_cast <SavingsAccount *> (accounts[i]); // downcast pointer
        if (derivedPtr != 0)
        {
            temp = derivedPtr->calculateInterest();
            cout << "earnings: $" << temp << endl;
            derivedPtr->credit( derivedPtr->calculateInterest() );
        }

        cout << "updated balance: $" << accounts[i]->getBalance() << "\n\n";
    }

    return 0;
}