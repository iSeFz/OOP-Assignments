#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void allTrafficLightsPossibilities(int n, int count = 0,string str = ""){
    if(pow(2,n) == count)
        return;
    if(str.size() != n){
        str += "R";
        allTrafficLightsPossibilities(n,count,str);
        str.pop_back();
        str += "G";
        allTrafficLightsPossibilities(n,count,str);
    }
    else{
        count++;
        for(int i = 0 ;i<str.size();i++){
            string color = (str[i] == 'R') ? "Red" : "Green";
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
