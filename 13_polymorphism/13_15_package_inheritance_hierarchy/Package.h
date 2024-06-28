// Package.h
// Package base class
#ifndef PACKAGE_H
#define PACKAGE_H


#include <string>
using namespace std;

// struct to store the recipient and sender data
struct info
 {
    string name;
    string address;
    string city;
    string state;
    string zipCode;
};

class Package
{
public:
    Package(const info &, const info &, const double, const double );
    double getWeight() const;
    double getCostPerOunce() const;
    string getSendersAddress() const;
    string getRecipientsAddress() const;

    virtual double calculateCost() const;
    virtual void print() const;

private:
    info sender;
    info recipient;
    double weight;
    double costPerOunce;
};


#endif //PACKAGE_H