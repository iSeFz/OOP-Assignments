#include <iostream>

using namespace std;


// Initializing class
template <class T>
class SmartArray {
private:
    T *array;
    int arraySize;
public:
    // Array constructor
    SmartArray(int size){
        array = new T[size];
        arraySize = size;
    }

    // Copy constructor
    SmartArray(const SmartArray & otherArray){
        arraySize = otherArray.arraySize;
        array = new T[arraySize];
        for (int i = 0; i < arraySize; i++) {
            array[i] = otherArray.array[i];
        }
    }

    // Destructor
    ~SmartArray(){
        delete[] array;
    }

    int size(){
        return arraySize;
    }

    // Overloading [] operator to call array elements in a certain position
    T & operator[](int k){

        // checks if index is out of bounds and throws an error then terminates the program if true
        if (k >= arraySize) { 
            cout << "Error: Index out of range." << endl;
            exit(1);
        }
        return array[k]; // Returns elemnt position if valid
    }

    // Append element to the end of the array
    void append(T value){
        T *newArray = new T[arraySize + 1]; // Extending array size by one

        // Loop that copies old array into new array
        for (int i = 0; i < arraySize; i++) {
            newArray[i] = array[i];
        }
        newArray[arraySize] = value; // Assigning the new element to the last position of the array
        delete[] array; // Delete old array
        array = newArray; // Assign new array to old array
        arraySize++; // Increment array size
    }

    //Overloading the assignment operator
    SmartArray & operator=(const SmartArray & otherArray){
        if (this != &otherArray) { // Checks if they have different addresses
            delete[] array; // Delete old array
            arraySize = otherArray.arraySize; // Assigns new array size
            array = new T[arraySize]; // Creates new array with new size
            for (int i = 0; i < arraySize; i++) { // Deep copying from the other array to the new array
                array[i] = otherArray.array[i];
            }
        }
        return *this;
    }

    // Prints all elements of the array
    void print(){
        for (int i = 0; i < arraySize; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }

};



int main()
{
    SmartArray<char> a(3); // create an array with 3 elements
    a[0] = '1';
    a[1] = '2';
    a[2] = '3';
    a.append('4');
    a.append('5');
    a.append('k');
    SmartArray<char> b(a);
    b.append('6');
    a = b;
    b = b;
    b.append('n');
    b.print();
    a.print();
    return 0;
}
