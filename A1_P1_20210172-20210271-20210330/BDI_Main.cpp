/*
FCAI - OOP - 2022 - Assignment #1
Team Members:
    Seif Yahia    - 20210172
    Omar Elgammal - 20210271
    Mohamed Amgad - 20210330
Program Name: Big Decimal Integer Program
Last Modification Date: 14 October 2022
Version: 3.0
*/

#include "BDI_Header.hpp"

int main(){
    // Test cases:
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("+113456789011345678901134567890");
    BigDecimalInt num4 = num2 + num1;
    // BigDecimalInt num5 = num2 - num1;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    //Next statement will print 236913578023691357802369135780
    cout << "num2 + num1 = " << num4 << endl;
    //Next statement will print -313456789011345678901134567890
    // cout << "num2 - num1 = " << num5 << endl;
    return 0;
}