// Exercise 11.11: Term.cpp
// Term class member-function definitions
#include "Term.h"

/** =======  Constructors Definition  =================== =========================================== ============= ======= */
// constructor
Term::Term( const int _coefficient, const int _exponent ){
    setCoefficient(_coefficient);
    setExponent(_exponent);
} // end Term


/** ==========  Member Function Definitions    ============ ======================= =========================== ============ */
void Term::setCoefficient( const int _coefficient ){
    coefficient = _coefficient;
} // end setCoefficient

void Term::setExponent( const int _exponent ){
    exponent = _exponent;
} // end setExponent

int Term::getCoefficient() const{
    return coefficient;
} // end getCoefficient

int Term::getExponent() const{
    return exponent;
} // end getExponent


/** ============  BitWise Operators Definitions     ===  ============== ===================== ===================== ======== */
// overload input operator
istream& operator>>( istream &input, Term &data ){
    cout << "coefficient (int): ";
    input >> data.coefficient;
    cout << "exponent (int): ";
    input >> data.exponent;

    while (data.exponent < 0){
        cout << "The exponent can not be negative ... try again\n";
        cout << "exponent (int): ";
        input >> data.exponent;
    }

    return input; // enable cin >> x >> y >> z
} // end operator>>

// overload output operator
ostream& operator<<( ostream &output, const Term &data ){
    if ( data.coefficient ) {
        if ( abs(data.coefficient)==1 && data.exponent )
            output << ( data.coefficient<0 ? '-' : '+' );
        else
            output << showpos << data.coefficient << noshowpos;

        if ( data.exponent ) {
            output << data.variable;
            if ( data.exponent != 1 )
                output << '^' << data.exponent;
        }
    }

    return output; // enable cout << x << y << z
} // end operator<<


/** ============  Assigment Operators Definitions     ===  ============== ===================== ===================== ======== */
// assigment operator=; Term = Term
const Term &Term::operator=( const Term &right ){
    if (this != &right){
        coefficient = right.coefficient; // set new value
        exponent = right.exponent; // set new value
    }

    return *this; // enables x = y = z
} // end operator=