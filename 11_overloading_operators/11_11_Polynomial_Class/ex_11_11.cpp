// Fig 11.11: ex_11_11.cpp
// Polynomial class tests
#include <iostream>
#include "Polynomial.h"
using namespace std;

int main(){
    Polynomial obj(6), obj2(6), obj3(6);

    cout << "Enter the data for obj:" << endl;
    cin >> obj;

    cout << "\nEnter the data for obj2:" << endl;
    cin >> obj2;

    cout << "obj = " << obj << endl
         << "obj2 = " << obj2 << "\n\n";

    obj3 = obj+obj2; // invoke operator+(Polynomial)
    cout << obj << " + " << obj2 << " = " << obj3 << "\n\n";
    cout << obj << " - " << obj2 << " = " << obj-obj2 << "\n\n"; // invoke operator-(Polynomial)
    cout << obj << " * " << obj2 << " = " << obj*obj2 << "\n\n"; // invoke operator*(Polynomial)
    cout << obj << " += " << obj2 << " = " << (obj+=obj2) << "\n\n"; // invoke operator+=(Polynomial)
    cout << obj << " -= " << obj2 << " = " << (obj-=obj2) << "\n\n"; // invoke operator-=(Polynomial)
    cout << obj << " *= " << obj3 << " = " << (obj*=obj3) << "\n\n"; // invoke operator*=(Polynomial)

    cout << obj << " + " << obj2 << " - " << obj3 << " * " << obj2 << " = " << (obj+obj2-obj3*obj) << "\n\n";

    return 0;
}
