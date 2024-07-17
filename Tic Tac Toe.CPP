#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
void printBoard(const vector<char>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

bool isGameOver(const vector<char>& board) {
    for (int i = 0; i < 3; ++i) {
        if (board[i] != ' ' && board[i] == board[i + 3] && board[i] == board[i + 6])
            return true;
    }
    for (int i = 0; i < 9; i += 3) {
        if (board[i] != ' ' && board[i] == board[i + 1] && board[i] == board[i + 2])
            return true;
    }
    if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8])
        return true;
    if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6])
        return true;

    for (int i = 0; i < 9; ++i) {
        if (board[i] == ' ')
            return false;
    }
    return true; 
}

int getUserMove(const vector<char>& board) {
    int move;
    do {
        cout << "Enter your move (1-9): ";
        cin >> move;
        move--; 
    } while (move < 0 || move >= 9 || board[move] != ' ');
    return move;
}
int getComputerMove(const vector<char>& board) {
    int move;
    do {
        move = rand() % 9;
    } while (board[move] != ' ');
    return move;
}
void playGame() {
    vector<char> board(9, ' '); // Initialize board
    bool userTurn = true; // User starts first
    srand(time(0)); // Seed for random number generation

    while (!isGameOver(board)) {
        printBoard(board);
        int move;
        if (userTurn) {
            move = getUserMove(board);
        } else {
            move = getComputerMove(board);
        }
        board[move] = userTurn ? 'X' : 'O'; // Mark the move on the board
        userTurn = !userTurn; // Switch turns
        cout << endl; // New line after each move
    }

    printBoard(board);

    if (isGameOver(board)) {
        cout << "Game Over!" << endl;
        if (userTurn)
            cout << "Computer wins!" << endl;
        else
            cout << "You win!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}

int main() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    playGame();
    return 0;
}
