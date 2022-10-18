#include<iostream>
using namespace std;

void pattern(int stars, int spaces)
{
    if(stars == 0)
        return;

    if(stars%2 == 0)
    {
        pattern(stars - stars/2,spaces);
        // printing spaces
        for (int j = 0; j < spaces; ++j)
            cout << "  ";
        // printing stars  
        for(int j = 0;j<stars;j++)
            cout << "* ";
        cout << endl;
        // recursive call to print reflection of shape above number of stars
        pattern(stars - stars/2,spaces + stars/2);
    }
    else
    {
        for (int j = 0; j < spaces; ++j) 
            cout << "  ";
        cout << "*";
        cout << endl;
    }
}



int main()
{
    // test case exist in sheet
    pattern(8,0);
    return 0;
}
