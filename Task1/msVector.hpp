#ifndef _MSVECTOR_HPP
#define _MSVECTOR_HPP

#include <iostream>
using namespace std;

// Forward declarations
template <class T> class MSVector;
template <class T> ostream& operator<<(ostream&, MSVector<T>);

// Main vector class
template <class T>
class MSVector{
// Friends
    // Overload the exertion operator to print all vector content
    friend ostream& operator<< <T> (ostream&, MSVector<T>);
// Private data members
private:
    int size, capacity;
    T* data;
// Public methods
public:
    // Constructors
    MSVector();
    MSVector(int);
    MSVector(T*, int);
    // Copy constructor
    MSVector(const MSVector<T>&);
    // Copy assignment operator
    MSVector<T>& operator=(const MSVector<T>&);
    // Move assignment operator
    MSVector<T>& operator=(MSVector<T>&&);
    // Destructor
    ~MSVector();
    // Access and return the element at the specified index
    T& operator[](int);
    // Add element to the end of the vector
    void push_back(T);
    // Remove and return last element in vector
    T pop_back();
    // Return current size of vector
    int Size() const;
    // Return current capacity of vector
    int Capacity() const;
    // Realocate to bigger space
    int Resize();
    // Return true if size = 0
    bool Empty();
    // Delete all vector contents
    void Clear();
    // Overload the equality operator to compare item by item
    bool operator==(const MSVector<T>&);
    // Overload the less than operator to compare item by item
    bool operator<(const MSVector<T>&);
};

// Default constructor
template <class T>
MSVector<T> :: MSVector() {
    size = 0;
    capacity = 2;
    data = new T[capacity];
}

// Parametrized constructor to assign with certain capacity
template <class T>
MSVector<T> :: MSVector(int cap) {
    size = 0;
    capacity = cap;
    data = new T[capacity];
}

// Assign with n elements from array
template <class T>
MSVector<T> :: MSVector(T* other, int n) {
    size = n;
    capacity = n;
    data = new T[capacity];
    for(int i = 0; i < size; i++){
        data[i] = other[i];
    }
}

// Copy constructor
template <class T>
MSVector<T> :: MSVector(const MSVector<T>& other) {
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for(int i = 0; i < other.size; i++){
        data[i] = other.data[i];
    }
}

// Copy assignment operator
template <class T>
MSVector<T>& MSVector<T> :: operator= (const MSVector<T>& other) {
    // Check if not self
    if(this != &other){
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for(int i = 0; i < size; i++){
            data[i] = other.data[i];
        }
    }
    else
        cerr << "Cannot copy self\n";
    return *this;
}

// Move assignment operator
template <class T>
MSVector<T>& MSVector<T> :: operator= (MSVector<T>&& other) {
    if(this != &other){
        size = other.size;
        capacity = other.capacity;
        data = other.data;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    else
        cerr << "Cannot move self\n";
    return *this;
}

// Destructor
template <class T>
MSVector<T> :: ~MSVector() { delete[] data; }

// Access and return the item at the specified index
template <class T>
T& MSVector<T> :: operator[] (int indx) {
    if(indx > size - 1 or indx < 0)
        throw out_of_range("Exception Error: Index is OUT of range!\n");
    return data[indx];
}

// Add element to the end of the vector
template <class T>
void MSVector<T> :: push_back(T item) {
    if(size < capacity){
        data[size++] = item;
    }
    else{
        capacity *= 2;
        T* newData = new T[capacity];
        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        delete[] data;
        data = nullptr;
        data = newData;
        newData = nullptr;
        data[size++] = item;
    }
}

// Remove and return last element in vector
template <class T>
T MSVector<T> :: pop_back() {
    T* newData = new T[size--];
    for(int i = 0; i < size; ++i){
        newData[i] = data[i];
    }
    T lastEl = data[size];
    delete[] data;
    data = nullptr;
    data = newData;
    newData = nullptr;
    return lastEl;
}

// Return current size of vector
template <class T>
int MSVector<T> :: Size() const { return size; }

// Return current capacity of vector
template <class T>
int MSVector<T> :: Capacity() const { return capacity; }

// Realocate to bigger space
template <class T>
int MSVector<T> :: Resize() {
    capacity *= 2;
    T* newData = new T[capacity];
    for(int i = 0; i < size; ++i){
        newData[i] = data[i];
    }
    delete [] data;
    data = newData;
    delete [] newData;
    return capacity;
}

// Return true if size = 0
template <class T>
bool MSVector<T> :: Empty() {
    if(size == 0) return true;
    return false;
}

// Delete all vector contents
template <class T>
void MSVector<T> :: Clear() {
    size = 0;
    delete [] data;
    data = nullptr;
}

// Overload the equality operator to compare item by item
template <class T>
bool MSVector<T> :: operator== (const MSVector<T> &other) {
    if(this->Size() != other.Size())
        return false;
    else{
        for (int i = 0; i < size; ++i) {
            if(this->data[i] != other.data[i])
                return false;
        }
    }
    return true;
}

// Overload the less than operator to compare item by item
template <class T>
bool MSVector<T> :: operator< (const MSVector<T> &other) {
    if(this->Size() != other.Size())
        return false;
    else{
        for (int i = 0; i < size; ++i) {
            if(this->data[i] >= other.data[i])
                return false;
        }
    }
    return true;
}

// Overload the exertion operator to print all vector content
template <class T>
ostream& operator<< (ostream& out, MSVector<T> vec) {
    if (!vec.Empty()){
        for (int i = 0; i < vec.Size(); ++i)
            out << vec[i] << " ";
        out << endl;
    }
    return out;
}

#endif