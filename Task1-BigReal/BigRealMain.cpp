/*
FCAI - OOP - 2022 - Assignment #2
Team Members:
    Seif Yahia    - 20210172
    Omar Elgammal - 20210271
    Mohamed Amgad - 20210330
Program Name: Big Real Program
Last Modification Date: 29 October 2022
Version: 1.0
*/

#include "BigRealClass.hpp"

int main(){
    // Should print INVALID FORMAT!!
    BigReal n0("+124857.+38383");
    BigReal n1("1.1.1");
    // Should print nothing
    BigReal n2(+5.290392);
    BigReal n3("-34.00000003");
    BigReal n4("11.9000000000000000000000000000000001");
    BigReal n5("2333333333339.1134322222222292");
    // Testing the assignment operator
    cout << "\nTesting the assignment operator!\n";
    BigReal n7;
    BigReal n8("+45673.000038483");
    n7 = n8;
    cout << "Value of n7 is " << n7.getRealStr() << endl;
    cout << "Value of n8 is " << n8.getRealStr() << endl;
    // Testing the copy constructor
    cout << "\nTesting the copy constructor!\n";
    BigReal tst1("124.55");
    BigReal tst2(tst1);
    cout << "Value of tst1 is " << tst1.getRealStr() << endl;
    cout << "Value of tst2 is " << tst2.getRealStr() << endl;
    return 0;
}