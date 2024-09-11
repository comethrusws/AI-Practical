#include <iostream>
#include <limits>

using namespace std;

#define PLAYER_X 'X' // Maximizer
#define PLAYER_O 'O' // Minimizer
#define EMPTY '_'

const int N = 3;

// Function to print the board
void printBoard(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if there are moves left
bool isMovesLeft(char board[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == EMPTY)
                return true;
    return false;
}

// Evaluation function: return +10 for 'X' win, -10 for 'O' win, 0 for no win
int evaluate(char board[N][N]) {
    // Check rows for victory
    for (int row = 0; row < N; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == PLAYER_X)
                return +10;
            else if (board[row][0] == PLAYER_O)
                return -10;
        }
    }

    // Check columns for victory
    for (int col = 0; col < N; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == PLAYER_X)
                return +10;
            else if (board[0][col] == PLAYER_O)
                return -10;
        }
    }

    // Check diagonals for victory
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == PLAYER_X)
            return +10;
        else if (board[0][0] == PLAYER_O)
            return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == PLAYER_X)
            return +10;
        else if (board[0][2] == PLAYER_O)
            return -10;
    }

    // No winner
    return 0;
}

// Minimax algorithm to find the best move
int minimax(char board[N][N], int depth, bool isMaximizer) {
    int score = evaluate(board);

    // If Maximizer has won the game, return the evaluated score
    if (score == 10)
        return score - depth;

    // If Minimizer has won the game, return the evaluated score
    if (score == -10)
        return score + depth;

    // If there are no moves left and no winner, it's a draw
    if (!isMovesLeft(board))
        return 0;

    // If it's the Maximizer's move
    if (isMaximizer) {
        int best = numeric_limits<int>::min();

        // Traverse all cells
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X;
                    best = max(best, minimax(board, depth + 1, false));
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    } 
    // If it's the Minimizer's move
    else {
        int best = numeric_limits<int>::max();

        // Traverse all cells
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    best = min(best, minimax(board, depth + 1, true));
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
}

// Find the best possible move for the Maximizer
pair<int, int> findBestMove(char board[N][N]) {
    int bestVal = numeric_limits<int>::min();
    pair<int, int> bestMove = {-1, -1};

    // Traverse all cells, evaluate the minimax function for each cell, and return the cell with the optimal move
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_X;
                int moveVal = minimax(board, 0, false);
                board[i][j] = EMPTY;

                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

int main() {
    char board[N][N] = {
        {PLAYER_X, PLAYER_O, PLAYER_X},
        {PLAYER_O, PLAYER_O, PLAYER_X},
        {EMPTY, EMPTY, EMPTY}
    };

    cout << "Initial board state:" << endl;
    printBoard(board);

    pair<int, int> bestMove = findBestMove(board);

    cout << "\nThe best move is: Row = " << bestMove.first << ", Column = " << bestMove.second << endl;

    return 0;
}
