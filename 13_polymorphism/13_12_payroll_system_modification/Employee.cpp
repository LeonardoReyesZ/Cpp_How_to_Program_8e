// Fig. 13.10: Employee.cpp
// Abstract-base-class Employee member-function definitions.
// Note: No definitions are given for pure virtual functions.
#include <iostream>
#include "Employee.h" // Employee class definition
using namespace std;

// constructor
Employee::Employee( const string &first, const string &last, const string &ssn, const Date &birth )
         : firstName(first), lastName(last), socialSecurityNumber(ssn), birthDay(birth){
    // empty body
} // end Employee constructor

// set first name
void Employee::setFirstName( const string &first ){
    firstName = first;
} // end function setFirstName

// get first name
string Employee::getFirstName() const{
    return firstName;
} // end function getFirstName

// set last name
void Employee::setLastName( const string &last ){
    lastName = last;
} // end function setLastName

// get last name
string Employee::getLastName() const{
    return lastName;
} // end function getLastName

// set social security number
void Employee::setSocialSecurityNumber( const string &ssn){
    socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// get social security number
string Employee::getSocialSecurityNumber() const{
    return socialSecurityNumber;
} // end function getSocialSecurityNumber

// set birhtday
void Employee::setBirthDay( const Date &birth ){
    birthDay = birth; // should validate
} // end setBirthDay

// get birthday
Date Employee::getBirthDay() const{
    return birthDay;
} // end getBirthDay

// print Employee's information (virtual, but not pure virtual)
void Employee::print() const{
    cout << getFirstName() << ' ' << getLastName()
         << "\nsocial security number: " << getSocialSecurityNumber()
         << "\nBirthday: " << getBirthDay();
} // end function print