/*
FCAI - OOP - 2022 - Assignment #2
Team Members:
    Seif Yahia    - 20210172
    Omar Elgammal - 20210271
    Mohamed Amgad - 20210330
Program Name: Big Real Program
Last Modification Date: 6 November 2022
Version: 5.0
*/

#include "BigRealClass.hpp"

int main(){
    // Sheet test case
    BigReal n1 ("11.9000000000000000000000000000000001");
    BigReal n2 ("2333333333339.1134322222222292");
    BigReal n3 = n1 + n2; // 2333333333351.013432222
    cout << n1 <<  " + " << n2 << " = " << n3 << endl;
    n3 = n1 - n2; // −2333333333327.213432222
    cout << n1 <<  " - " << n2 << " = " << n3 << endl;

    // To Do : Copy and Move constructors
    /*
    // n3 = (n3 + BigReal (0.9));
    // cout << "n3 + 0.9 = " << endl;
    // Testing insertion operator
    BigReal test2;
    cin >> test2;
    // Testing exertion operator
    cout << test2;
    */

    // Our test case
    BigReal a("-005546.0066");
    BigReal b("006845.1200");
    BigReal c, d;
    c = a + b; // 1299.1134
    d = a - b; // -12391.1266
    cout << a << " + " << b << " = " << c << endl;
    cout << a << " - " << b << " = " << d << endl;
    return 0;
}