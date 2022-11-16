// problem #1: Function solver
// Author: Omar Mohamed Elgammal - FCAI
// Description: A set of classes that allows you to build and modify
//              and solve functions at runtime.

// Importing necessary libraries
#include <iostream> 
#include <functional>
#include <cmath>
using namespace std;

// Parent class
class Function{
    virtual double evaluateAt(double value) = 0;
};

// Simple function that accepts a regular function and returns double value
class SimpleFunction : public Function {
    private:
        function<double(double)> func;
    public:

        // Constructor that assigns the function
        SimpleFunction(function<double(double)> fun) {
            func = fun;
        }

        // Function that evaluates the function at a given value
        double evaluateAt(double value){
            return func(value);
        }
};

// Function that is defined as func1(func2(value))
class CompositeFunction : public Function {
    private:
        function<double(double)> func1;
        function<double(double)> func2;
    public:

        // Constructor that assigns the functions
        CompositeFunction(function<double(double)> fun1, function<double(double)> fun2){
            this->func1 = fun1;
            this->func2 = fun2;
            
        }

        // Function that evaluates the function at a given value
        double evaluateAt(double value){
            return func1(func2(value));
        }

};

// Function that returns the value of its derivative
class DerivativeFunction : public Function {
    private:
        function<double(double)> func;
        double deltaX;
    public:

        // Constructor that assigns the function and deltaX
        DerivativeFunction(function<double(double)> fun, double deltaX) {
            this->func = fun;
            this->deltaX = deltaX;
        }

        // Returns the derivative of the function by using linear approximation formula
        double evaluateAt(double value){ // F'(x) ≈ (F(x + Δx) – F(x - Δx)) / 2Δx
            double result = ((func(value + deltaX) - func(value - deltaX)) / (2 *deltaX));
            return result;
        }
};

// Predefined functions:
double cube (double n) { // returns n^3 
   return n * n * n; 
} 

// Sample function
double second (double d) { 
    return d * d - 5 * d - 4; 
} 

// Sample function
double fun (double d) { 
    return d * d - 3 * d - 4; 
}


double absolute(double x){ // returns |x|
    if(x < 0)
        return -x;
    else
        return x;
}

int main() 
{
    SimpleFunction f1([](double n) -> double {return n * n;}); 
    cout << f1.evaluateAt(5) << endl; // 25
    DerivativeFunction f2 (second, 5);   
    cout << f2.evaluateAt(5) << endl; // 5
    CompositeFunction f3 (fun, cube); 
    cout << f3.evaluateAt(5) << endl; // 15246
    return 0; 
}