#include <iostream>
#include <vector>

using namespace std;
struct dominoT{
    int leftDots;
    int rightDots;
};

vector<dominoT> chain;

// Function that checks if a chain can be formed with the given domino tiles
bool FormsDominoChain(vector <dominoT> & dominos){
    dominoT piece;
    
    // If input vector gets empty it means that all tiles are in the chain
    if (dominos.empty()){ 
        return true;
    }

    // Loop that iterates over dominos vector
    for (int i = 0; i < dominos.size(); i++){
        piece = {dominos[i].leftDots, dominos[i].rightDots};

        // If the chain is empty, add the first domino tile to it
        if (chain.empty() || chain.back().rightDots == dominos[i].leftDots){
            chain.push_back(piece); // Adding the domino tile
            dominos.erase(dominos.begin() + i); // Erasing the tile form dominos vector
            
            // Recursive call to check if the chain can be formed with the remaining tiles
            if(FormsDominoChain(dominos)){ 
                return true;
            }
            else{
                dominos.insert(dominos.begin() + i, piece); // If the chain cannot be formed, add the tile back to the input vector
                chain.pop_back(); // Remove the tile from the chain
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
    dominoT d6 = {2,1};

    dominos.push_back(d1);
    dominos.push_back(d3);
    dominos.push_back(d4);
    dominos.push_back(d5);
    dominos.push_back(d2);
    dominos.push_back(d6);

    int once = 0;

    // Prints chain if it can be formed or not
    if(FormsDominoChain(dominos)){
        cout << "Chain formed: \n";
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