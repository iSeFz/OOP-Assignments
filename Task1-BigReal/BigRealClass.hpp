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
        BigDecimalInt modifiedReal;
        // Store the point position to preserve it
        int pointPosition;
        // Check if the input is valid or not
        bool isValidInput(string bigStr);
        // Remove the decimal point before passing the number to the BigDecimalInt class
        void removeDecimalPoint(string & realStr);
        // Return the decimal point to its original position after making operations
        string returnPoint();
    public:
        // Getter function to get the modifiedReal value
        BigDecimalInt & getModifiedReal();
        // Default constructor function that accept double as parameter
        BigReal(double real = 0.0);
        // Overload the constructor function to accept string as parameter
        BigReal(string real);
        // Overload the constructor function to accept BigDecimalInt objects as parameter
        BigReal(BigDecimalInt bigInteger);
        // Copy constructor to copy objects into each other
        BigReal(const BigReal & other);
        // Move constructor to move object into another object
        BigReal(BigReal && other);
        // Overload the assignment operator to assign values to modifiedReal
        BigReal & operator = (BigReal & other);
        // Move Assignment to move object into another object
        BigReal & operator = (BigReal && other);
        // Overload the plus operator to work with BigReal objects
        BigReal operator + (BigReal & other);
        // Overload the minus operator to work with BigReal objects
        BigReal operator - (BigReal & other);
        // Overload the less than "<" operator to work with BigReal objects
        bool operator < (BigReal & anotherReal);
        // Overload the greater than ">" operator to work with BigReal objects
        bool operator > (BigReal & anotherReal);
        // Overload the equality "==" operator to check if the two numbers are equal
        bool operator == (BigReal & anotherReal);
        // Return size of BigReal
        int size();
        // Return sign of BigReal
        int sign();
        // Declare friend functions to have access to all class data members
        friend ostream & operator << (ostream & out, BigReal & real);
        friend istream & operator >> (istream & in, BigReal & real);
};

// Overload the exertion operator "<<" to print objects
ostream & operator << (ostream & out, BigReal & real);
// Overload the insertion operator ">>" to take input
istream & operator >> (istream & in, BigReal & real);

#endif