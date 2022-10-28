#ifndef BIGREALCLASS_HPP
#define BIGREALCLASS_HPP

#include <iostream>
#include <string>
#include <regex>
#include "BigDecimalIntClass.h"
using namespace std;

// Main class that contain all program features
class BigReal{
    // Private section that contain data members and private functions
    private:
        string realStr;
        bool isValidInput(string bigStr);
    public:
        // Getter function to get the value of realStr
        string getRealStr();
        // Setter function to set the value of realStr
        void setRealStr(string newReal);
        // Default constructor function that accept double as parameter
        BigReal(double real = 0.0);
        // Overload the constructor function to accept string as parameter
        BigReal(string real);
        // Overload the constructor function to accept BigDecimalInt objects as parameter
        BigReal(BigDecimalInt bigInteger);
        // Copy constructor
        BigReal(const BigReal & other);
        // Move constructor
        BigReal(BigReal && other);
        // Overload the assignment operator to assign values to realStr
        BigReal & operator = (BigReal & other);
        // Move Assignment
        BigReal & operator = (BigReal && other);
        // Overloading the plus operator to work with BigReal objects
        BigReal operator + (BigReal & other);
        // Overloading the minus operator to work with BigReal objects
        BigReal operator - (BigReal & other);
        // Overloading the less than "<" operator to work with BigReal objects
        bool operator < (BigReal anotherReal);
        // Overloading the greater than ">" operator to work with BigReal objects
        bool operator > (BigReal anotherReal);
        // Overloading the equality "==" operator to check if the two numbers are equal
        bool operator == (BigReal anotherReal);
        // Function to return size of BigReal
        int size();
        // Function to return sign of BigReal
        int sign();
        // Declare friend functions to have access to all class data members
        friend ostream & operator << (ostream & out, BigReal real);
        friend istream & operator >> (istream & in, BigReal real);
};

// Overloading the exertion operator "<<" to print objects
ostream & operator << (ostream & out, BigReal real);
// Overloading the insertion operator ">>" to take input
istream & operator >> (istream & in, BigReal real);

#endif