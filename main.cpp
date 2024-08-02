#include <iostream>
using namespace std;

// 2D array representing the game board
char game[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };

// Function prototypes
void drawBoard();
bool updateBoard(char player, int row, int col);
bool checkWin();

int main() {
    char player = 'X';  // Initialize the first player as 'X'
    int row = 0, col = 0;  // Variables to store user input for row and column

    cout << "Welcome to Tic Tac Toe" << endl;
    while (true) {
        cout << endl << "Player " << player << "'s turn:" << endl << endl;
        while (true) {
            drawBoard();
            cout << "Enter row number (1-3)" << endl;
            while (true) {
                cin >> row;
                if (row >= 1 && row <= 3) break;
                else cout << "Please enter a correct row number (1-3)" << endl;
            }
            cout << "Enter column number (1-3)" << endl;
            while (true) {
                cin >> col;
                if (col >= 1 && col <= 3) break;
                else cout << "Please enter a correct column number (1-3)" << endl;
            }
            if (updateBoard(player, row - 1, col - 1)) {
                player = (player == 'X') ? 'O' : 'X';  // Switch player
                break;
            }
            else {
                cout << "This block is already filled!" << endl;
                cout << "Select another empty block please" << endl;
            }
        }
        if (checkWin()) {
            drawBoard();
            break;
        }
    }

    return 0;
}

// Function to draw the game board
void drawBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << game[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Function to update the board with the player's move
bool updateBoard(char player, int row, int col) {
    if (game[row][col] == ' ') {
        game[row][col] = player;
        return true;
    }
    else {
        return false;
    }
}

// Function to check if there's a winner or if the game is a draw
bool checkWin() {
    char block = ' ';

    // Check horizontal rows for a win
    for (int i = 0; i < 3; i++) {
        block = game[i][0];
        if (block != ' ' && block == game[i][1] && block == game[i][2]) {
            cout << "Player " << block << " wins!" << endl;
            return true;
        }
    }

    // Check vertical columns for a win
    for (int i = 0; i < 3; i++) {
        block = game[0][i];
        if (block != ' ' && block == game[1][i] && block == game[2][i]) {
            cout << "Player " << block << " wins!" << endl;
            return true;
        }
    }

    // Check diagonals for a win
    block = game[1][1];
    if (block != ' ' && ((block == game[0][0] && block == game[2][2]) || (block == game[0][2] && block == game[2][0]))) {
        cout << "Player " << block << " wins!" << endl;
        return true;
    }

    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game[i][j] == ' ') {
                return false;
            }
        }
    }

    cout << "Game Draw!" << endl;
    return true;
}
