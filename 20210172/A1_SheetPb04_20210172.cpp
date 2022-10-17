/*
FCAI - OOP - 2022 - Assignment #1
Author: Seif Yahia - 20210172
Program Name: Problem #4 - Binary Print
Last Modification Date: 17 October 2022
*/

#include <iostream>
#include <string>

using namespace std;

// Funcitons prototype
void binaryPrint(int);
void numbers(string, int);

int main(){
    cout << "Conversion from decimal to binary: ";
    binaryPrint(5);
    cout << "\nPattern:\n";
    numbers("00101", 2);
    return 0;
}

// Converts from decimal integer into binary number using recursion
void binaryPrint(int n){
    if(n > 1)
        { binaryPrint(n / 2); }
    cout << n % 2;
}

// Function to print many numbers depending on the prefix and k-digits suffix
void numbers(string prefix, int k){
    if(k == 0)
        { cout << prefix << endl; }
    else{
        // Print (2 ^ k) possible suffixes after the prefix
        numbers(prefix + "0", k - 1);
        numbers(prefix + "1", k - 1);
    }
}