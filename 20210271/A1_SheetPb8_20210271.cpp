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
    SmartArray(const SmartArray & otherArray){
        arraySize = otherArray.arraySize;
        array = new T[arraySize];
        for (int i = 0; i < arraySize; i++) {
            array[i] = otherArray.array[i];
        }
    }
    ~SmartArray(){
        delete[] array;
    }
    int size(){
        return arraySize;
    }
    T & operator[](int k){
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
    b.print();
    a.print();
    return 0;
}
