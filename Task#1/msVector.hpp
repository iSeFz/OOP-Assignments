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
    // iterator
    typedef T* iterator;
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
     // Return address of first element in MSVector
    iterator begin();
    // Return address of location after last element in MSVector
    iterator end();
    // Add element to the end of the vector
    // and return the # of items
    int push_back(T);
    // Remove and return last element in vector
    T pop_back();
    // Insert item at iterator position
    void insert(iterator, T);
    // Remove item at iterator position
    void erase(iterator);
    // Remove items between two iterators
    void erase(iterator,iterator);
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

// Return address of first element in vector
template <class T>
typename MSVector<T> :: iterator MSVector<T> :: begin(){ return data; }

// Return address of location after last element in MSVector
template <class T>
typename MSVector<T> :: iterator MSVector<T> :: end() { return &data[size]; }

// Access and return the item at the specified index
template <class T>
T& MSVector<T> :: operator[] (int indx) {
    try{
        if(indx > size - 1 or indx < 0)
            throw out_of_range("\n\tException Error: Index is OUT of range!\n");
    } catch(out_of_range error){
        cerr << error.what(); exit(-1);
    }
    return data[indx];
}

// Add element to the end of the vector
template <class T>
int MSVector<T> :: push_back(T item) {
    // Check if the vector is full and if so
    // resize to double the capacity
    if(size >= capacity){ this->Resize(); }
    data[size++] = item;
    return size;
}

// Remove and return last element in vector
template <class T>
T MSVector<T> :: pop_back() {
    try{
        if(this->Empty()){
            throw "\n\tException Error: Vector is already EMPTY!\n";
        }
    } catch(const char* error){ cerr << error; exit(-1); }
    return data[--size];
}

// Insert item at iterator position
template <class T>
void MSVector<T> :: insert(iterator pos, T value) {
    try{
        if(pos > MSVector<T>::end() || pos < MSVector<T>::begin())
            throw out_of_range("\n\tException Error: Position is out of range!\n");
    } catch(out_of_range error){
        cerr << error.what(); exit(-1);
    }
    if(pos == MSVector<T>::end()){
        this->push_back(value);
    }
    else {
        if(size + 1 > capacity)
            capacity *= 2;
        int idx = 0;
        T *newData = new T[capacity];
        for (auto it = MSVector<T>::begin(); it != MSVector<T>::end();) {
            if (it != pos)
                newData[idx++] = *(it++);
            else {
                newData[idx++] = value;
                newData[idx++] = *(it++);
            }
        }
        delete[] data;
        size++;
        data = newData;
        newData = nullptr;
    }
}

// Remove item at iterator position
template <class T>
void MSVector<T> :: erase(iterator pos) {
    try{
        if(pos < MSVector<T>::begin() || pos >= MSVector<T>::end())
            throw out_of_range("\n\tException Error: Position is out of range!\n");
    } catch(out_of_range error){
        cerr << error.what(); exit(-1);
    }
    int idx = 0;
    T* newData = new T[capacity];
    for (auto it = MSVector<T>::begin(); it != MSVector<T>::end(); ++it) {
        if(it != pos)
            newData[idx++] = *it;
    }
    delete [] data;
    size--;
    data = newData;
    newData = nullptr;
}

// Remove items between two iterators
template <class T>
void MSVector<T> :: erase(iterator start, iterator end) {
    try{
        if((start < MSVector<T>::begin() || start > MSVector<T>::end())
        && (end < MSVector<T>::begin() || end > MSVector<T>::end())){
            throw out_of_range("\n\tException Error: Position is out of range!\n");
        }
    } catch(out_of_range error){
        cerr << error.what(); exit(-1);
    }
    try {
        if (start > end)
            throw "Positioin of start is greater than Position of end";
    }
    catch (const char* e){
        cerr << "Program Terminated due to: " << e;
        exit(-1);
    }
    int idx = 0;
    int LB = start - MSVector<T>::begin();
    int UB = end - MSVector<T>::begin() - 1;
    int newSize = size - (UB - LB + 1);
    if(newSize <= 0){
        MSVector<T>::Clear();
        return;
    }
    T* newData = new T[capacity];
    for (auto it = MSVector<T>::begin(); it != MSVector<T>::end(); ++it) {
        if(it < start || it > end - 1)
            newData[idx++] = *it;
    }
    delete [] data;
    size = newSize;
    data = newData;
    newData = nullptr;
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
    // If the vector is not full return 0
    if(size < capacity){ return capacity; }
    // Otherwise double the capacity
    capacity *= 2;
    T* newData = new T[capacity];
    // Copy the old vector in a new one
    // with double the capacity
    for(int i = 0; i < size; ++i){
        newData[i] = data[i];
    }
    delete [] data; // Delete the old vector
    data = newData; // Copy the new to the old
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
        out << "\t==> ";
        for (int i = 0; i < vec.Size(); ++i)
            out << vec[i] << " ";
        out << "<==";
    }
    out << "\n";
    return out;
}

#endif