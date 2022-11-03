#ifndef A2_SHEETPB5_20210330_GAMEOFLIFE_H
#define A2_SHEETPB5_20210330_GAMEOFLIFE_H
#define SIZE 20
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define CLEAR "cls"
#include <windows.h>
#else
#define CLEAR "clear"
#include <unistd.h>
#endif
#include <iostream>
#include <fstream>
using namespace std;

class Universe{
private:
    bool board[SIZE + 2][SIZE + 2] = {{false}};
    public:
    // Function to initialize board
    void initialize(string fileName);
    // Function to display board
    void display();
    //Function to count neighbors
    int countNeighbors(int x_axis, int y_axis);
    // Function to calculate next generation
    void nextGeneration();
    // Function to run the game
    void run(int numOfPhases);

};
#endif //A2_SHEETPB5_20210330_GAMEOFLIFE_H
