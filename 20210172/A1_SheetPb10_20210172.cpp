/*
FCAI - OOP - 2022 - Assignment #1
Author: Seif Yahia - 20210172
Program Name: Problem #10 - Phishing Scanner
Last Modification Date: 24 October 2022
*/

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <map>

using namespace std;

// Function prototype
void checkPhishing(string);

// List of 30 most common words found in phishing messages
// The first part of the map is the word, the second is a pair of integers
// The first part of the pair is its point score and the second is its frequency
map <string, pair<int, int>> mostCommonPhishingWords = {
        {"request", {1, 0}}, {"important", {2, 0}},
        {"urgent", {1, 0}}, {"confirmation", {2, 0}},
        {"shipment", {2, 0}}, {"financial", {3, 0}},
        {"promotion", {3, 0}}, {"offer", {2, 0}},
        {"deal", {2, 0}}, {"free", {3, 0}},
        {"profit", {2, 0}}, {"guaranteed", {1, 0}},
        {"giveaway", {2, 0}}, {"credit", {3, 0}},
        {"money", {3, 0}}, {"opportunity", {2, 0}},
        {"winner", {3, 0}}, {"congratulations", {3, 0}},
        {"selected", {3, 0}}, {"debt", {1, 0}},
        {"no", {3, 0}}, {"cash", {1, 0}},
        {"work", {2, 0}}, {"investment", {2, 0}},
        {"lottery", {2, 0}}, {"password", {3, 0}},
        {"account", {3, 0}}, {"number", {1, 0}},
        {"username", {3, 0}}, {"invitation", {3, 0}}
};

int main(){
    string email;
    cout << "Welcome to the Phishing Scanner Program!\n";
    cout << "Enter the email text file name: ";
    cin >> email;
    checkPhishing(email);
    return 0;
}

// Function to check for phishing words in a given file
void checkPhishing(string fileName){
    // Check for the file name format using regex
    if(!regex_match(fileName, regex("^.*\\.txt$")))
        { cerr << "Invalid file name format!\n"; return; }
    // Create an object and open the file
    ifstream file(fileName);
    // Check if the file is opened successfully
    if(file.fail())
        { cerr << "Error opening the file!\n"; return; }
    // Scan the file word by word for phishing words
    int totalPoints = 0;
    string word;
    while(file >> word){
        // Check if the current word is present in the list or not
        if(mostCommonPhishingWords.count(word))
            // If the word is found among the list increment its frequency by 1
            { ++mostCommonPhishingWords[word].second; }
    }
    // Loop over the elements of the map to check for the frequency of the word
    for(auto & el : mostCommonPhishingWords){
        // If the frequency is more than 1 then the word appeard in the email
        if(el.second.second >= 1){
            // Add the points of the word to the point total
            totalPoints += el.second.first;
            // Print the word, its frequency and the point total
            cout << "The word \"" << el.first << "\" appeared "
                 << el.second.second << " time(s) in the file. "
                 << "The point total is " << totalPoints << " points.\n";
        }
    }
    cout << "\nThe point total for the entire message is " << totalPoints << " points.\n";
    // Close the file before exit
    file.close();
}
