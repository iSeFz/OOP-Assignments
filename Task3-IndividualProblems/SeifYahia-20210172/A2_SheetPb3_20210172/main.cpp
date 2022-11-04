/*
FCAI - OOP - 2022 - Assignment #2
Author: Seif Yahia - 20210172
Program Name: Problem 3 - Document Similarity
Last Modification Date: 4 November 2022
*/

#include "DocSimilarity.hpp"

int main(){
    // Initializing objects with strings
    StringSet set1("Chocolate ice cream, chocolate milk, and chocolate bars are delicious.");
    StringSet set2("I love chocolate bars very much! They are delicious.");
    
    // Printing the contents of the two sets
    cout << "set1 contents: ";
    set1.printSet();
    cout << "set2 contents: ";
    set2.printSet();
    
    // Checking similarity using binary cosine coefficient
    cout << "Checking the similarity between set1 and set2....\n";
    cout << set1.checkSimilarity(set2) << endl;
    
    // Testing the addition of string to a set
    cout << "Adding text to set2....\n";
    set2.addStr("This is some more new text!");
    cout << "set2 contents NEW!!: ";
    set2.printSet();

    // Print the number of strings in the set
    cout << "Number of strings in set2 is " << set2.strCount() << " strings.\n";
    
    // Removing all strings in the set and clearing its contents
    cout << "Clearing set2....\n";
    set2.clearSet();

    // Initializing more objects
    StringSet set3("Chocolate is made out of cocoa seeds.");
    StringSet set4("Milk is a necessary ingredient in the ice cream.");
    cout << "set3 contents: ";
    set3.printSet();
    cout << "set4 contents: ";
    set4.printSet();

    // Testing the union of two sets by overloaded + operator
    set2 = set3 + set4;
    cout << "set2 now is the union of set3 and set4!\n";
    cout << "set2 contents NEW!!: ";
    set2.printSet();

    // Testing the intersection of two sets by overloaded * operator
    StringSet set5 = set1 * set2;
    cout << "set5 is the intersection of set1 and set2!\n";
    cout << "set5 contents: ";
    set5.printSet();
    return 0;
}
