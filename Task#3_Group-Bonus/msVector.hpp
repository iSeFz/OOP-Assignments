#ifndef _MSVECTOR_HPP
#define _MSVECTOR_HPP
/**
 * @file msVector.hpp
 * @authors Mohamed Amgad and Seif Yahia 
 * @brief This is the Header file For msVector
 * @version 2.0
 * @date 2022-12-22
 */
#include <iostream>
using namespace std;

template <class T> class MSVector;
template <class T> ostream& operator<<(ostream&, MSVector<T>);
/**
 * @brief MSVector Class 
 * 
 * @tparam T 
 */

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
    
    typedef T* iterator;
    
    /**
     * @brief Construct a new MSVector object
     * 
     */
    MSVector();

    /**
     * @brief Construct a new MSVector object
     * 
     */
    MSVector(int);

    /**
     * @brief Construct a new MSVector object from Pre-defined container
     * 
     */
    MSVector(T*, int);

    /**
     * @brief Construct a new MSVector object from another object
     * 
     */
    MSVector(const MSVector<T>&);

    /**
     * @brief Redefine MSVector object form another object
     * 
     * @return MSVector<T>& 
     */
    MSVector<T>& operator=(const MSVector<T>&);

    /**
     * @brief Move MSVector object to another object
     * 
     * @return MSVector<T>& 
     */
    MSVector<T>& operator=(MSVector<T>&&);

    /**
     * @brief Destroy the MSVector object
     * 
     */
    ~MSVector();

    /**
     * @brief Get value at given index
     * 
     * @return T& 
     */
    T& operator[](int);

     /**
      * @brief Get address of first element in MSVector
      * 
      * @return iterator 
      */
    iterator begin();

    /**
     * @brief Get address of position after last element
     * 
     * @return iterator 
     */
    iterator end();

    /**
     * @brief Push Element at end of MSVector
     * 
     * @return int 
     */
    int push_back(T);

    /**
     * @brief Remove last element form MSVector
     * 
     * @return T 
     */
    T pop_back();

    /**
     * @brief Insert value at given Position
     * 
     */
    void insert(iterator, T);
    
    /**
     * @brief Erase element at given Position
     * 
     */
    void erase(iterator);
    /**
     * @brief Erase element from start till before end
     * 
     */
    void erase(iterator,iterator);
    
    /**
     * @brief Get size of MSVector
     * 
     * @return int 
     */
    int Size() const;
    /**
     * @brief Get capacity of MSVector
     * 
     * @return int 
     */
    int Capacity() const;
  
    /**
     * @brief Resize MSVector
     * 
     * @return int 
     */
    int Resize();
    
    /**
     * @brief Check if MSVector is empty or not
     * 
     * @return true 
     * @return false 
     */
    bool Empty();

    /**
     * @brief Clear MSVector
     * 
     */
    void Clear();
  
    /**
     * @brief Compare two MSVector element by element
     * 
     * @return true 
     * @return false 
     */
    bool operator==(const MSVector<T>&);
  
    /**
     * @brief Compare two MSVector element by element
     * 
     * @return true 
     * @return false 
     */
    bool operator<(const MSVector<T>&);
};

/**
 * @brief Construct a new MSVector object
 * 
 * @tparam T 
 * @return MSVector<T> 
 */
template <class T>
MSVector<T> :: MSVector() {
    size = 0;
    capacity = 2;
    data = new T[capacity];
}

/**
 * @brief Construct a new MSVector object
 * 
 * @tparam T 
 * @param cap 
 * @return MSVector<T> 
 */
template <class T>
MSVector<T> :: MSVector(int cap) {
    size = 0;
    capacity = cap;
    data = new T[capacity];
}

/**
 * @brief Construct a new MSVector object from Pre-defined container
 * 
 * @tparam T 
 * @param other 
 * @param n 
 * @return MSVector<T> 
 */
template <class T>
MSVector<T> :: MSVector(T* other, int n) {
    size = n;
    capacity = n;
    data = new T[capacity];
    for(int i = 0; i < size; i++){
        data[i] = other[i];
    }
}

/**
 * @brief Construct a new MSVector object from another object
 * 
 * @tparam T 
 * @param other 
 * @return MSVector<T> 
 */
template <class T>
MSVector<T> :: MSVector(const MSVector<T>& other) {
    size = other.size;
    capacity = other.capacity;
    data = new T[capacity];
    for(int i = 0; i < other.size; i++){
        data[i] = other.data[i];
    }
}

/**
 * @brief Redefine MSVector object form another object
 * 
 * @tparam T 
 * @param other 
 * @return MSVector<T>& 
 */
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

/**
 * @brief Move MSVector object to another object
 * 
 * @tparam T 
 * @param other 
 * @return MSVector<T>& 
 */
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

/**
 * @brief Destroy the MSVector object
 * 
 * @tparam T 
 * @return MSVector<T> 
 */
template <class T>
MSVector<T> :: ~MSVector() { delete[] data; }

/**
 * @brief Get address of first element in MSVector
 * 
 * @tparam T 
 * @return MSVector<T> 
 */
template <class T>
typename MSVector<T> :: iterator MSVector<T> :: begin(){ return data; }

/**
 * @brief Get address of position after last element
 * 
 * @tparam T 
 * @return MSVector<T> 
 */
template <class T>
typename MSVector<T> :: iterator MSVector<T> :: end() { return &data[size]; }

/**
 * @brief Get value at given index
 * 
 * @tparam T 
 * @param indx 
 * @return T& 
 */
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

/**
 * @brief Push Element at end of MSVector
 * 
 * @tparam T 
 * @param item 
 * @return int 
 */
template <class T>
int MSVector<T> :: push_back(T item) {
    // Check if the vector is full and if so
    // resize to double the capacity
    if(size >= capacity){ this->Resize(); }
    data[size++] = item;
    return size;
}

/**
 * @brief Remove last element form MSVector
 * 
 * @tparam T 
 * @return T 
 */
template <class T>
T MSVector<T> :: pop_back() {
    try{
        if(this->Empty()){
            throw "\n\tException Error: Vector is already EMPTY!\n";
        }
    } catch(const char* error){ cerr << error; exit(-1); }
    return data[--size];
}

/**
 * @brief insert value at given Position
 * 
 * @tparam T 
 * @param pos 
 * @param value 
 */
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


/**
 * @brief Erase element at given Position
 * 
 * @tparam T 
 * @param pos 
 */
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

/**
 * @brief Erase element from start till before end
 * 
 * @tparam T 
 * @param start 
 * @param end 
 */
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
            throw "Position of start is greater than Position of end";
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

/**
 * @brief Get size of MSVector
 * 
 * @tparam T 
 * @return int 
 */
template <class T>
int MSVector<T> :: Size() const { return size; }

/**
 * @brief Get capacity of MSVector
 * 
 * @tparam T 
 * @return int 
 */
template <class T>
int MSVector<T> :: Capacity() const { return capacity; }

/**
 * @brief Resize MSVector
 * 
 * @tparam T 
 * @return int 
 */
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

/**
 * @brief Check if MSVector is empty or not
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template <class T>
bool MSVector<T> :: Empty() {
    if(size == 0) return true;
    return false;
}

/**
 * @brief Clear all elements in MSVector
 * 
 * @tparam T 
 */
template <class T>
void MSVector<T> :: Clear() {
    size = 0;
    delete [] data;
    data = nullptr;
}

/**
 * @brief Compare two MSVector element by element
 * 
 * @tparam T 
 * @param other 
 * @return true 
 * @return false 
 */
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

/**
 * @brief Compare two MSVector element by element
 * 
 * @tparam T 
 * @param other 
 * @return true 
 * @return false 
 */
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

/**
 * @brief Print MSVector element by element in console
 * 
 * @tparam T 
 * @param out 
 * @param vec 
 * @return ostream& 
 */
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
