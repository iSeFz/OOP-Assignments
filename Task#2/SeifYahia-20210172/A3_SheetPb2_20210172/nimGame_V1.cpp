/* FCAI - OOP - 2022 - Assignment #3
Author: Seif Yahia - 20210172
Program Name: Problem 2 - Nim Game
Last Modification Date: 19 December 2022 */

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
void variantOne();

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

// Driver program to test the above functions
int main() {
    int var = 0;
    cout << "Welcome to Nim Game. We start with " << N_COINS << " coins.\n";
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";
    while(var < 1 || var > 2){
        cout << "Choose which variant of the game to play (1 or 2): ";
        cin >> var;
        if(var == 1){
            variantOne();
            break;
        } else if(var == 2) {
            cout << "\t\tComing Soon!\n";
            // variantTwo();
            break;
        } else{
            cerr << "Enter only 1 or 2!\n";
        }
    }
    return 0;
}
