/* FCAI - OOP - 2022 - Assignment #3
Author: Seif Yahia - 20210172
Program Name: Problem 2 - Nim Game
Last Modification Date: 23 December 2022 */

#include <iostream>

#define NO_GOOD_MOVE 0
#define MAX_MOVE 3
#define N_COINS 23
#define HUMAN 1
#define COMPUTER 0

using namespace std;

// Functions prototype
int findGoodMove(int);
bool isBadPosition(int);
int findGoodPile(int[]);
void variantOne();
void variantTwo();

// Driver program to test the above functions
int main() {
    int var = 0;
    cout << "Welcome to Nim Game. We start with " << N_COINS << " coins.\n";
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";
    while(var < 1 or var > 2){
        cout << "Choose which variant of the game to play (1 or 2): ";
        cin >> var;
        if(var == 1){
            variantOne();
            break;
        } else if(var == 2){
            variantTwo();
            break;
        } else{
            cerr << "Enter only 1 or 2!\n";
        }
    }
    return 0;
}

// Find good move for computer by testing all possible moves
int findGoodMove(int nCoins) {
	for (int n = 1; n <= MAX_MOVE; n++){
        // Check if it is bad position for human
		if (isBadPosition(nCoins - n)){
			return n;
        }
    }
	return NO_GOOD_MOVE;
}

// Check if the current position is bad for human
bool isBadPosition(int nCoins) {
    // If it is the last coin then it is bad for human
    if (nCoins == 1){ return true; }
    // If the remaining coins are greater than 1
    // Backtrack to check another move for computer
    return (findGoodMove(nCoins) == NO_GOOD_MOVE);
}

// Find good pile for computer
int findGoodPile(int piles[]){
    for(int i = 0; i < 3; ++i){
        if(piles[i] > 1){
            return i + 1;
        }
    }
    return 0;
}

// First variant of the game where each player has his own pile
void variantOne(){
    int humanPile = 0, computerPile = 0;
    int nCoins = N_COINS, n = 0;
    int whoseTurn = HUMAN;
    cout << "\t\tVariant 1 Selected\n";
    // Loop until the number of coins reaches 1
    while (nCoins > 1) {
        // Update the state of the game after each round
        cout << "Remaining coins = " << nCoins << " coins.\n";
        cout << (whoseTurn ? "Human's" : "Computer's") << " turn: ";
        switch (whoseTurn) {
            case HUMAN:
                n = nCoins + 10;
                // Get the human move
                while (n < 1 || n > 3 || n > nCoins) {
                    cout << "Pls pick 1 to 3 coins and <= remaining coins: ";
                    cin >> n;
                }
                // Update the human pile by the current play
                humanPile += n;
                break;
            case COMPUTER:
                // Get the computer's move
                n = findGoodMove(nCoins);
                if (!n) { n = 1; } // If there is no good move take 1
                // Update the computer pile by the current play
                computerPile += n;
                cout << "takes " << n << " coins.\n" ;
        }
        // Update the number of coins after each round
        nCoins -= n;
        // Swap turns between human and computer
        whoseTurn = (whoseTurn + 1) % 2;
    }
    // Check for the pile with an even number of coins
    if(humanPile % 2 == 0) { whoseTurn = HUMAN; }
    else { whoseTurn = COMPUTER; }
    cout << "Winner is " << (whoseTurn ? "Computer!\n" : "Human!\n");
}

// Second variant of the game where
void variantTwo(){
    int piles[] = {7, 8, 8};
    int nCoins = N_COINS, n = 0, pileNumber = 0;
    int whoseTurn = HUMAN;
    cout << "\t\tVariant 2 Selected\n";
    // Loop until all coins are taken from all piles
    while (piles[0] > 1 or piles[1] > 1 or piles[2] > 1) {
        // Update the state of the game after each round
        cout << "Current game state ==> " << piles[0] << " " << piles[1] << " " << piles[2] << "\n";
        cout << (whoseTurn ? "Human" : "Computer") << " plays:\n";
        switch (whoseTurn) {
            case HUMAN:
                n = 5;
                pileNumber = 5;
                // Get the human move
                while (n < 1 or n > 3 or (n > piles[0] and n > piles[1] and n > piles[2])){
                    cout << "Pls pick 1 to 3 coins and <= remaining coins: ";
                    cin >> n;
                }
                while (pileNumber < 1 or pileNumber > 3) {
                    cout << "Take " << n << " coins from pile at index? (1, 2 or 3): ";
                    cin >> pileNumber;
                    if(pileNumber == 1 and (piles[0] == 0 or n > piles[0])){
                        pileNumber += 5;
                    }
                    if(pileNumber == 2 and (piles[1] == 0 or n > piles[1])){
                        pileNumber += 5;
                    }
                    if(pileNumber == 3 and (piles[2] == 0 or n > piles[2])){
                        pileNumber += 5;
                    }
                }
                nCoins -= n;
                break;
            case COMPUTER:
                // Get the computer's move
                n = findGoodMove(nCoins);
                if (!n) { n = 1; } // If there is no good move take 1
                pileNumber = findGoodPile(piles);
                if(!pileNumber){
                    for(int i = 0; i < 3; ++i){
                        if(piles[i] != 0){ pileNumber = i + 1; }
                    }
                }
                nCoins -= n;
                cout << "takes " << n << " coins from pile number " << pileNumber << "\n";
        }
        // Update the number of coins after each round
        switch(pileNumber){
            case 1:
                piles[0] -= n;
                break;
            case 2:
                piles[1] -= n;
                break;
            case 3:
                piles[2] -= n;
        }
        // Swap turns between human and computer
        whoseTurn = (whoseTurn + 1) % 2;
    }
    cout << "Winner is " << (whoseTurn ? "Computer!\n" : "Human!\n");
}
