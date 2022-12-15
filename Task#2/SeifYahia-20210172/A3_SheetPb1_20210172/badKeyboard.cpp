/*
FCAI - OOP - 2022 - Assignment #3
Author: Seif Yahia - 20210172
Program Name: Problem 1 - Bad Keyboard
Last Modification Date: 15 December 2022
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Main class defintion
class badKeyboard{
public:
    bool isInDictionary(string);
    void findMeaningfulMessage(string, string);
};

// Check if the word exists in the dictionary
bool badKeyboard::isInDictionary(string currentWord){
    // Convert the incoming word into lowercase
    for(char& ch : currentWord){
        ch = tolower(ch);
    }
    // Search for the incoming word in the dictionary
    ifstream dict("dictionary.txt");
    string word;
    while(dict >> word){
        if(currentWord == word){
            return true;
        }
    }
    return false;
}

// Main function to find a meaningful message
void badKeyboard::findMeaningfulMessage(string message, string prevResult){
    // Traverse the incoming message to get all possible meaningful messages
    for(int i = 1; i <= message.length(); ++i){
        // Check if the current substring is a meaningful word
        // whether it is found in the dictionary or not
        string current = message.substr(0, i);
        if(isInDictionary(current)){
            // If the index reaches the end of the message
            // meaning there are no more possible solutions
            if(i == message.length()){
                // Update the value of the previous result
                // with the new combination found then print it
                prevResult += current;
                cout << "\"" << prevResult << "\"\n";
            }
            // Backtrack to check for other possible solutions with
            // recursive call on the rest of the message with the updated result
            findMeaningfulMessage(message.substr(i), prevResult + current + " ");
        }
        // If the current substring is NOT found in the dictionary
        // ignore it and take the next letter to check again and so on.
    }
}

// Driver program to test the above function
int main(){
    badKeyboard mess;
    cout << "Possible solutions:\n";
    mess.findMeaningfulMessage("letusplayfootballtonight", "");
    return 0;
}
