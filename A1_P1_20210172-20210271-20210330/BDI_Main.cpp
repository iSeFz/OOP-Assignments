/*
FCAI - OOP - 2022 - Assignment #1
Team Members:
    Seif Yahia    - 20210172
    Omar Elgammal - 20210271
    Mohamed Amgad - 20210330
Program Name: Big Decimal Integer Program
Last Modification Date: 13 October 2022
Version: 1.5
*/

#include "BDI_Lib.cpp"

int main(){
    // Test cases to check for the correct number format
    // Initializes from string & rejects bad input
    BigDecimalInt num1("-123456789012345678901234567890"); // valid BigDecimalInt
    // Initialize from integer
    BigDecimalInt num2(54033); // Invalid integer in this case
    return 0;
}