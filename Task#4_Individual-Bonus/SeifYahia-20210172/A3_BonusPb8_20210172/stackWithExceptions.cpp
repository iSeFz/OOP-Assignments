/*
FCAI - OOP - 2022 - Assignment #3
Author: Seif Yahia - 20210172
Program Name: Individual Bonus - Problem 8 - Exceptions/Templates
Last Modification Date: 22 December 2022
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
    void setSize(int);
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
    topEl = 0;
    delete[] data;
}

// Set the size of the stack according to the user's input
template <typename T>
void Stack<T> :: setSize(int userSize){ size = userSize; }

// Push an element at top of the Stack
template <typename T>
void Stack<T> :: push(T item){
    if(topEl >= size){
        throw StackOverflowException();
    }
    data[topEl++] = item;
}

// Pop an element from the top of the Stack
template <typename T>
T Stack<T> :: pop(){
    T lastElement = this->top();
    topEl--;
    return lastElement;
}

// Return the element at the top of the Stack
template <typename T>
T Stack<T> :: top(){
    if(this->empty()){
        throw StackEmptyException();
    }
    return data[topEl - 1];
}

// Return true if the Stack has no elements
template <typename T>
bool Stack<T> :: empty(){
    if(topEl == 0){ return true; }
    return false;
}

// Print the current contents of the Stack
template <typename T>
void Stack<T> :: printStack(){
    if(this->empty()) {
        cerr << "\n\tStack is EMPTY!!\n";
        return;
    }
    cout << "\n";
    for(int i = topEl - 1; i >= 0; --i){
        cout << data[i] << "\n";
    }
}

// Function to manage the stack functions
template <typename T>
void manageStack(Stack<T> clientStack){
    short choice;
    int stackSize = 0;
    string elementToPush;
    while(true){
        cout << "\nChoose one of the following options:\n";
        cout << "1. Create a Stack\n"
                "2. Check top element\n"
                "3. Push an element\n"
                "4. Pop an element\n"
                "5. Print stack elements\n"
                "6. Exit\n";
        cout << "Your choice ==> ";
        cin >> choice;
        try{
            if(choice == 1){
                if(stackSize != 0){
                    cerr << "\n\tYou have already created a stack!\n";
                    continue;
                }
                cout << "Creating a stack for you...\n";
                cout << "Enter the size of the stack ==> ";
                cin >> stackSize;
                clientStack.setSize(stackSize);
                cout << "\n\tCreated a stack of size " << stackSize << " successfully!\n";
            } else if(choice == 2){
                string temp = clientStack.top();
                cout << "\n\tCurrent top element is ==> " << temp << "\n";
            } else if(choice == 3){
                if(stackSize == 0){
                    cerr << "\n\tYou should create a stack first!\n";
                    continue;
                }
                cout << "Enter the item to push to the stack ==> ";
                cin.ignore();
                getline(cin, elementToPush);
                clientStack.push(elementToPush);
                cout << "\n\tPushed \"" << elementToPush << "\" to the stack.\n";
            } else if(choice == 4){
                string temp = clientStack.pop();
                cout << "\n\tPopped \"" << temp << "\" from the stack.\n";
            } else if(choice == 5){
                clientStack.printStack();
            } else if(choice == 6){ break; }
            else{
                cerr << "\n\tINVALID Choice! Choose ONLY from 1 to 6\n";
            }
        } catch(StackEmptyException){
            cerr << "\n\tStack is already EMPTY!!\n";
        } catch(StackOverflowException){
            cerr << "\n\tStack is already FULL!!\n";
        }
    }
    cout << "\n\tThank you for using FCAI Stack :)\n";
}

// Driver program to test the above class
int main(){
    Stack <string> test;
    manageStack(test);
    return 0;
}
