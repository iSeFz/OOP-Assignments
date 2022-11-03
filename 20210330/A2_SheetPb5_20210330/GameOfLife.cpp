#include "GameOfLife.h"

// Function to initialize board
void Universe::initialize(string fileName){
    // open file
    ifstream file(fileName);
    if(file.fail()){
        cerr << "Can't open file\n";
        return;
    }
    // value that will carry data from file
    bool value;
    cin.ignore(265,'\n');
    for (int i = 1; i < SIZE + 1; ++i) {
        for (int j = 1; j < SIZE + 1; ++j) {
            file >> value;
            // fill the board with values from file
            board[i][j] = value;
        }
    }
}

//Function to display board
void Universe::display() {
    for (int i = 1; i < SIZE + 1; ++i) {
        for (int j = 1; j < SIZE + 1 ; ++j) {
            // if the cell is alive print ◼ else print ◻
            string ch = (board[i][j]) ? "◼":"◻";
            cout << ch << " ";
        }
        cout << endl;
    }
}

// Function to count neighbors
int Universe::countNeighbors(int x_axis, int y_axis) {
    // count the values of neighbors around the cell
    int neighborsSum = board[x_axis - 1][y_axis - 1] + board[x_axis - 1][y_axis]
                     + board[x_axis - 1][y_axis + 1] + board[x_axis][y_axis - 1]
                     + board[x_axis][y_axis + 1] + board[x_axis + 1][y_axis - 1]
                     + board[x_axis + 1][y_axis] + board[x_axis + 1][y_axis + 1];
    return neighborsSum;
}

void Universe::nextGeneration(){
    // create a copy of the board
    bool temp[SIZE + 2][SIZE + 2] = {{false}};
    for (int i = 1; i < SIZE + 1; ++i) {
        for (int j = 1; j < SIZE + 1; ++j) {
            //get the sum of neighbors
            int neighborsSum = this->countNeighbors(i,j);
            // if the cell is alive
            if(board[i][j]){
                if(neighborsSum < 2)
                    temp[i][j] = false;
                if(neighborsSum == 2 || neighborsSum == 3)
                    temp[i][j] = true;
                if (neighborsSum > 3)
                    temp[i][j] = false;
            }
            // if the cell is dead
            else{
                if(neighborsSum == 3)
                    temp[i][j] = true;
            }
        }
    }
    // copy the values of temp to board
    swap(board,temp);
}
// Function to run the game
void Universe::run(int numOfPhases) {
    // choice of user to select the pattern
    char choice;
    cout << "Menu:";
    cout << "\n\t1)dock\n\t2)1-2-3-4\n\t3)blowup";
    cout << "\nEnter your choice: ";
    cin >> choice;
    if(choice == '1')
        this->initialize("pattern1.txt");
    else if(choice == '2')
        this->initialize("pattern2.txt");
    else if(choice == '3')
        this->initialize("pattern3.txt");
    else
    {
        cout << "invalid input";
        exit(1);
    }
    while (numOfPhases--){
        this->display();
        this->nextGeneration();
        //wait for 1 second
        sleep(1);
        // clear the screen
        system(CLEAR);
    }
}