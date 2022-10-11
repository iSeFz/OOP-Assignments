#include<iostream>
#include <fstream>
#include<sstream>
using namespace std;

string fileToString(fstream &file)
{
    string fTos;
    char ch;
    ch = file.get();
    while(!file.eof()){
        fTos += ch;
        ch = file.get();
    }
    return fTos;
}
void compByChar(fstream &file1, fstream &file2)
{
    string str1,str2;
    str1 = fileToString(file1);
    str2 = fileToString(file2);
    int count = 0;
    int smallest = (int)min(str1.size(),str2.size());
    int longest = (int)max(str1.size(),str2.size());
    if(str1 != str2)
    {
        cout << "First File:\n";
        for(int i = 0;i<smallest;i++)
        {
            if(str1[i] != str2[i])
            {
                cout << "\'" << str1[i] << "\'";
                count++;
            }
            else
            {
                cout << str1[i];
            }
        }
        if(str1.size() > str2.size())
        {
            for (int i = smallest; i < longest; ++i)
            {
                cout << "\'" << str1[i];
                count++;
            }
        }
        cout << "\nThe number of differences = "<< count;

    }
    else
    {
        cout << "The files are identical\n";
    }

}
void compByWord(fstream &file1, fstream &file2)
{
    string word1,word2;
    stringstream ss1(fileToString(file1));
    stringstream ss2(fileToString(file2));
    while (ss1 >> word1 and ss2 >> word2)
    {
        if(word1 != word2)
        {
            if(ss1.peek() == ' ')
            {
                cout << "\'" << word1 << "\' ";
                continue;
            }
            if(ss1.peek() == '\n')
            {
                cout << "\'" << word1 << "\'\n";
                continue;
            }
            cout << "\'" << word1 << "\'";
        }
        else
        {
            if (ss1.peek() == '\n')
                cout << word1 << "\n";
            else
                cout << word1 << " ";
        }
    }

}

void Menu()
{
    string file1, file2;
    cout << "Enter name of first file (without .txt): ";
    cin >> file1;
    fstream fl1(file1+".txt", ios::in);
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
    cout << "Menu:\n\t1) Compare by char\n\t2) Compare by word\n";
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
    if(choice == "1")
        compByChar(fl1, fl2);
    else if(choice == "2")
        compByWord(fl1,fl2);
}

int main()
{
    Menu();
    return 0;
}
