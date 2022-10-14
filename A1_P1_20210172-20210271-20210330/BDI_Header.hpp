#ifndef BDI_HEADER_HPP
#define BDI_HEADER_HPP

#include <iostream>
#include <string>
#include <regex>
using namespace std;

//Main class that contain all library feature
class BigDecimalInt{
    // private section that contain data members and some getters & setters
    private:
        string decStr;
        // accessor
        void setDecStr(string diffStr);
        // mutator
        string getDecStr();
        // Function to invert sign of number
        BigDecimalInt inv(BigDecimalInt x);
    public:
        // Constructor function to initialize data member
        BigDecimalInt(string decString);
        // overloading for constructor function to take number as int
        BigDecimalInt(int decInt);
        // Function to return size of number
        int size();
        // Function to return sign of number
        int sign();
        // Overloading the plus operator to work with BigDecimalInt objects
        BigDecimalInt operator + (BigDecimalInt & anotherDec);
        // Overloading the minus operator to work with BigDecimalInt objects
        BigDecimalInt operator- (BigDecimalInt & anotherDec);
        // Overloading the less than "<" operator to work with BigDecimalInt objects
        bool operator > (BigDecimalInt & anotherDec);
        // Overloading the less than "<" operator to work with BigDecimalInt objects
        bool operator < (BigDecimalInt & anotherDec);
        // Overload the equality "==" operator to check if the two numbers are equal
        bool operator == (BigDecimalInt anotherDec);
        // Overload the equal "=" operator to deal with objects
        BigDecimalInt operator = (BigDecimalInt anotherDec);
        // Overload the exertion operator "<<" to print objects
        friend ostream & operator << (ostream & out, BigDecimalInt b);
};

ostream & operator << (ostream & out, BigDecimalInt b);

#endif