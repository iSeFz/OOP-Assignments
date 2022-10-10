/*
FCAI - OOP - 2022 - Assignment #1
Author: Seif Yahia - 20210172
Program Name: Problem #7 - Teddy Bear Picnic
Last Modification Date: 10 October 2022
*/

#include <iostream>

using namespace std;

// Function prototype
bool bearPicnic(int);

int main(){
    int bears;
    cout << "Welcome to the Teddy Bear Picnic!!\n";
    cout << "Enter number of bears to start with: ";
    cin >> bears;
    // Ternary operator check for win/lose status
    bearPicnic(bears) ? cout << "You WIN!!\n" : cout << "You Lose!\n";
    return 0;
}

// Check if it is possible to win the game by "n" bears or not
bool bearPicnic(int n){
    int check = (n % 10) * ((n % 100) / 10);
    if(n < 42)
        { return false; }
    else if(n == 42)
        { return true; }
    // If n is even, give back half of the bears
    else if(n % 2 == 0 && bearPicnic(n / 2))
        { return true; }
    // If n is divisible by 3 OR 4, give back the 
    // multiplication of the last two digits of n
    else if((n % 3 == 0 || n % 4 == 0) && check && bearPicnic(n - check))
        { return true; }
    // If n is divisible by 5, give back exactly 42 bears
    else if(n % 5 == 0 && bearPicnic(n - 42))
        { return true; }
    else
        return false;
}