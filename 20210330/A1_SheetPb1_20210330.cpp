#include<iostream>
#include <sstream>
#include <map>
using namespace std;

void toInclusiveSpeech(const string & speech){
    stringstream ss(speech);
    string word;
    string ans;
    char lastCh;
    map<string,string>dic{{"him"," or her"},{"he"," or she "},{"his"," or her "},{"He"," or she"}
                            ,{"His"," or her"}};
    while(ss >> word){
        if(word.size() > 3 and tolower(word[0]) == 'h'){
            lastCh = word[word.size() - 1];
            word.erase(word.size() - 1);
            ans += word + dic[word] + lastCh + " ";
            continue;
        }
        else if (dic.count(word)){

            ans += word + dic[word] + " ";
            continue;
        }
        ans += word + " ";
    }
    cout << ans;
}


int main()
{

    toInclusiveSpeech("I love him. she love him.");

    return 0;
}