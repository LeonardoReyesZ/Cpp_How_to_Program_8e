// Exercise 14.6: ex_14.6.cpp -> implementing a template function
// equally operator for fundamental types
#include <iostream>
using namespace std;

template< typename T >
bool isEqualTo( const T a, const T b)
{
    return a==b;
} // end isEqualTo

int main()
{
    cout << "1 == 2 ?  " << isEqualTo(1,2) << endl;
    cout << "12 == 12 ?  " << isEqualTo(12,12) << endl;
    cout << "1.2 == 2.7 ?  " << isEqualTo(1.2,2.7) << endl;
    cout << "6.9 == 6.9 ?  " << isEqualTo(6.9,6.9) << endl;
    cout << "S == C ?  " << isEqualTo('S','C') << endl;
    cout << "c == c ?  " << isEqualTo('c','c') << endl;

    return 0;
}
