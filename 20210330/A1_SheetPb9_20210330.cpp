#include<iostream>
#include <fstream>
#include<sstream>
#include <vector>
using namespace std;
// Function to fill vector with lines of files
vector<string> fileToVector(fstream &file)
{
    string line;
    vector<string>vec;
    while (getline(file,line))
    {
        vec.push_back(line);
    }
    return vec;
}

// Function to compare two files char by char
void compByChar(fstream &firstFile, fstream &secondFile)
{
    // load firstFile to v1 line by line
    vector<string>v1(fileToVector(firstFile));
    // load secondFile to v2 line by line
    vector<string>v2(fileToVector(secondFile));
    bool swp = false;
    // make two vectors equal in length
    while (v1.size() > v2.size())
        v2.emplace_back("*");

    while (v1.size() < v2.size())
    {
        v1.emplace_back("*");
        swp = true;
    }
    //get the greatest vector
    if (swp)
        v1.swap(v2);

    for (int i = 0; i< (int)v1.size(); ++i)
    {
        // compare each line char by char
        if(v1[i] != v2[i])
        {
            cout << "Line number " << i + 1 << " is different and it is:\n";
            cout << v1[i];
            return;
        }
    }
    cout << "Two files are identical\n";
}

// Function to compare file word by word
void compByWord(fstream &firstFile, fstream &secondFile)
{
    // load firstFile to v1 line by line
    vector<string>v1(fileToVector(firstFile));
    // load secondFile to v2 line by line
    vector<string>v2(fileToVector(secondFile));
    string wordOfF1,wordOfF2;
    bool swp = false;
    // make two vectors equal in length
    while (v1.size() > v2.size())
        v2.emplace_back("*");

    while (v1.size() < v2.size())
    {
        v1.emplace_back("*");
        swp = true;
    }
    //get the greatest vector
    if (swp)
        v1.swap(v2);

    for (int i = 0; i < (int) v1.size(); ++i)
    {
        // load string-streams with lines of the both files
        stringstream ss1(v1[i]) , ss2(v2[i]);
        // take each word in string-stream and load it in variable
        while (ss1 >> wordOfF1)
        {
            ss2 >> wordOfF2;

            if (wordOfF1 != wordOfF2)
            {
                cout <<"word "<< wordOfF1 << " is different and exist in that line:\n";
                cout << v1[i];
                return;
            }
        }
    }
    // print when two files identical
    cout << "Two files are identical\n";
}

void Menu()
{
    string file1, file2;
    cout << "Enter name of first file (without .txt): ";
    cin >> file1;
    fstream fl1(file1+".txt", ios::in);
    // check if file opened or not
    if(fl1.fail())
    {
        cout << "can't open file1";
        return;
    }

    cout << "Enter name of second file (without .txt): ";
    cin >> file2;
    fstream fl2(file2+".txt", ios::in);
    if(fl2.fail())
    {
        cout << "can't open file2";
        return;
    }

    string choice;
    cout << "Menu:\n\t1) Compare by char\n\t2) Compare by word\n\t0) exit";
    cout << "Enter number from [1-2]: ";
    cin >> choice;
    while (choice != "1" and choice != "2")
    {
        cout << "invalid input\n";
        cout << "Enter number from [1-2]\n";
        cin.ignore(256,'\n');
        cin.clear();
        cin >> choice;
    }
    // take choice
    if(choice == "1")
        compByChar(fl1, fl2);
    else
        compByWord(fl1,fl2);
}

int main()
{
    Menu();
    return 0;
}
