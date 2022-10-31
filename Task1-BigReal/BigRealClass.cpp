#include "BigRealClass.hpp"


// Function to check if the input is valid or not
bool BigReal :: isValidInput(string bigStr)
    { return (regex_match(bigStr, regex("^[+-]?[0-9]+[.]?[0-9]*$"))); }

// Default constructor function that accept double as parameter
BigReal :: BigReal(double real){
    // Check for its format before assigning it to the data member
    if (!isValidInput(to_string(real)))
        { cerr << "INVALID FORMAT!!\n"; }
    // Assign the value of double to the realStr
    string realStr = to_string(real);
    removeDecimalPoint(realStr);
}

// Overload the constructor function to accept string as parameter
BigReal :: BigReal(string real){
    // Check for its format before assigning it to the data member
    if (!isValidInput(real))
        { cerr << "INVALID FORMAT!!\n"; }
    // Assign the value of string to the realStr
    removeDecimalPoint(real);
}
// Overload the equality operator
bool BigReal:: operator == (BigReal & anotherReal){
    if(modifiedReal == anotherReal.modifiedReal)
        return true;
    return false;
}

// Overload the exertion operator to print BigReal in console
ostream & operator << (ostream & out, BigReal & real){
    // if number is negative
    if(!real.sign())
        out << '-';
    out << real.returnPoint();
    return out;
}
// Overload the insertion operator to take input from user and initialize BigReal
istream & operator >> (istream & in, BigReal & real){
    string realStr;
    in >> realStr;
    real.removeDecimalPoint(realStr);
    return in;
}

// Sign function
int BigReal:: sign(){
    return modifiedReal.Sign();
}
// Function to remove decimal point and store its position
void BigReal:: removeDecimalPoint(string & realStr){
    pointPosition =  realStr.find('.');
    string realWithoutPoint;
    // case if real number entered with sign char
    if(realStr[0] == '+' || realStr[0] == '-'){
        realWithoutPoint = realStr.erase(pointPosition,1);
        pointPosition--; // to take sign position in consideration
    }
    else{
        realWithoutPoint = realStr.erase(pointPosition,1);
    }
    modifiedReal = BigDecimalInt(realWithoutPoint);
}

// Function to return decimal point to its original position
string BigReal:: returnPoint(){
    string realNumber = modifiedReal.getnum();
    // return decimal point to its original position
    realNumber.insert(pointPosition, ".");
    return realNumber;
}