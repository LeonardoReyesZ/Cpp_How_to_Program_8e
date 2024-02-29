// Fig 11.18: Hugeint.cpp
// HugeInt member-function and friend-function definitions
#include <cctype> // isdigit function prototype
#include "Hugeint.h" // HugeInt class definition
using namespace std;


/** ========== Constructors Definitions  =========================================================================== */
// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt( long value ){
    // initialize array to zero
    for( int i=0; i<digits; ++i )
        integer[i] = 0;

    // place digits of argument into array
    for( int j=digits-1; value!=0 && j>=0; j-- ){
        integer[j] = value%10;
        value /=10;
    }
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string
// representing a large integer into a HugeInt object
HugeInt::HugeInt( const string &number ){
    // initialize array to zero
    for( int i=0; i<digits; ++i )
        integer[i] = 0;

    // place digits of argument into array
    int lenght = number.size();

    for( int j=digits-lenght, k=0; j<digits; ++j, ++k)
        if( isdigit(number[k])) // ensure that character is a digit
            integer[j] = number[k]-'0';
} // end HugeInt conversion constructor


/** ==========  Member Function Definitions  ================================================================== */
int HugeInt::leadingZeros() const{
    int lenght{0};

    // get the number of leading zeros
    for (lenght; lenght<digits && integer[lenght]==0; ++lenght) ;

    return lenght; // return the number of leading zeros
} // end leading zeros


/** ==========  Unary Operators Definitions  ================================================================== */
HugeInt &HugeInt::operator++(){
    int carry = 1; // Start with a carry of 1

    // Iterate through the digits from the least significant to the most significant
    for (int i = digits-1; i>=0 && carry; --i){
        int sum = integer[i] + carry; // Add the current digit and the carry
        integer[i] = sum % 10; // Update the current digit with the result modulo 10
        carry = sum / 10; // Update the carry for the next iteration
    }

    return *this; // Return reference to the modified object
} // end operator++


/** ==========  Assigment Operators Definitions  ================================================================== */
/*   -= Operator Definitions   ***********************************/
// operator -= ; HugeInt -= HugeInt
const HugeInt &HugeInt::operator-=( const HugeInt &right ){
    *this = (*this - right); // invoke operator-(HugeInt)
    return *this; // enables cascading
} // end operator-=

// operator -= ; HugeInt -= int
const HugeInt &HugeInt::operator-=( int right ){
    return *this -= HugeInt(right); // invoke operator-=(HugeInt)
}// end operator -=

// operator -= ; HugeInt -= string
const HugeInt &HugeInt::operator-=( const string &right ){
    return *this -= HugeInt(right); // invoke operator-=(HugeInt)
} // end operator -=

/*   *= Operator Definitions   ***********************************/
const HugeInt& HugeInt::operator*=(const HugeInt& right) {
    *this = *this * right; // invoke operator*(HugeInt)
    return *this; // Return a reference to the modified object
} // end operator*=

const HugeInt& HugeInt::operator*=( int right ){
    return *this *= HugeInt(right); // invoke operator*=(HugeInt)
} // end operator *=

const HugeInt& HugeInt::operator*=( const string &right ){
    return *this *= HugeInt(right); // invoke operator*=(HugeInt)
} // end operator *=


/** ==========  Arithmetic Operators Definitions  ================================================================== */
/*   Addition Operator Definitions   ***********************************/
// addition operator; HugeInt+HugeInt
HugeInt HugeInt::operator+( const HugeInt &op2 ) const{
    HugeInt temp; // temporary result
    int carry = 0;

    // sum each element of the objects
    for( int i=digits-1; i>=0; i-- ){
        temp.integer[i] = integer[i]+op2.integer[i]+carry;

        // determine whether to carry a 1
        if( temp.integer[i]>9 ){
            temp.integer[i] %= 10; // reduce to 0-9
            carry = 1; // carry a unit to the next significant value
        }
        else // no carry
            carry = 0;
    }

    return temp; // return copy of temporary object
} // end function operator+

// addition operator; HugeInt+int
HugeInt HugeInt::operator+( int op2 ) const{
    // convert op2 to a HugeInt, then invoke
    // operator+ for two HugeInt objects
    return *this + HugeInt(op2);
} // end function operator+

// addition operator;
// HugeInt + string that represents large integer value
HugeInt HugeInt::operator+( const string &op2 ) const{
    // convert opt2 to a HugeInt, then invoke
    // operator+ for two HugeInt objects
    return *this + HugeInt(op2);
} // end function operator+

/*   Subtraction Operator Definitions   ***********************************/
// subtraction operator; HugeInt-HugeInt
// (this) is going to be the minuend
HugeInt HugeInt::operator-(const HugeInt &subtrahend) const {
    HugeInt result; // result of subtraction
    bool negative = false; // flag to determine if the difference will be negative
    int limit = this->leadingZeros(); // last significant element of the minuend
    int carry = 0;  // necessary or not to borrow a unit

    // Check if the minuend is smaller than the subtrahend
    if (*this<subtrahend) {
        result = subtrahend - *this; // Subtract the minuend from the subtrahend and negate the result
        negative = true; // the result will be negative
    } else {
        // Subtract each element starting from the least significant one
        for (int i = digits-1; i>=0; --i) {
            result.integer[i] = integer[i] - subtrahend.integer[i] - carry;
            carry = 0; // after using the borrowed unit
            // If the result is negative and there are more significant digits to borrow from
            if (result.integer[i]<0 && i>limit) {
                // Perform borrowing
                result.integer[i] += 10; // units borrowed
                carry = 1; // unit to be taken from the next significant element
            }
        }
    }

    // If the difference is negative, change the sign of the most significant digit
    if (negative)
        result.integer[result.leadingZeros()] *= -1;

    return result; // Return the difference
}

// subtraction operator; HugeInt-int
HugeInt HugeInt::operator-( int subtrahend ) const{
    return *this - HugeInt(subtrahend); // invoke operator-(HugeInt)
} // end operator-

// subtraction operator; HugeInt - string
HugeInt HugeInt::operator-( const string &subtrahend ) const{
    return *this - HugeInt(subtrahend); // invoke operator-(HugeInt)
} // end operator-

/*   Multiplication Operator Definitions   ***********************************/
// multiplication operator; HugeInt * HugeInt
HugeInt HugeInt::operator*( const HugeInt &op2 ) const{
    HugeInt temp; // Temporary result

    // Multiply each digit of *this by each digit of op2
    for( int i = digits-1, k=0; i>=0; --i, ++k ){ // each digit of the multiplier
        for( int j = digits-1; j>=0; --j ){ // each digit of the integer to be multiply
            int product = (integer[j] * op2.integer[i]); // get the product
            temp.integer[j-k] += product; // sum the product to each element of the array
            if( temp.integer[j-k] > 9 && (j-k) >= 0 ){ // determine if we have to carry a value
                temp.integer[j-k-1] += temp.integer[j-k]/10; // carry to the next index
                temp.integer[j-k] %= 10; // reduce current value
            }
        }
    }

    return temp; // Return the result
} // end function operator*

// multiplication operator; HugeInt*int
HugeInt HugeInt::operator*( int op2) const{
    // convert op2 to a HugeInt, then invoke
    // operator* for two HugeInt objects
    return (*this * HugeInt(op2) );
} // end operator*

// multiplication operator; HugeInt*string
HugeInt HugeInt::operator*( const string &op2 ) const{
    // convert op2 to a HugeInt, then invoke
    // operator* for two HugeInt objects
    return (*this * HugeInt(op2) );
} // end operator*

/*   Division Operator Definitions   ***********************************/
// division operator; HugeInt / HugeInt
HugeInt HugeInt::operator/(const HugeInt &divisor) const {
    HugeInt quotient{}; // Result of division
    HugeInt dividend(*this); // copy the dividend

    // Check if the dividend is smaller than the divisor
    if (dividend < divisor)
        return quotient; // Return zero as the result

    // Perform division
    int digit = 0;

    while (dividend >= divisor) {
        dividend -= divisor; // subtract divisor from the dividend
        digit++; // increment the quotient digit
    }

    quotient = digit; // assign the quotient digit

    return quotient; // return the result
} // end operator/

// division operator; HugeInt / int
HugeInt HugeInt::operator/( int right ) const{
    return *this / HugeInt(right); // invoke operator(HugeInt)
} // end operator/

// division operator; HugeInt / string
HugeInt HugeInt::operator/( const string &right ) const{
    return *this / HugeInt(right); // invoke operator(HugeInt)
} // end operator/


/** ==========  Relational Operators Definitions  ================================================================== */
/*   Operator == Definitions   ***********************************/
// operator==; HugeInt == HugeInt
bool HugeInt::operator==( const HugeInt &right ) const{
    // compare each element in the objects
    for (int i{}; i<digits; ++i)
        if (integer[i] != right.integer[i])
            return false; // the objects are not equal

    return true; // the objects are equal
} // end operator==

// operator==; HugeInt == int
bool HugeInt::operator==( int right ) const{
    return *this == HugeInt(right); // convert right to a HugeInt
}

// operator==; HugeInt == string
bool HugeInt::operator==( const string &right ) const{
    return (*this == HugeInt(right)); // convert right to a HugeInt
} // end operator==

/*   Operator != Definitions   ***********************************/
// operator!=; HugeInt != HugeInt
bool HugeInt::operator!=( const HugeInt &right ) const{
    return ! (*this == right); // invoke operator==(HugeInt)
}  // end operator!=

// operator!=; HugeInt != int
bool HugeInt::operator!=( int right ) const{
    return ! (*this == right); // invoke operator==(int)
}  // end operator!=

// operator!=; HugeInt != string
bool HugeInt::operator!=( const string &right ) const{
    return ! (*this == right); // invoke operator==(string)
}  // end operator!=

/*   Operator < Definitions    ***********************************/
// operator<; HugeInt < HugeInt
bool HugeInt::operator<( const HugeInt &right ) const{
    // determine the size of each HugeInt
    int sizeLeft = this->leadingZeros();
    int sizeRight = right.leadingZeros();

    // determine if one HugeInt is smaller than the other by their leading zeros
    if (sizeLeft > sizeRight) // more leading zeros -> less value
        return true; // left value is smaller
    else if (sizeLeft < sizeRight) // less leading zeros -> more value
        return false; // right value is smaller

    // if the sizes are equal, compare each element starting from the most valuable one
    for (int i=sizeLeft; i<digits; ++i) // sizeLeft and sizeRight are equal
        if (integer[i] < right.integer[i])
            return true; // left value is smaller than the right one

        else if (integer[i] > right.integer[i])
            return false; // left value is bigger than the right one
        // continue with the next pair of values

   return false; // the numbers are equal
} // end operator<

// operator<; HugeInt < int
bool HugeInt::operator<( int right ) const{
    return *this < (HugeInt(right)); // invoke operator<(HugeInt)
} // end operator<

// operator<; HugeInt < string
bool HugeInt::operator<( const string &right ) const{
    return *this < (HugeInt(right)); // invoke operator<(HugeInt)
} // end operator<

/*   Operator > Definitions    ***********************************/
// operator>; HugeInt > HugeInt
bool HugeInt::operator>( const HugeInt &right ) const{
    if (*this == right) return false; // first verify that the objects are different

    return ! (*this < right); // invoke operator<(HugeInt)
} // end operator>

// operator>; HugeInt > int
bool HugeInt::operator>( int right ) const{
    return *this > HugeInt(right); // invoke operator>(HugeInt)
} // end operator>

// operator>; HugeInt > string
bool HugeInt::operator>( const string &right ) const{
    return *this > HugeInt(right); // invoke operator>(HugeInt)
} // end operator>

/*   Operator <= Definitions   ***********************************/
// operator <=; HugeInt <= HugeInt
bool HugeInt::operator<=( const HugeInt &right ) const{
    if (*this == right)
        return true; // this and right are equal

    if (*this < right)
        return true; // this is smaller than right

    return false; // this is not smaller or equal than right
} // end operator<=

// operator <=;  HugeInt <= int
bool HugeInt::operator<=( int right ) const{
    return *this <= HugeInt(right); // invoke operator<=(HugeInt)
} // end operator<=

// operator <=; HugeInt <= string
bool HugeInt::operator<=( const string &right ) const{
    return *this <= HugeInt(right); // invoke operator<=(HugeInt)
} // end operator<=

/*   Operator >= Definitions   ***********************************/
// operator >=; HugeInt >= HugeInt
bool HugeInt::operator>=( const HugeInt &right ) const{
    if (*this == right) // first check that the objects are different
        return true; // this and right are equal

    if (*this > right) // invoke operator>(HugeInt)
        return true; // this is higher than right

    return false; // this is not equal or higher than right
} // end operator>=

// operator >=; HugeInt >= int
bool HugeInt::operator>=( int right) const{
    return *this >= HugeInt(right); // invoke operator>=(HugeInt)
} // end operator >=

// operator >=; HugeInt >= string
bool HugeInt::operator>=( const string &right) const{
    return *this >= HugeInt(right); // invoke operator>=(HugeInt)
} // end operator >=


/** ==========  BitWise Operators Definitions  ================================================================== */
// overloaded output operator
ostream& operator<<( ostream &output, const HugeInt &num ){
    int i;

    for( i=0; (num.integer[i]==0) && (i<=HugeInt::digits); ++i )
        ; // skip leading zeros

    if( i==HugeInt::digits )
        output << 0;
    else
        for( ; i<HugeInt::digits; ++i )
            output << num.integer[i];

    return output;
} // end function operator<<
