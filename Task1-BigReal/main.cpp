/*
FCAI - OOP - 2022 - Assignment #2
Team Members:
    Seif Yahia    - 20210172
    Omar Elgammal - 20210271
    Mohamed Amgad - 20210330
Program Name: Big Real Program
Last Modification Date: 4 November 2022
Version: 4.5
*/

#include "BigRealClass.hpp"

int main()
{
    // 5546.5466 + 6845.12 = 12,391.6666
    BigReal a("00779.00990100");
    BigReal b("00022.99009900");
    BigReal c, d;
    c = a + b;
    d = a - b;
    cout << a << " + " << b << " = " << c << endl;
    cout << a << " - " << b << " = " << d << endl;

    /*
    // Sheet test case
    BigReal n1 ("11.9000000000000000000000000000000001");
    cout << "n1 = " << n1 << endl;
    BigReal n2 ("2333333333339.1134322222222292");
    cout << "n2 = " << n2 << endl;
    // Should print 2333333333351.013432222
    // But it needs some SAD fixing
    BigReal n3 = n1 + n2;
    cout << "n1 + n2 = " << n3 << endl;
    n3 = (n3 + BigReal (0.9));
    cout << "n3 + 0.9 = " << endl;
    */
    return 0;
}