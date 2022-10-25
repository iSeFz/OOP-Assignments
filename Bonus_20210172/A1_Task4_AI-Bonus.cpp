/*
FCAI - OOP - 2022 - Assignment #1
Author: AI GitHub Copilot - Seif Yahia (20210172)
Program Name: Problem #4 - AI Generated Binary Print
Last Modification Date: 24 October 2022
*/

#include <iostream>
#include <string>

using namespace std;

// Function to convert decimal to binary using recursion without local variables
void decToBinary(int n, string &binary)
{
    if (n > 0)
    {
        decToBinary(n / 2, binary);
        binary += to_string(n % 2);
    }
}

// Main Function
int main()
{
    // Variable Declaration
    int n;
    string binary = "";

    // Input
    cout << "Enter a number: ";
    cin >> n;

    // Process
    decToBinary(n, binary);

    // Output
    cout << "Binary: " << binary << endl;
    return 0;
}