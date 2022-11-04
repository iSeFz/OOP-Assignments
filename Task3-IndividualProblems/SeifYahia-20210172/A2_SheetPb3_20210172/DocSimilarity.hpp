// Include necessary libraries
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

// Main defintion of class
class StringSet{
    private:
        vector <string> mainSet;
    public:
        // Getter function to get the mainSet vector
        vector <string> & getVector();
        // Constructor to load the words in a given file
        // StringSet(string fileName = "");
        // Constructor to load the string passed & breaks it to tokens
        StringSet(string text = "");
        // Add a certain string to the set
        void addStr(string toAdd);
        // Remove a certain string from the set
        // void removeStr(string toRemove);
        // Clear the entire set
        void clearSet();
        // Return number of strings in the set
        long strCount();
        // Output all strings in the set
        void printSet();
        // Overload the "+" operator to return the union of two sets
        StringSet operator + (StringSet & anotherSet);
        // Overload the "*" operator to return the intersection of two sets
        StringSet operator * (StringSet & anotherSet);
        // Check the similarity of two StringSet objects
        double checkSimilarity(StringSet & anotherSet);
};

// Convert the text entered into lowercase with no puctuation marks
string & modifyText(string & text);
