#include<iostream>
#include<sstream>

using namespace std;


// A function that compress all blank spaces in a string and adjusts capitalization
string adjustText(string & text){

    // Initializing variables required for function
    int caps = 1;
    stringstream ss(text);
    string word, result = "";

    // Looping through each word in the string
    while(ss >> word){
        for(int i = 0; i < word.length(); i++){
            word[i] = tolower(word[i]); // Changes all characters to lowercase

            // Checks if the character is the first letter of the sentence or follows a period
            if(caps && isalpha(word[i])){ 
                word[i] = toupper(word[i]);
                caps = 0;
            }
            
            // Checks if the character is a period to set caps to 1 to capitalize the next letter
            else if(word[i] == '.'){
                caps = 1;
            }
        }
        result += word + " "; // Adds the word to the result string
    }
    return result;
}


int main(){
    string example = "the      Answer to  life,    the Universe, and everything IS 42.";
    cout << adjustText(example);
}