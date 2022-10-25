/*
FCAI - OOP - 2022 - Assignment #1
Team Members:
    Seif Yahia    - 20210172
    Omar Elgammal - 20210271
    Mohamed Amgad - 20210330
Program Name: Big Decimal Integer Program
Last Modification Date: 25 October 2022
Version: 4.0
*/

#include "BDI_Header.hpp"

int main(){
    // Sheet test cases:
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("+113456789011345678901134567890");
    BigDecimalInt num4 = num2 + num1;
    BigDecimalInt num5 = num2 - num1;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    // Next statement will print 236913578023691357802369135780
    cout << "num2 + num1 = " << num4 << endl;
    // Next statement will print -10000000001000000000100000000
    cout << "num2 - num1 = " << num5 << endl;

    // Our test cases
    BigDecimalInt test1(3040);
    BigDecimalInt test2("-44429377737373787339304");
    BigDecimalInt test3("+999938738732133");
    BigDecimalInt test4("-1033720303003003030");
    BigDecimalInt test5(-19999);
    BigDecimalInt result1 = test2 - test5;
    BigDecimalInt result2 = test3 - test4;
    // The next statement will print 999938738732133
    cout << "test3 = " << test3 << endl;
    // The next statement will print −44428344017070784336274
    cout << "test2 - test4 = " << test2 - test4 << endl;
    // The next statement will print 1034720241741735163
    cout << "test3 - test4 = "<< result2 << endl;
    // The next statement will print −1033720303002999990
    cout << "test1 + test4 = " << test1 + test4 << endl;
    // The next statement will print -44429377737373787319305
    cout << "test2 - test5 = " << result1 << endl;
    // The next statement will print true
    cout << "test1 > test2 is " << std::boolalpha << (test1 > test2) << endl;
    // The next statement will print false
    cout << "test4 > test3 is " << std::boolalpha << (test4 > test3) << endl;
    return 0;
}