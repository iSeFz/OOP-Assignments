#include<iostream>
#include<sstream>

using namespace std;


string adjustText(string & text){
    int caps = 1;
    stringstream ss(text);
    string word, result = "";
    while(ss >> word){
        for(int i = 0; i < word.length(); i++){
            word[i] = tolower(word[i]);
            if(caps && isalpha(word[i])){
                word[i] = toupper(word[i]);
                caps = 0;
            }
            else if(word[i] == '.'){
                caps = 1;
            }
        }
        result += word += " ";
    }
    return result;
}


int main(){
    string example = "the      Answer to  life,    the Universe, and everything IS 42.";
    cout << adjustText(example);
}