// Ex. 13.12: ex_13.12.cpp
// Processing Employee derived-class objects individually plus birthday bonus
// and polymorphically using dynamic binding.
#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
using namespace std;

void virtualViaPointer( const Employee * const, const Date & ); // prototype

int main()
{
    // set floating-point output formatting
    cout << fixed << setprecision(2);

    // create derived-class objects
    SalariedEmployee salariedEmployee(
            "John", "Smith", "111-11-1111", Date(02,20,1995), 800 );
    CommissionEmployee commissionEmployee(
            "Sue", "Jones", "333-33-3333", Date(06,12,1999), 10000, .06 );
    BasePlusCommissionEmployee basePlusCommissionEmployee(
            "Bob", "Lewis", "444-44-4444", Date(12,27,1987), 5000, .04, 300 );

    // create vector of three base-class pointers
    vector <Employee *> employees(3);

    // initialize vector with Employess
    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee;

    // start date for the payments
    Date date(12,01,2024);

    cout << "Employees processed polymorphically via dynamic binding:\n";

    // call virtualViaPointer to print each Employee's information
    // and earnings using dynamic binding
    cout << "Virtual function calls made off base-class pointers:\n\n";

    for (size_t i=0; i<employees.size(); ++i)
        virtualViaPointer( employees[i], date );


} // end main

// call Employee virtual functions print and earnings off a
// base-class pointer using dynamic binding
void virtualViaPointer( const Employee * const baseClassPtr, const Date &payDate )
{

    if (payDate.getMonth() == baseClassPtr->getBirthDay().getMonth())
    {
        cout << "Happy BirthDay !!! You got $100 as a gift !!!\n";
        baseClassPtr->print();
        cout << "\nearned $" << baseClassPtr->earnings() + 100 << "\n\n";
    }
    else
    {
        baseClassPtr->print();
        cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
    }
} // end function virtualViaPointer

