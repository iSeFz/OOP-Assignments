#include "DocSimilarity.hpp"

// Getter function to get the mainSet vector
vector <string> & StringSet :: getVector(){ return mainSet; }

// Convert the text entered into lowercase with no puctuation marks
string & modifyText(string & text){
    for(int i = 0; i < text.length(); ++i){
        // Check if the character is already lowercase, ignore it
        if((text[i] >= 97) && (text[i] <= 122))
            { continue; }
        // Check if the character is letter or number, convert it to lowercase
        if(isalnum(text[i]))
            { text[i] = tolower(text[i]); }
        // Check if the character is space and the next character
        // is not space make it only one space
        else if(isspace(text[i]) && !isspace(text[i + 1]))
            { text[i] = ' '; }
        // Convert any other character to null character
        else
            { text[i] = '\0'; }
    }
    // Remove all null characters from the string
    text.erase(remove(text.begin(), text.end(), '\0'), text.end());
    return text;
}

// Constructor to load text from file to the mainSet vector
StringSet :: StringSet(fstream & file){
    // Loop over the file and load each string to the vector
    string word;
    while(file >> word){
        // Check if the word is found before or not to take
        // only one instance of the word to prevent repeating
        if(find(mainSet.begin(), mainSet.end(), word) == mainSet.end())
            { mainSet.push_back(modifyText(word)); }
    }
}

// Constructor to load text from parameter to the mainSet vector
StringSet :: StringSet(string text){
    text = modifyText(text);
    // Convert the coming string into input string stream
    istringstream ss(text);
    string word;
    // Split the passed string into separate words
    while(ss >> word){
        // Check if the word is found before or not to take
        // only one instance of the word to prevent repeating
        if(find(mainSet.begin(), mainSet.end(), word) == mainSet.end())
            { mainSet.push_back(word); }
    }
}

// Add certain string to the set
void StringSet :: addStr(string toAdd){
    toAdd = modifyText(toAdd);
    // Convert the coming string into input string stream
    istringstream ss(toAdd);
    string word;
    // Split the passed string into separate words
    while(ss >> word){
        // Check if the word is found before or not to take
        // only one instance of the word to prevent repeating
        if(find(mainSet.begin(), mainSet.end(), word) == mainSet.end())
            { mainSet.push_back(word); }
    }
}

// Remove certain string from the set
void StringSet :: removeStr(string toRemove){
    // Loop over the set to check for the word to remove
    for(int i = 0; i < mainSet.size(); ++i){
        // If the word is found, remove it from the set
        if(mainSet[i] == toRemove){
            mainSet.erase(mainSet.begin() + i);
            cout << "The word \"" << toRemove << "\" is removed from the set.\n";
            return;
        }
    }
    // If the word is not found in the set
    cerr << "The word \"" << toRemove << "\" is NOT in the set!\n";
}

// Clear all elements in the set
void StringSet :: clearSet(){ mainSet.clear(); }

// Return current number of strings in the set
long StringSet :: strCount(){ return mainSet.size(); }

// Output all strings in the set
void StringSet :: printSet(){
    for(string word : mainSet)
        { cout << word << " "; }
    cout << endl;
}

// Overload the "+" operator to return the union of two sets
StringSet StringSet :: operator + (StringSet & anotherSet){
    StringSet unionOfSets;
    // Copy strings from the current set to unionOfSets
    unionOfSets.mainSet = this->mainSet;
    // Copy strings from the passed set to unionOfSets
    for(string word : anotherSet.getVector())
        { unionOfSets.mainSet.push_back(word); }
    // Return the object after combining the sets in it
    return unionOfSets;
}

// Overload the "*" operator to return the intersection of two sets
StringSet StringSet :: operator * (StringSet & anotherSet){
    StringSet intersectionOfSets;
    // Loop over the two sets and check if there is common words
    for(string word : this->mainSet){
        for(string anotherWord : anotherSet.getVector()){
            // Add the common words to the intersectionOfSets
            if(word == anotherWord)
                { intersectionOfSets.mainSet.push_back(word); }
        }
    }
    // Return the common elements between the two sets
    return intersectionOfSets;
}

// Check the similarity of two StringSet objects
double StringSet :: checkSimilarity(StringSet & anotherSet){
    int commonWords = 0;
    double similarityFactor = 0.0;
    // Get the number of common words using methods in class StringSet
    commonWords = (*this * anotherSet).strCount();
    // (*this * anotherSet) returns an object with the common words between the two sets
    // strCount() returns the number of these common words
    cout << "Number of common Words = " << commonWords << endl;
    // Compute the similarity factor using the binary cosine coefficient equation
    similarityFactor = commonWords / (sqrt(this->strCount()) * sqrt(anotherSet.strCount()));
    cout << "Similarity Factor = ";
    return similarityFactor;
}
