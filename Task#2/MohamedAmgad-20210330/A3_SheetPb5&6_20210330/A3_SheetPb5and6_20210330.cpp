#include "A3_SheetPb5and6_20210330.h"

// Default constructor
AM_Game::AM_Game() {
    Size = 5;
    board.resize(Size,vector<char>(Size,' '));
    for (int i = 1; i <= 3; ++i) {
        board[0][i] = 'v';
        board[i][0] = '>';
    }
    p1Rockets = new int[Size - 2]{0,0,0};
    p2Rockets = new int[Size - 2]{0,0,0};
}

// Parameterized constructor
AM_Game::AM_Game(int size) {
    Size = size;
    board.resize(size,vector<char>(size,' '));
    for (int i = 1; i <= size - 2; ++i) {
        board[0][i] = 'v';
        board[i][0] = '>';
    }
    p1Rockets = new int[size - 2];
    p2Rockets = new int[size - 2];
    for (int i = 0; i < size - 2; ++i) {
        p1Rockets[i] = 0;
        p2Rockets[i] = 0;
    }
}

//Display board
void AM_Game::displayBoard() {
    cout << string(5*Size,'-')<<"\n";
    for (int i = 0; i < Size; ++i) {
        for (int j = 0; j < Size; ++j) {
            if((i != 0 || i != Size - 1) && (j != 0 || j != Size - 1))
                cout <<" |" << board[i][j] << "| ";

        }
        cout << "\n"<<string(5*Size,'-')<<"\n";
    }
}

//Take move
bool AM_Game::move(char player, int rocketNum) {
    if(rocketNum < 1 || rocketNum > Size - 2)
        return false;
    if(player == 'v'){
        // check if rocket is at its destination or not
        if(p1Rockets[rocketNum - 1] == Size - 1)
            return false;
        if(board[p1Rockets[rocketNum - 1] + 1][rocketNum] != '>'){
            // make my position is empty
            board[p1Rockets[rocketNum - 1]++][rocketNum] = ' ';
            // move to next position
            board[p1Rockets[rocketNum - 1]][rocketNum] = 'v';
            return true;
        }
        else if(board[p1Rockets[rocketNum - 1] + 2][rocketNum] != '>'){
            // make my position is empty
            board[p1Rockets[rocketNum - 1]][rocketNum] = ' ';
            // increment to jump filled position
            p1Rockets[rocketNum - 1] += 2;
            // move to next position
            board[p1Rockets[rocketNum - 1]][rocketNum] = 'v';
            return true;
        }
        // there are two 'G' in front of me
        else
            return false;
    }else
    {
        if(p2Rockets[rocketNum - 1] == Size - 1)
            return false;
        // if next index is empty
        if (board[rocketNum][p2Rockets[rocketNum - 1] + 1] != 'v'){
            // make my position is empty
            board[rocketNum][p2Rockets[rocketNum - 1]++] = ' ';
            // move to next position
            board[rocketNum][p2Rockets[rocketNum - 1]] = '>';
            return true;
        }
        // if index after my position with 2 is empty
        else if(board[rocketNum][p2Rockets[rocketNum - 1] + 2] != 'v'){
            // make my position is empty
            board[rocketNum][p2Rockets[rocketNum - 1]] = ' ';
            // increment to jump filled position
            p2Rockets[rocketNum - 1] += 2;
            // move to next position
            board[rocketNum][p2Rockets[rocketNum - 1]] = '>';
            return true;
        }
        // there are two 'R' in front of me
        else
            return false;
    }
}

// function to check if there is no move for a player
bool AM_Game::noMove(char player, int rocketNum) {
    // number of rockets at destination
    int rocketsAtEnd = 0;
    if(player == 'v'){
        // if rocket at destination don't check
        if(p1Rockets[rocketNum - 1] == 4)
            return false;
        for (int i = 1; i <= Size - 2; ++i) {
            // get number of rockets at destination except we want to move
            if(i != rocketNum && board[Size - 1][i] == 'v'){
                    rocketsAtEnd++;
            }
        }
        // if all rockets at destination except we want to move and rocket we want to move can't move
        if(rocketsAtEnd == Size - 3 && board[p1Rockets[rocketNum - 1] + 1][rocketNum] == '>'
            && board[p1Rockets[rocketNum - 1] + 2][rocketNum] == '>')
            return true;

    }
    else{
        // if rocket at destination don't check
        if(p2Rockets[rocketNum - 1] == 4)
            return false;
        for (int i = 1; i <= Size - 2; ++i) {
            // get number of rockets at destination except we want to move
            if(i != rocketNum && board[i][Size - 1] == '>'){
                rocketsAtEnd++;
            }
        }
        // if all rockets at destination except we want to move and rocket we want to move can't move
        if(rocketsAtEnd == Size - 3 && board[rocketNum][p2Rockets[rocketNum - 1] + 1] == 'v'
            && board[rocketNum][p2Rockets[rocketNum - 1] + 2] == 'v')
            return true;
    }
    // player can move or choose another rocket to move with it
    return false;
}

// undo player move
void AM_Game::undo(char player, int rocketNum) {
    if (player == 'v') {
        // if next index is empty
        if (board[p1Rockets[rocketNum - 1] - 1][rocketNum] != '>') {
            // make my position is empty
            board[p1Rockets[rocketNum - 1]--][rocketNum] = ' ';
            // move to next position
            board[p1Rockets[rocketNum - 1]][rocketNum] = 'v';
        } else if (board[p1Rockets[rocketNum - 1] - 2][rocketNum] != '>') {
            // make my position is empty
            board[p1Rockets[rocketNum - 1]][rocketNum] = ' ';
            // increment to jump filled position
            p1Rockets[rocketNum - 1] -= 2;
            // move to next position
            board[p1Rockets[rocketNum - 1]][rocketNum] = 'v';
        }
    } else {
        // if next index is empty
        if (board[rocketNum][p2Rockets[rocketNum - 1] - 1] != 'v') {
            // make my position is empty
            board[rocketNum][p2Rockets[rocketNum - 1]--] = ' ';
            // move to next position
            board[rocketNum][p2Rockets[rocketNum - 1]] = '>';
        }
            // if index after my position with 2 is empty
        else if (board[rocketNum][p2Rockets[rocketNum - 1] - 2] != 'v') {
            // make my position is empty
            board[rocketNum][p2Rockets[rocketNum - 1]] = ' ';
            // increment to jump filled position
            p2Rockets[rocketNum - 1] -= 2;
            // move to next position
            board[rocketNum][p2Rockets[rocketNum - 1]] = '>';
        }
    }
}

//check win
int AM_Game::checkWin() {
    int sum = 0;
    for (int i = 1; i <= Size - 2; ++i) {
        sum += board[Size - 1][i];
    }
    // 118 is ascii code of 'v'
    if (sum == 118 * (Size - 2))
        return 10;
    sum = 0;
    for (int i = 1; i <= Size - 2; ++i) {
        sum += board[i][Size - 1];
    }
    // 62 is ascii code of 62
    if (sum == 62 * (Size - 2))
        return -10;
    return 0;
}

//run Game
void AM_Game::run(bool AI) {
    char player = ' ';
    int rocketNum;
    while (abs(checkWin()) != 10){
        bool changeTurn = false;
        system(CLEAR);
        AM_Game::displayBoard();
        // change turn of players
        player = (player == ' ' || player == '>') ? 'v' : '>';
        if(player == 'v') {
            player = 'v';
            cout << "Player1 choose rocket:";
            // check if there are valid moves for player or not
            for (int i = 1; i <= Size - 2; ++i) {
                if(noMove('v',i))
                    changeTurn = true;
            }
            if (changeTurn)
                continue;
            cin >> rocketNum;
            // check input validation
            while(!move(player,rocketNum)){
                cout << "Invalid input please choose another rocket: ";
                cin >> rocketNum;
            }
        }
        else if(!AI) {
            cout << "Player2 choose rocket:";
            // check if there are valid moves for player or not
            for (int i = 1; i <= Size - 2; ++i) {
                if(noMove('>',i))
                    changeTurn = true;
            }
            if (changeTurn)
                continue;
            cin >> rocketNum;
            // check input validation
            while(!move(player,rocketNum)){
                cout << "Invalid input please choose another rocket: ";
                cin >> rocketNum;
            }
        }
        else {
            // let score max as possible because we want to minimize it
            int score = 1000;
            int bestChoice;
            for (int i = 1; i <= Size - 2; ++i) {
                if (move('>',i)){
                    int bestScore = minimax(board,20, true);
                    undo('>',i);
                    // if bestScore < score take this move in consideration
                    if (bestScore < score){
                        score = bestScore;
                        bestChoice = i;
                    }
                }
            }
            // play optimal move
            move('>',bestChoice);
        }
    }
    system(CLEAR);
    AM_Game::displayBoard();
    if(player == 'v')
        cout << "Player1 is winner";
    else if (!AI)
        cout << "Player2 is winner";
    else
        cout << "Computer is winner";
}

// minimax function
int AM_Game::minimax(vector<vector<char>> &Board,int depth, bool isMaximizing) {
    int result = checkWin();
    // check if there is win
    if (result == 10 || result == -10)
        return result;
    // arrived to end of level
    if(depth == 0)
        return result;
    // Max player which is 'v'
    if (isMaximizing){
        // let bestScore is minimum possible value at first
        int bestScore = -1000;
        // test every move
        for (int i = 1; i <= Size - 2; ++i) {
            if (move('v',i)){
                int score = minimax(board,depth - 1, false);
                undo('v',i);
                bestScore = max(bestScore, score);
            }
        }
        return bestScore;
    }
    else{
        // let bestScore is maximum possible value at first
        int bestScore = 1000;
        for (int i = 1; i <= Size - 2; ++i) {
            if (move('>',i)){
                int score = minimax(board,depth - 1, true);
                undo('>',i);
                bestScore = min(bestScore, score);
            }
        }
        return bestScore;
    }
}

// Menu of Game
void AM_Game::Menu() {
    cout << "Welcome to AM_Game\n";
    cout << "Please choose one of the two options:\n\t";
    cout << "1) VS human\n\t2) VS computer\nyour Choice: ";
    int choice;
    cin >> choice;
    while (choice > 2 || choice < 1){
        cin.ignore();
        cin.clear();
        cout << "Invalid input Please enter 1 or 2: ";
        cin >> choice;
    }
    if(choice == 1)
        run(false);
    else
        run(true);
}