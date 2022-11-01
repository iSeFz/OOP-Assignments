/*
FCAI - OOP - 2022 - Assignment #2
Team Members:
    Seif Yahia    - 20210172
    Omar Elgammal - 20210271
    Mohamed Amgad - 20210330
Program Name: Big Real Program
Last Modification Date: 1 November 2022
Version: 3.0
*/

#include "BigRealClass.hpp"

int main(){
    // Should print INVALID NUMBER FORMAT!!
    BigReal n0("+124857.+38383");
    BigReal n1("1.1.1");
    
    // Should print nothing
    BigReal n2(+5.290392);
    BigReal n3("-34.00000003");
    BigReal n4("11.9000000000000000000000000000000001");
    BigReal n5("2333333333339.1134322222222292");
    
    // Testing the copy assignment operator
    cout << "\nTesting the assignment operator!\n";
    BigReal n7("+45673.000038483");
    BigReal n8, n9;
    n9 = n8 = n7;
    cout << "Value of n7 is " << n7 << endl;
    cout << "Value of n8 is " << n8 << endl;
    cout << "Value of n9 is " << n9 << endl;
    
    // Testing the copy constructor
    cout << "\nTesting the copy constructor!\n";
    BigReal tst1("124.55");
    BigReal tst2(tst1);
    cout << "Value of tst1 is " << tst1 << endl;
    cout << "Value of tst2 is " << tst2 << endl;
    
    /*// Testing the move assignment operator
    cout << "\nTesting the move assignment operator\n";
    BigReal a("50034.775");
    BigReal b = a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    
    // Testing the move constructor
    cout << "\nTesting the move constructor\n";
    BigReal c("-6034.00915");
    BigReal d = c;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;*/

    // Testing insertion operator
    BigReal test2;
    cin >> test2;
    // Testing exertion operator
    cout << test2;
    return 0;
}