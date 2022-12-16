/*
FCAI - OOP - 2022 - Assignment #3
Author: Seif Yahia - 20210172
Program Name: Individual Bonus - Problem 7 - STL Map
Last Modification Date: 16 December 2022
*/

#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class FrequencyTable{
    private:
        map<string, int> frequencyOfWords;
    public:
        // List words and number of times it appeared
        void listFreqTable(string fileName){
            // Check if the file opens correctly
            ifstream file(fileName);
            if(file.fail()){
                cerr << "Error opening the file\n";
                return;
            }
            // Read words from file and load them into a string
            string word, text;
            while(file >> word){
                text += word + " ";
            }
            file.close();
            // Adjust and clean the text from punctuation marks
            for(int i = 0; i < text.length(); ++i){
                if(ispunct(text[i]) && text[i] != '-'){
                    text.erase(text.begin() + i);
                    --i;
                }
            }
            // Store the frequency of each word in STL map
            stringstream ss(text);
            text = "";
            while(ss >> text){
                frequencyOfWords[text]++;
            }
            // Print each word and its frequency
            for(auto el : frequencyOfWords){
                cout << "\"" << el.first << "\" repeated " << el.second << " time(s)\n";
            }
        }
};

// Driver program to test the above function
int main(){
    FrequencyTable f;
    f.listFreqTable("doc.txt");
    return 0;
}
