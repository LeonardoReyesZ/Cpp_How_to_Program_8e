// Fig 11.19: fig11_19.cpp
// HugeInt test program
#include <iostream>
#include "Hugeint.h"
using namespace std;


int main(){
    // initialize objects
    HugeInt n1( 7604321 );
    HugeInt n2( 8091034 );
    HugeInt n3( "99999999999999999999999999999" );
    HugeInt n4( "1" );
    HugeInt n5;
    HugeInt n6( 24 );
    HugeInt n7;
    HugeInt n8( "60402038122114" );
    HugeInt n9( 12345 );

    cout << "\nn1 is " << n1 << "\nn2 is " << n2
         << "\nn3 is " << n3 << "\nn4 is " << n4
         << "\nn5 is " << n5 << endl;

    /*   Arithmetic Operator Tests   ****************************************************************/
    // addition operator tests
    cout << "\n\nAddition operator tests ... \n\n";
    n5 = n1+n2;
    cout << n1 << " + " << n2 << " = " << n5 << "\n\n";
    cout << n3 << " + " << n4 << "\n= " << (n3+n4) << "\n\n";
    n5 = n1+9;
    cout << n1 << " + " << 9 << " = " << n5 << "\n\n";
    n5 = n2+"10000";
    cout << n2 << " + " << "10000" << " = " << n5 << endl;

    // subtraction operator tests
    cout << "\n\nSubtraction operator tests ... \n\n"
         << n1 << " - " << n2 << " = " << (n1-n2) << "\n\n"
         << n3 << " - " << n4 << "  = " << (n3-n4) << "\n\n"
         << n1 << " - " << 9 << " = " << (n1-9) << "\n\n"
         << n2 << " - " << "10000" << " = " << (n2-"10000") << endl;

    // multiplication operator tests
    cout << "\n\nMultiplication operator tests ... \n\n";
    cout << n2 << " * " << n6 << "\n= " << (n2*n6) << "\n\n";
    n7 = n1*n2;
    cout << n1 << " * " << n2 << "\n= " << n7 << "\n\n"
         << n2 << " * " << 254817 << "\n= " << (n2*254817) << "\n\n"
         << n1 << " * " << "9187234" << "\n= " << (n1*"9187234") << "\n\n"
         << n1 << " * " << n6 << " * " << 37 << " * " << "64" << "\n= " << (n1*n6*37*"64") << endl;

    // division operator tests
    cout << "\n\nDivision operator tests ... \n\n"
         << n2 << " / " << n6 << "\n= " << (n2/n6) << "\n\n"
         << n1 << " / " << n2 << "\n= " << (n1/n2) << "\n\n"
         << n2 << " / " << 254817 << "\n= " << (n2/254817) << "\n\n"
         << n1 << " / " << "9187234" << "\n= " << (n1/"9187234") << "\n\n"
         << n1 << " / " << n6 << " / " << 37 << " / " << "64" << "\n= " << (n1/n6/37/"64") << endl;

    /*   Relational Operator Tests   ****************************************************************/
    // equal operator tests
    cout << "\n\nEqual operator tests ... \n\n"
         << n7 << " == " << n8 << "\n= " << (n7==n8 ? "Equal" : "Not Equal") << "\n\n"
         << n3 << " == " << 17485789 << "\n= " << (n3==17485789 ? "Equal" : "Not Equal") << "\n\n"
         << n4 << " == " << "1" << "\n= " << (n4=="1" ? "Equal" : "Not Equal") << endl;

    // not equal operator tests
    cout << "\n\nUnequal operator tests ... \n\n"
         << n2 << " != " << n5 << "\n= " << (n2!=n5 ? "Not equal" : "Equal") << "\n\n"
         << n8 << " != " << 12345678910111213 << "\n= " << (n8!=12345678910111213 ? "Not equal" : "Equal") << "\n\n"
         << n5 << " != " << "7901234" << "\n= " << (n5!="7901234" ? "Not equal" : "Equal") << endl;

    // less operator tests
    cout << "\n\nLess than operator tests ... \n\n"
         << n8 << " < " << n9 << " = " << (n8<n9 ? "True" : "False") << "\n\n"
         << n5 << " < " << 9999999999 << " = " << (n5<9999999999 ? "True" : "False") << "\n\n"
         << n2 << " < " << "7891233" << " = " << (n2<"7891233" ? "True" : "False") << "\n\n"
         << n9 << " < " << "12345" << " = " << (n9<"12345" ? "True" : "False") << endl;

    // higher operator tests
    cout << "\n\nHigher than operator tests ... \n\n"
         << n8 << " > " << n9 << " = " << (n8>n9 ? "True" : "False") << "\n\n"
         << n5 << " > " << 9999999999 << " = " << (n5>9999999999 ? "True" : "False") << "\n\n"
         << n2 << " > " << "7891233" << " = " << (n2>"7891233" ? "True" : "False") << "\n\n"
         << n9 << " > " << "12345" << " = " << (n9>"12345" ? "True" : "False") << endl;

    // less or equal operator tests
    cout << "\n\nLess Equal operator tests ... \n\n"
         << n8 << " <= " << n9 << " = " << (n8<=n9 ? "True" : "False") << "\n\n"
         << n5 << " <= " << 9999999999 << " = " << (n5<=9999999999 ? "True" : "False") << "\n\n"
         << n2 << " <= " << "7891233" << " = " << (n2<="7891233" ? "True" : "False") << "\n\n"
         << n9 << " <= " << "12345" << " = " << (n9<="12345" ? "True" : "False") << endl;

    // higher or equal operator tests
    cout << "\n\nHigher Equal operator tests ... \n\n"
         << n8 << " >= " << n9 << " = " << (n8>=n9 ? "True" : "False") << "\n\n"
         << n5 << " >= " << 9999999999 << " = " << (n5>=9999999999 ? "True" : "False") << "\n\n"
         << n2 << " >= " << "7891233" << " = " << (n2>="7891233" ? "True" : "False") << "\n\n"
         << n9 << " >= " << "12345" << " = " << (n9>="12345" ? "True" : "False") << endl;


    return 0;
} // end main
