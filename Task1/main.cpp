/*
FCAI - OOP - 2022 - Assignment #3
Team Members:
    Seif Yahia    - 20210172
    Mohamed Amgad - 20210330
Program Name: MSVector
Last Modification Date: 11 December 2022
Version: 1.5
*/

#include "msVector.hpp"

int main(){
    MSVector <string> v1(4);
    v1.push_back((string) "seif");
    v1.push_back((string) "lol");
    v1.push_back((string) "amgad");
    v1.push_back((string) "waw");
    cout << "Capcity before adding: " << v1.Capacity() << endl; // 4
    v1.push_back((string) "testing");
    cout << "Capcity after adding: " << v1.Capacity() << endl; // 8
    cout << "Size after adding: " << v1.Size() << endl; // 5
    cout << "v1 contents: " << v1; // seif lol amgad waw testing
    v1[3] = (string) "tryhard";
    cout << "v1 contents: " << v1; // seif lol amgad tryhard testing
    MSVector<string> v2 = v1;
    cout << "v2 contents: " << v2; // seif lol amgad tryhard testing
    cout  << std::boolalpha << "Result of equality operator: " << (v1 == v2) << endl; // true
    v2[2] = "Salam Alykum231";
    cout << "v2 contents: " << v2; // seif lol Salam Alykum231 tryhard testing
    cout  << std::boolalpha << "Result of less than operator: " << (v1 < v2) << endl; // true
    v2.push_back("new");
    cout << "Size after adding: " << v2.Size() << endl; // 6
    cout << "v1 contents: " << v1; // seif lol amgad tryhard testing
    cout << "v2 contents: " << v2; // seif lol Salam Alykum231 tryhard testing new

    cout << "Clearing v2\n";
    v1.Clear();
    cout << "Current Size: " << v1.Size() << endl;
    cout << "v1 contents: " << v1 << endl;
}
