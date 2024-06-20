// Fig. 13.9: Employee.h
// Employee abstract base class.
#ifndef INC_17_POLYMORPHISM_EMPLOYEE_H
#define INC_17_POLYMORPHISM_EMPLOYEE_H

#include <string> // C++ standard string class
#include "Date.h" // date class
using namespace std;

class Employee{
public:
    Employee( const string &, const string &, const string &, const Date& );

    void setFirstName( const string & ); // set first name
    string getFirstName() const; // return last name

    void setLastName( const string & ); // set last name
    string getLastName() const; // return last name

    void setSocialSecurityNumber( const string & ); // set SSN
    string getSocialSecurityNumber() const; // return SSN

    void setBirthDay( const Date & ); // set birthday
    Date getBirthDay() const; // return birthday

    // pure virtual function makes Employee an abstract base class
    virtual double earnings() const = 0; // pure virtual
    virtual void print() const; // virtual

private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
    Date birthDay;
}; // end class Employee_H

#endif //INC_17_POLYMORPHISM_EMPLOYEE_H
