#include <iostream>
#include <vector>

using namespace std;
struct dominoT{
    int leftDots;
    int rightDots;
};

vector<dominoT> chain;

bool FormsDominoChain(vector <dominoT> & dominos){
    dominoT piece;
    if (dominos.empty()){
        return true;
    }
    for (int i = 0; i < dominos.size(); i++)
    {
        piece = {dominos[i].leftDots, dominos[i].rightDots};
        if (chain.empty()){
            chain.push_back(piece);
            dominos.erase(dominos.begin() + i);
            if(FormsDominoChain(dominos)){
                return true;
            }
            chain.pop_back();
            dominos.insert(dominos.begin() + i, piece);
        }
        else{
            if (chain.back().rightDots == dominos[i].leftDots){
            chain.push_back(piece);
            dominos.erase(dominos.begin() + i);
            if(FormsDominoChain(dominos)){
                return true;
            }
            chain.pop_back();
            dominos.insert(dominos.begin() + i, piece);
            }
        }
    }
    return false;
}


int main(){
    vector<dominoT> dominos;
    dominoT d1 = {1,4};
    dominoT d2 = {2,6};
    dominoT d3 = {4,4};
    dominoT d4 = {6,1};
    dominoT d5 = {4,3};

    dominos.push_back(d1);
    dominos.push_back(d3);
    dominos.push_back(d4);
    dominos.push_back(d5);
    dominos.push_back(d2);

    int once = 0;
    if(FormsDominoChain(dominos)){
        for(dominoT i : chain){
            if(!once){
                cout << i.leftDots << "|" << i.rightDots;
                once++;
            }
            else{
                cout << " - " << i.leftDots << "|" << i.rightDots;
            }
        }
    }
    else{
        cout << "Chain cannot be formed!!";
    }

}