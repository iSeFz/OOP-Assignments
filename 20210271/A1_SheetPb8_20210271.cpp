// Assume that array class is modern C++ is not created yet. We want to create a smarter version of the
// normal arrays that is aware of its size. Create this as a template class with the following features:
// The smart array takes a type parameter to decide the type it will contain.
// The smart array keeps track of its current size.
// It has a destructor that frees any heap storage allocated by the smart array.
// It has a method size ( ) that returns the number of elements in the array.
// overriding the bracket-selection operator, which has the following prototype:
// int & operator[] (int k) ;
// Your implementation of operator [ ] should check to make sure that the index k is valid.
// You should return the appropriate element in the internal array by reference so that clients can
// assign a new value to a selection expression.
// Overload the assignment operator to copy and array and implement deep copying. See page 551 for
// details in Programming Abstractions book.
// Implement a copy constructor that takes another array of the same type and creates an identical one
// with copies of the values in the original array.
// Write a program to test the array on different types.
#include <iostream>
#include <cstdlib>
using namespace std;
template <class T>
class SmartArray {
private:
    T *array;
    int arraySize;
public:
    SmartArray(int size){
    array = new T[size];
    arraySize = size;
}
    ~SmartArray(){
    delete[] array;
}
    int size(){
    return arraySize;
}
    int & operator[](int k){
    if (k >= arraySize) {
        cout << "Error: Index out of range." << endl;
        exit(1);
    }
    return array[k];
}
    void append(T value){
    T *newArray = new T[arraySize + 1];
    for (int i = 0; i < arraySize; i++) {
        newArray[i] = array[i];
    }
    newArray[arraySize] = value;
    delete[] array;
    array = newArray;
    arraySize++;
}
    void print(){
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
};

// SmartArray::SmartArray(int size) {
//     array = new T[size];
//     arraySize = size;
// }

// SmartArray::~SmartArray() {
//     delete[] array;
// }

// int SmartArray::size() {
//     return arraySize;
// }

// int & SmartArray::operator[](int k) {
//     if (k >= arraySize) {
//         cout << "Error: Index out of range." << endl;
//         exit(1);
//     }
//     return array[k];
// }

// void SmartArray::append(T value) {
//     T *newArray = new T[arraySize + 1];
//     for (int i = 0; i < arraySize; i++) {
//         newArray[i] = array[i];
//     }
//     newArray[arraySize] = value;
//     delete[] array;
//     array = newArray;
//     arraySize++;
// }

// void SmartArray::print() {
//     for (int i = 0; i < arraySize; i++) {
//         cout << array[i] << " ";
//     }
//     cout << endl;
// }

int main()
{
    SmartArray<int> a(3); // create an array with 3 elements
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a.append(4);
    a.append(5);
    a.append(6);
    a.print(); // should print 1 2 3 4 5 6
    a[6] = 7; // should print an error message and terminate
    return 0;
}

