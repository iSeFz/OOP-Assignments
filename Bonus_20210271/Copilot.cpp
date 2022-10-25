// Name: Omar Mohamed Said Elgammal
// ID: 20210271
// FCAI - OOP assignment 1 - Copilot bonus individual task



#include <iostream>

using namespace std;

// Write a program that reads in a sentence and outputs the sentence with spacing
// corrected and with letters corrected for capitalization. In other words, in the output sentence, all strings
// of two or more blanks should be compressed to a single blank. The sentence should start with an
// uppercase letter but should contain no other uppercase letters. Do not worry about proper names; if their
// first letters are changed to lowercase, that is acceptable.
// Treat a line break as if it were a blank, in the sense that a line break and any number of blanks are
// compressed to a single blank. Assume that the sentence ends with a period and contains no other
// periods.

string adjustText(const string sentence){
    // get rid of multiple spaces
    // get rid of capital letters
    // make sure first letter is capital
    string newSentence = "";
    int i = 0;
    while (sentence[i] != '\0') {
        if (sentence[i] == ' ') {
            newSentence += ' ';
            while (sentence[i] == ' ') {
                i++;
            }
        }
        newSentence += tolower(sentence[i]); // added tolower
        i++;
    }
    newSentence[0] = toupper(newSentence[0]);
    return newSentence;
}

int main()
{
    cout << "Enter a sentence: ";
    string sentence;
    getline(cin, sentence);
    cout << adjustText(sentence);

    return 0;
}