#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void allTrafficLightsPossibilities(int n, bool yellowOn = false, int count = 0,string str = ""){
    if(pow(2 + yellowOn,n) == count)
        return;
    if(str.size() != n){
        str += "R";
        allTrafficLightsPossibilities(n,yellowOn,count,str);
        str.pop_back();
        str += "G";
        allTrafficLightsPossibilities(n,yellowOn,count,str);
        if(yellowOn){
            str.pop_back();
            str += "Y";
            allTrafficLightsPossibilities(n,yellowOn,count,str);
        }
    }
    else{
        count++;
        for(int i = 0 ;i<str.size();i++){
            string color;
            if(str[i] == 'R')
                color = "Red";
            else if(str[i] == 'G')
                color = "Green";
            else
                color = "Yellow";
            cout << i + 1 << "-" << color;
            if(i != str.size() - 1)
                cout << ", ";
        }
        cout << endl;
    }
}



int main(){

    allTrafficLightsPossibilities(3);
    return 0;
}
