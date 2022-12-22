/*
FCAI - OOP - 2022 - Assignment #3
Author: Seif Yahia - 20210172
Program Name: Problem 3 - Maze
Program Description:
    This is a maze. A mouse wants to get from
    corner 0, 0 to N-1, N-1
    It can move only to right or down
    It uses backtracking to find 1st way out 
Last Modification Date: 22 December 2022
*/

#include <iostream>
#define N 9 // Maze size
using namespace std;

// Functions prototype
bool isSafe(int maze[N][N], int x, int y, int sol[N][N]);
bool solveMaze(int maze[N][N]);
bool solveMazeAll(int maze[N][N], int x, int y, int sol[N][N]);
bool solveMazeShort(int maze[N][N], int x, int y, int sol[N][N]);
void printSolution(int sol[N][N]);

// Driver program to test above function
int main(){
    int maze[N][N] = {
        {1, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 0, 0, 1},
        {0, 1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 0, 1, 0, 1, 1, 1, 1},
        {0, 0, 0, 1, 0, 1, 0, 0, 1}
    };
    cout << "Welcome to FCAI Maze Problem!\n";
    solveMaze(maze);
    return 0;
}

// A utility function to print solution matrix sol[N][N]
void printSolution(int sol[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << " " << sol[i][j] << " ";
        }
        cout << "\n";
    }
}

// A utility function to check if x,y is valid index for N*N maze
bool isSafe(int maze[N][N], int x, int y, int sol[N][N]){
    // if (x,y outside maze) return false
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0){
        return true;
    }
    return false;
}

/* This function solves the Maze problem using Backtracking. It mainly
   uses solveMazeAll() or solveMazeShort() to solve the problem.
   It returns false if no path is possible, otherwise return true
   and prints the path in the form of 1s. */
bool solveMaze(int maze[N][N]){
    int sol[N][N] = {{0}};
    char choice;
    cout << "Choose what to output (1 or 2):\n";
    cout << "1. All Possible Solutions\n2. Shortest Solution\n";
    cout << "Your choice ==> ";
    cin >> choice;
    if(choice == '1'){
        cout << "  All Possible Solutions\n";
        if(solveMazeAll(maze, 0, 0, sol) == false){
            cout << "Solution doesn't exist\n";
            return false;
        }
        return true;
    } else if(choice == '2'){
        cout << "    Shortest Solution\n";
        if(solveMazeShort(maze, 0, 0, sol) == false){
            cout << "Solution doesn't exist\n";
            return false;
        }
        return true;
    } else{
        cout << "\tINVALID Input!! Choose only 1 or 2\n";
        solveMaze(maze);
    }
    return false;
}

// A recursive utility function to find all possible solutions
bool solveMazeAll(int maze[N][N], int x, int y, int sol[N][N]){
    // if (x,y is goal) return true
    if(x == N-1 && y == N-1){
        sol[x][y] = 1;
        printSolution(sol);
        cout << "\n";
        return true;
    }
    // Check if maze[x][y] is valid
    if(isSafe(maze, x, y, sol) == true){
        // mark x,y as part of solution path
        sol[x][y] = 1;
        /* Move forward in x direction (down in the maze) */
        solveMazeAll(maze, x+1, y, sol);
        /* If moving in x direction doesn't give solution then
           Move forward in y direction (right in the maze) */
        solveMazeAll(maze, x, y+1, sol);
        /* If moving forward in y direction doesn't give solution then
           Move backward in x direction (up in the maze) */
        solveMazeAll(maze, x-1, y, sol);
        /* If moving backward in x direction doesn't give solution then
           Move backward in y direction (left in the maze) */
        solveMazeAll(maze, x, y-1, sol);
        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return true;
    }
    return false;
}

// A recursive utility function to find the shortest solution
bool solveMazeShort(int maze[N][N], int x, int y, int sol[N][N]){
    // if (x,y is goal) return true
    if(x == N-1 && y == N-1){
        sol[x][y] = 1;
        printSolution(sol);
        return true;
    }
    // Check if maze[x][y] is valid
    if(isSafe(maze, x, y, sol) == true){
        // mark x,y as part of solution path
        sol[x][y] = 1;

        /* Move forward in x direction (down in the maze) */
        if (solveMazeShort(maze, x+1, y, sol) == true)
            return true;
        
        /* If moving in x direction doesn't give solution then
           Move forward in y direction (right in the maze) */
        if (solveMazeShort(maze, x, y+1, sol) == true)
            return true;
        
        /* If moving forward in y direction doesn't give solution then
           Move backward in x direction (up in the maze) */
        if (solveMazeShort(maze, x-1, y, sol) == true)
            return true;

        /* If moving backward in x direction doesn't give solution then
           Move backward in y direction (left in the maze) */
        if (solveMazeShort(maze, x, y-1, sol) == true)
            return true;

        /* If none of the above movements work then BACKTRACK:
            unmark x,y as part of solution path */
        sol[x][y] = 0;
        return false;
    }
    return false;
}
