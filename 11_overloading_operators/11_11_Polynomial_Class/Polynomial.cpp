// Exercise 11.11: Polynomial.cpp
// Polynomial class member-function definitions
#include "Polynomial.h"

/** =======  Constructors and Destructor Definition  ==== =========================================== ============= ======= */
// explicit constructor
Polynomial::Polynomial( const int _size ){
    if (_size < 0)
        throw invalid_argument( "Size Error");

    size = _size; // set size
    ptr = new Term[_size]; // empty polynomial object
} // end Polynomial

// copy constructor
Polynomial::Polynomial( const Polynomial &data ){
    size = data.size;  // get the size
    ptr = new Term[size]; // new memory space

    // copy the object
    *this = data; // invoke operator=(Polynomial)

} // end Polynomial

// destructor
Polynomial::~Polynomial(){
    delete [] ptr; // release memory space
} // end ~Polynomial


/** ==========  Member Function Definitions    ============ ======================= =========================== ============ */
// simplify and reduce the expression
void Polynomial::reduce(){
        int reSize{0}; // new size of the polynomial

        // check Terms with coefficients different from 0
        for (int i{0}; i<size; ++i)
            if (ptr[i].getCoefficient() != 0){
                ++reSize; // increment the size of the new Polynomial

                // sum terms with the same exponent
                for (int j{i+1}; j<size; ++j)
                    if (ptr[j].getCoefficient() != 0 &&
                        ptr[i].getExponent() == ptr[j].getExponent()){
                        ptr[i].setCoefficient( ptr[i].getCoefficient() + ptr[j].getCoefficient() );
                        ptr[j].setCoefficient(0); // coefficient taken
                    }
            }

        // order the terms according to their exponent value
        if (reSize){ // avoid null assigment
            Polynomial reduced(reSize);

            // get the terms of the reduced polynomial
            for (int i{0}, max{-1}, id{0}; i<reSize; ++i){
                for (int j{0}; j < size; ++j) { // look for the maximum exponent
                    if (ptr[j].getCoefficient() != 0) {
                        if (max < ptr[j].getExponent()) {
                            max = ptr[j].getExponent(); // find the biggest exponent
                            id = j; // biggest exponent index
                        }
                    }
                }

                // copy the term with the biggest exponent
                reduced.ptr[i] = ptr[id]; // invoke operator=(Term)
                ptr[id].setCoefficient(0); // term taken
                max = -1; // reset max exponent
            }

            // rewrite the polynomial with the reduced form
            *this = reduced;  // invoke operator=(Polynomial)
        }
        else if (!reSize && size>1) // there is no terms in the polynomial
            *this = Polynomial(0); // invoke operator=(Polynomial)
} // end reduce

/** ============  BitWise Operators Definitions     ===  ============== ===================== ===================== ======== */
// overload input operator
istream& operator>>( istream &input, Polynomial &data ){
    // read the data
    for (int i{0}; i<data.size; ++i) {
        input >> data.ptr[i]; // read each term
    }

    data.reduce(); // simplify expression

    return input;
} // end operator>>

// overload output operator
ostream& operator<<( ostream &output, const Polynomial &data ){
    for (int i{0}; i<data.size; ++i) {
        output << data.ptr[i]; // print each term
    }

    return output;
} // end operator<<


/** ============  Assigment Operators Definitions     ===  ============== ===================== ===================== ======== */
// assigment operator; Polynomial=Polynomial
const Polynomial &Polynomial::operator=( const Polynomial &right ){
    if (this != &right){ // avoid self-assigment
        if (size != right.size){ // avoid redundant-assigment
            // resize the ptr
            delete [] ptr; // release space
            size = right.size; // resize this object
            ptr = new Term[size]; // create new space
        }

        // assign each term
        for (int i{0}; i<size; ++i)
            ptr[i] = right.ptr[i]; // invoke operator=(Term)
    }

    return *this;  // enables x = y = z
} // end operator=

// addition assigment operator; Polynomial+=Polynomial
const Polynomial &Polynomial::operator+=( const Polynomial &right ){
    *this = *this+right; // invoke operator+(Polynomial)
    return *this;
} // end operator+=

// subtraction assigment operator; Polynomial-=Polynomial
const Polynomial &Polynomial::operator-=( const Polynomial &right ){
    *this = *this-right; // invoke operator-(Polynomial)
    return *this;
} // end operator -=

// multiplication assigment operator*=
const Polynomial &Polynomial::operator*=( const Polynomial &right ){
    *this = *this*right; // invoke operator*(Polynomial)
    return *this;
} // end operator*=


/** ============  Arithmetic Operators Definitions     ===  ============== ===================== ===================== ======== */
// addition operator; Polynomial+Polynomial
Polynomial Polynomial::operator+( const Polynomial &right ) const{
    Polynomial result(size + right.size);

    // add *this to the result
    for (int i{0}; i<size; i++)
        result.ptr[i] = ptr[i];

    // add right to the result
    for (int i{size}; i<result.size; ++i)
        result.ptr[i] = right.ptr[i-size];

    result.reduce(); // simplify the expression

    return result; // return the result of the addition
} // end operator+

// subtracting operator; Polynomial-Polynomial
Polynomial Polynomial::operator-( const Polynomial &right ) const{
    Polynomial result(size+right.size);

    // add *this to the result
    for (int i{0}; i<size; ++i)
        result.ptr[i] = ptr[i];

    // add right to the result with a negative coefficients
    for (int i{size}; i<result.size; ++i){
        result.ptr[i] = right.ptr[i-size];
        result.ptr[i].setCoefficient( -result.ptr[i].getCoefficient() );
    }

    result.reduce(); // simplify the expression
    return result; // return the result of the subtraction
} // end operator-

// multiplying operator; Polynomial*Polynomial
Polynomial Polynomial::operator*( const Polynomial &right ) const{
    Polynomial result( size * right.size );

    // multiply the polynomials
    for (int i{0}, id{0}; i<size; ++i)
        for (int j{0}; j<right.size; ++j, ++id){
            result.ptr[id].setCoefficient( ptr[i].getCoefficient() * right.ptr[j].getCoefficient() );
            result.ptr[id].setExponent( ptr[i].getExponent() + right.ptr[j].getExponent());
        }

    result.reduce(); // simplify the expression
    return result; // return the result of the subtraction
} // end operator*