#ifndef A3_SHEETPB5_6_20210330_A3_SHEETPB5AND6_20210330_H
#define A3_SHEETPB5_6_20210330_A3_SHEETPB5AND6_20210330_H
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Main class of AM_Game
class AM_Game{
private:
    // size of board
    int Size;
    // board
    vector<vector<char>>board;
    // position of player1 rockets
    int* p1Rockets;
    // position of player2 rockets
    int* p2Rockets;
public:
    // Default constructor
    AM_Game();
    // Parameterized constructor
    AM_Game(int size);
    // Function to display board
    void displayBoard();
    // Function to take move of players
    bool move(char,int);
    // Function to check if the current player has no moves to do
    bool noMove(char,int);
    // Function to undo move that had done
    void undo(char,int);
    // Function to check win and estimate value based on whom win
    int checkWin();
    // Function to run game
    void run(bool);
    // Function to present menu of game
    void Menu();
    // Function of minimax algorithm to choose best move
    int minimax(vector<vector<char>>&,int,bool);
};
#endif //A3_SHEETPB5_6_20210330_A3_SHEETPB5AND6_20210330_H
