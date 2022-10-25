#include<iostream>
#include<fstream>
using namespace std;
// compare two files char by char
void compFileByChar(fstream &file1, fstream &file2)
{
    string line1, line2;
    int count = 0;
    // read line by line from both files
    while (getline(file1,line1) && getline(file2,line2))
    {
        // compare character by character
        if (line1 != line2)
        {
            cout << "Line " << count + 1 << " is different" << endl;
            cout << "File 1: " << line1 << endl;
            cout << "File 2: " << line2 << endl;
            return;
        }
        count++;
    }
    cout << "Files are identical" << endl;
}

// comapre two files word by word
void compFileByWord(fstream &file1, fstream &file2)
{
    string word1, word2;
    int count = 0;
    // get first word from each file
    while (file1 >> word1 && file2 >> word2)
    {
        // compare word by word
        if (word1 != word2)
        {
            cout << "Word " << count + 1 << " is different" << endl;
            cout << "File 1: " << word1 << endl;
            cout << "File 2: " << word2 << endl;
            return;
        }
        count++;
    }
    cout << "Files are identical" << endl;
}

int main()
{
    system("cls");
    // open file1.txt in read mode and file2.txt in read mode
    fstream file1("file1.txt", ios::in), file2("file2.txt", ios::in);
    // check if file is opened successfully
    if (!file1 || !file2)
    {
        cout << "Error in opening file" << endl;
        return 0;
    }
    cout << "Comparing files by character" << endl;
    // compare two files char by char
    compFileByChar(file1, file2);
    // close both files
    file1.close();
    file2.close();

    // open file1.txt in read mode and file2.txt in read mode
    file1.open("file1.txt", ios::in);
    file2.open("file2.txt", ios::in);

    cout<<"Comparing files by word"<<endl;
    // compare two files word by word
    compFileByWord(file1, file2);
    // close both files
    file1.close();
    file2.close();
    
    return 0;
}