#ifndef A3_BONUSPB9_20210330_A3_BONUSPB9_20210330_H
#define A3_BONUSPB9_20210330_A3_BONUSPB9_20210330_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
class Set{
private:
    vector<T>data;
public:
    // Default constructor
    Set();
    // Insert Function to insert element in set
    void insert(T);
    // Erase Function to erase element from set
    void erase(T);
    // Get size of set
    int size();
    // print elements of set
    void print();
    // Check if element exist in set or not
    bool count(T);
    // Get memory element of first element in set
    typename vector<T>::iterator begin();
    // Equality operator
    bool operator==(Set<T>&);
    // not Equal operator
    bool operator!=(Set<T>&);
};

// Default constructor
template <typename T>
Set<T>::Set() {
    data.resize(0);
}

// Insert Function to insert element in set
template <typename T>
void Set<T>::insert(T value) {
    // check if element exist before or not
    if(find(data.begin(), data.end(),value) == data.end()) {
        data.push_back(value);
        sort(data.begin(), data.end());
    }
}

// Erase Function to erase element from set
template <typename T>
void Set<T>::erase(T value) {
    // check if element is existed or not
    auto it = find(data.begin(), data.end(),value);
    if(it != data.end()){
        data.erase(it);
    }
    // if not exit the program
    else {
        cerr <<  "Try to remove non-existence element\n";
        exit(-1);
    }
}

// Get size of set
template <typename T>
int Set<T>::size() {
    return data.size();
}

// print elements of set
template <typename T>
void Set<T>::print() {
    for (auto el = Set<T>::begin(); el != Set<T>::begin() + Set<T>::size(); ++el) {
        cout << *el << ' ';
    }
    cout << endl;
}

// Check if element exist in set or not
template<typename T>
bool Set<T>::count(T value) {
    if(find(data.begin(), data.end(),value) == data.end())
        return false;
    else
        return true;
}

// Get memory element of first element in set
template <typename T>
typename vector<T>::iterator Set<T>::begin() {
    return data.begin();
}

// Equality operator
template <typename T>
bool Set<T>::operator==(Set<T> &another) {
    for (int i = 0; i < Set<T>::size(); ++i) {
        if(this->data[i] != another.data[i])
            return false;
    }
    return true;
}

// not Equal operator
template <typename T>
bool Set<T>::operator!=(Set<T> &another) {
    for (int i = 0; i < Set<T>::size(); ++i) {
        if(this->data[i] != another.data[i])
            return true;
    }
    return false;
}
#endif //A3_BONUSPB9_20210330_A3_BONUSPB9_20210330_H