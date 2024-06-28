// Exercise 13.15: ex_13.15.cpp
// Package Inheritance Hierarchy
#include <iostream>
#include <iomanip>
#include <vector>
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
using namespace std;

int main() {
    // package data sample to make tests
    info sender[3] = {{"Stacy S.", "12th Parnell Road", "Dublin", "IR", "D01 234"},
                      {"Robert T.", "23th Abbey street", "Belfast", "IR", "B02 421"},
                      {"William S.", "2nd Occonnel street", "Galway", "IR", "G21 972"}};

    info recipient[3] = {{"Bernard O.", "6th Zunich street", "Munich", "GE", "678234"},
                         {"Samantha T.", "1st Owen street", "London", "EN", "E02 421"},
                         {"Isabella S.", "3rd Napoleon street", "Lyion", "FR", "FR1 972"}};

    double weight[3] = {1.0, 100.0, 10.0 };
    double cost[3] = {50, 200, 300};
    double fee[3] = {0.2, 0.3, 0.5 };

    double totalCost = 0; // total cost of all packages

    // set floating point output formatting
    cout << fixed << setprecision(2);

    // create vector of three base-class pointers
    vector <Package *> packages(3);

    // initialize vector with various kinds of packages
    packages[0] = new Package( sender[0], recipient[0], weight[0], cost[0] );
    packages[1] = new TwoDayPackage( sender[1], recipient[1], weight[1], cost[1], fee[1] );
    packages[2] = new OvernightPackage( sender[2], recipient[2], weight[1], cost[2], fee[2] );

    // polymorphically display each element in vector packages
    for ( size_t i{0}; i<packages.size(); ++i )
    {
        packages[i]->print();
        cout << endl;

        totalCost += packages[i]->calculateCost(); // get total cost
    }

    cout << "The total cost of all packages is: $" << totalCost <<endl ;

    return 0;
}