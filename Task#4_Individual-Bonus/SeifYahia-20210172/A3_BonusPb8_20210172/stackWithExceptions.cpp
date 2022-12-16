/*
FCAI - OOP - 2022 - Assignment #3
Author: Seif Yahia - 20210172
Program Name: Individual Bonus - Problem 8 - Exceptions/Templates
Last Modification Date: 16 December 2022
*/

#include <iostream>
#include <string>
using namespace std;

// Forward class declarations
class StackOverflowException{};
class StackEmptyException{};

template <class T>
class Stack{
private:
    T* data;
    int size, topEl;
public:
    Stack(int sz = 5);
    Stack(const Stack<T>&);
    Stack<T>& operator=(const Stack<T>&);
    ~Stack();
    void push(T);
    T pop();
    T top();
    bool empty();
    void printStack();
};

// Constructor to initialize a Stack of the passed size
template <typename T>
Stack<T> :: Stack(int sz){
    size = sz;
    topEl = 0;
    data = new T[size];
}

// Copy constructor
template <typename T>
Stack<T> :: Stack(const Stack<T>& other){
    this->size = other.size;
    this->topEl = other.topEl;
    this->data = new T[size];
    for(int i = 0; i < this->size; ++i){
        this->data[i] = other.data[i];
    }
}

// Copy assignment operator overloading
template <typename T>
Stack<T>& Stack<T> :: operator=(const Stack<T>& other){
    if(this != &other){
        delete[] data;
        this->size = other.size;
        this->topEl = other.topEl;
        this->data = new T[size];
        for(int i = 0; i < this->size; ++i){
            this->data[i] = other.data[i];
        }
    } else{ cerr << "Cannot copy self!\n"; }
    return *this;
}

// Destructor to avoid memory leak
template <typename T>
Stack<T> :: ~Stack(){
    size = 0;
    delete[] data;
}

// Push an element at top of the Stack
template <typename T>
void Stack<T> :: push(T item){
    try{
        if(topEl == size){
            throw StackOverflowException();
        }
        else{
            data[topEl++] = item;
        }
    } catch(StackOverflowException){
        cerr << "Stack is already full! Cannot push any element!\n";
    }
}

// Pop an element from the top of the Stack
template <typename T>
T Stack<T> :: pop(){
    try{
        if(this->empty()){
            throw StackEmptyException();
        }
        else{
            topEl--;
        }
    } catch(StackEmptyException){
        cerr << "Stack is already empty! Cannot pop any element!\n";
    }
    return data[topEl];
}

// Return the element at the top of the Stack
template <typename T>
T Stack<T> :: top(){ return data[topEl - 1]; }

// Return true if the Stack has no elements
template <typename T>
bool Stack<T> :: empty(){
    if(topEl == 0){ return true; }
    return false;
}

// Print the current contents of the Stack
template <typename T>
void Stack<T> :: printStack(){
    if(this->empty()) return;
    for(int i = topEl - 1; i >= 0; --i){
        cout << data[i] << "\n";
    }
}

// Driver program to test the above class
int main(){
    Stack <string> s1;
    s1.push("hello world");
    s1.push("I'm learning C++ programming");
    cout << "\ts1 contents:\n"; s1.printStack();
    cout << "==============================\n";
    // Testing copy constructor
    Stack <string> s2 = s1;
    cout << "Copying s1 into s2 via copy constructor...\n";
    cout << "Pushing an element into s2...\n";
    s2.push("new text in s2");
    cout << "\ts1 contents:\n"; s1.printStack();
    cout << "\ts2 contents:\n"; s2.printStack();
    cout << "==============================\n";
    // Testing copy assignment operator
    Stack <string> s3;
    s3 = s2;
    cout << "Copying s1 into s2 via copy assignment operator...\n";
    cout << "\ts3 contents:\n"; s3.printStack();
    cout << "Popping from s3... " << s3.pop() << "\n";
    cout << "\ts2 contents:\n"; s2.printStack();
    cout << "\ts3 contents:\n"; s3.printStack();
    cout << "==============================\n";
    // Testing other functions of the Stack
    Stack <int> s4(3);
    s4.push(8);
    s4.push(4);
    s4.push(2);
    cout << "\ts4 contents:\n"; s4.printStack();
    s4.push(3);
    cout << "Popping from s4... " << s4.pop() << "\n";
    cout << "Top element now is ==> " << s4.top() << "\n";
    cout << "Popping from s4... " << s4.pop() << "\n";
    cout << "Popping from s4... " << s4.pop() << "\n";
    s4.pop();
    cout << "\tThank you for using FCAI Stack :)\n";
    return 0;
}
