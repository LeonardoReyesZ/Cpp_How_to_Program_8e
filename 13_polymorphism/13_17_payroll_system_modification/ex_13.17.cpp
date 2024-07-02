// ex_13_17.cpp
// Processing Employee derived-class objects individually
#include <iostream>
#include <iomanip>
#include <vector>
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"
#include "PieceWorker.h"
#include "HourlyWorker.h"
using namespace std;


int main()
{
    // set floating-point output formatting
    cout << fixed << setprecision(2);

    // create vector of three base-class pointers
    vector <Employee *> employees
    {
        new SalariedEmployee( "John", "Smith", "111-11-1111", 800 ),
        new CommissionEmployee( "Sue", "Jones", "333-33-3333", 10000, .06 ),
        new BasePlusCommissionEmployee( "Bob", "Lewis", "444-44-4444", 5000, .04, 300 ),
        new PieceWorker( "Stacy", "Obama", "888-88-8888", 20, 300 ),
        new HourlyWorker( "Arya", "Blummer", "777-77-7777", 50, 35 ),
        new HourlyWorker( "Brandon", "Stark", "666-66-6666", 50, 45 )
    };

    // call virtualViaPointer to print each Employee's information
    for (Employee *employeePtr : employees )
    {
        employeePtr->print();
        cout << "\nearned: $" << employeePtr->earnings() << "\n\n";
    }


} // end main