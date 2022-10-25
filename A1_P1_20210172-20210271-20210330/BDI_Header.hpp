#ifndef BDI_HEADER_HPP
#define BDI_HEADER_HPP

#include <iostream>
#include <string>
#include <regex>
using namespace std;

// Main class that contain all program features
class BigDecimalInt{
    // Private section that contain data members and private functions
    private:
        string decStr;
        // Setter function to set the value of data member
        void setDecStr(string);
        // Getter function to access the private data member
        string getDecStr();
        // Function to invert sign of BigDecimalInt
        BigDecimalInt invertSign(BigDecimalInt);
    public:
        // Constructor function to check for the format of the entered number
        BigDecimalInt(string);
        // Overloading the constructor function to accept input as integer
        BigDecimalInt(int);
        // Function to return size of BigDecimalInt
        int size();
        // Function to return sign of BigDecimalInt
        int sign();
        // Overloading the plus operator to work with BigDecimalInt objects
        BigDecimalInt operator + (BigDecimalInt);
        // Overloading the minus operator to work with BigDecimalInt objects
        BigDecimalInt operator - (BigDecimalInt);
        // Overloading the less than "<" operator to work with BigDecimalInt objects
        bool operator > (BigDecimalInt);
        // Overloading the less than "<" operator to work with BigDecimalInt objects
        bool operator < (BigDecimalInt);
        // Overloading the equality "==" operator to check if the two numbers are equal
        bool operator == (BigDecimalInt);
        // Overloading the assignment "=" operator to deal with objects
        BigDecimalInt operator = (BigDecimalInt);
        // Declare friend function to have access to all class data members
        friend ostream & operator << (ostream&, BigDecimalInt);
};

// Overloading the exertion operator "<<" to print objects
ostream & operator << (ostream&, BigDecimalInt);

#endif