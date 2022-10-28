#include "BigRealClass.hpp"

// Getter function to get the value of realStr
string BigReal :: getRealStr(){ return realStr; }

// Setter function to set the value of data member
void BigReal :: setRealStr(string newReal){ realStr = newReal; }

// Function to check if the input is valid or not
bool BigReal :: isValidInput(string bigStr)
    { return (regex_match(bigStr, regex("^[+-]?[0-9]+[.]?[0-9]*$"))); }

// Default constructor function that accept double as parameter
BigReal :: BigReal(double real){
    // Check for its format before assigning it to the data member
    if (!isValidInput(to_string(real)))
        { cerr << "INVALID FORMAT!!\n"; }
    // Assign the value of double to the realStr
    realStr = to_string(real);
}

// Overload the constructor function to accept string as parameter
BigReal :: BigReal(string real){
    // Check for its format before assigning it to the data member
    if (!isValidInput(real))
        { cerr << "INVALID FORMAT!!\n"; }
    // Assign the value of string to the realStr
    realStr = real;
}

// Copy constructor to copy objects into each other
BigReal :: BigReal(const BigReal & other){
    // Create a new pointer to the realStr
    string * realNum = new string;
    // Assign the value of the passed object to the pointer
    *realNum = other.realStr;
    // Assign the value of the pointer to the realStr
    realStr = *realNum;
    // Delete the pointer to avoid memory leak
    delete realNum;
}

// Overload the assignment operator to assign values to realStr
BigReal & BigReal :: operator = (BigReal & other){
    realStr = other.getRealStr();
    // Return the lvalue, assuming num1 = num2, return "num1"
    return *this;
}
