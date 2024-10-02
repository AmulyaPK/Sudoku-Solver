#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<map>
using namespace std;
using sudokuBoard = vector<vector<int>>;

map<string, vector<sudokuBoard>> sudokuPuzzles = {
    {"easy", {
            {{0, 6, 8, 0, 1, 0, 0, 4, 7},
            {0, 0, 0, 0, 0, 7, 0, 0, 5},
            {0, 0, 0, 0, 5, 4, 8, 6, 0},
            {0, 2, 6, 0, 4, 0, 7, 0, 0},
            {0, 5, 0, 0, 2, 0, 4, 3, 0},
            {0, 7, 0, 8, 0, 0, 0, 0, 6},
            {0, 8, 5, 0, 7, 9, 0, 0, 0},
            {2, 0, 9, 5, 3, 8, 0, 7, 0},
            {7, 3, 0, 1, 0, 2, 0, 5, 8}},
            {{9, 0, 0, 0, 0, 0, 3, 4, 0},
            {0, 5, 1, 9, 4, 3, 0, 0, 6},
            {4, 7, 0, 6, 5, 0, 8, 0, 0},
            {0, 0, 0, 0, 0, 1, 4, 0, 0},
            {0, 1, 9, 0, 6, 0, 0, 3, 0},
            {7, 0, 0, 8, 9, 5, 1, 0, 0},
            {0, 0, 2, 0, 0, 0, 0, 8, 7},
            {5, 6, 8, 7, 0, 4, 0, 0, 3},
            {0, 9, 0, 0, 0, 6, 2, 0, 4}},
            {{2, 4, 0, 5, 6, 0, 0, 9, 0},
            {0, 6, 3, 0, 9, 0, 0, 2, 5},
            {0, 0, 5, 3, 0, 0, 7, 6, 0},
            {0, 0, 5, 3, 0, 0, 7, 6, 0},
            {0, 1, 2, 6, 0, 5, 9, 4, 0},
            {9, 0, 8, 0, 0, 0, 0, 0, 0},
            {6, 0, 0, 2, 0, 0, 0, 5, 3},
            {7, 0, 0, 9, 0, 6, 0, 0, 4},
            {0, 0, 6, 4, 7, 3, 1, 0, 0},
            {0, 0, 0, 0, 0, 1, 0, 7, 2}}
        }
    },
    {"medium", {
            {{0, 0, 0, 9, 0, 6, 0, 5, 7},
            {6, 7, 0, 0, 3, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 6, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 3, 0},
            {0, 8, 4, 0, 5, 7, 1, 0, 0},
            {0, 9, 0, 8, 0, 0, 0, 0, 0},
            {7, 0, 0, 0, 0, 1, 4, 2, 0},
            {0, 1, 0, 0, 6, 9, 3, 7, 0},
            {0, 2, 0, 4, 0, 0, 5, 6, 0}},
            {{0, 6, 0, 0, 0, 0, 1, 0, 0},
            {0, 3, 2, 6, 9, 0, 0, 0, 0},
            {0, 0, 5, 0, 7, 4, 0, 2, 0},
            {5, 2, 0, 3, 8, 7, 0, 9, 6},
            {4, 8, 0, 5, 6, 0, 7, 1, 2},
            {9, 7, 0, 0, 0, 0, 3, 0, 0},
            {0, 0, 7, 4, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 3, 6, 5, 0, 1},
            {0, 5, 0, 0, 0, 0, 0, 6, 4}},
            {{0, 9, 1, 5, 0, 6, 0, 0, 0},
            {0, 0, 6, 0, 0, 0, 8, 0, 0},
            {0, 2, 0, 7, 3, 0, 0, 9, 0},
            {3, 0, 4, 6, 0, 2, 7, 8, 9},
            {2, 0, 9, 4, 7, 1, 0, 5, 6},
            {5, 0, 7, 0, 0, 0, 1, 0, 0},
            {0, 0, 2, 0, 0, 0, 0, 6, 3},
            {0, 0, 0, 1, 6, 0, 2, 0, 8},
            {0, 7, 0, 0, 0, 3, 0, 0, 0}}
        }
    },
    {"hard", {
            {{0, 7, 0, 0, 9, 0, 0, 0, 0},
            {0, 2, 0, 3, 0, 0, 1, 8, 7},
            {0, 0, 0, 7, 0, 0, 0, 3, 0},
            {0, 0, 5, 0, 0, 0, 0, 0, 3},
            {0, 0, 0, 1, 6, 0, 8, 0, 9},
            {2, 1, 0, 5, 0, 0, 0, 0, 0},
            {5, 0, 8, 0, 0, 0, 7, 4, 0},
            {3, 4, 0, 6, 0, 7, 0, 0, 0},
            {1, 0, 7, 0, 0, 4, 0, 6, 0}},
            {{9, 2, 0, 0, 7, 8, 3, 0, 5},
            {0, 0, 0, 6, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 4, 0, 0, 0, 0},
            {6, 0, 0, 0, 0, 0, 4, 0, 9},
            {7, 3, 0, 0, 9, 0, 0, 6, 2},
            {0, 0, 0, 4, 0, 0, 0, 0, 8},
            {0, 9, 7, 0, 8, 6, 0, 5, 4},
            {3, 0, 0, 5, 0, 0, 6, 0, 0},
            {0, 0, 8, 0, 0, 4, 0, 0, 0}},
            {{0, 9, 0, 0, 0, 0, 1, 0, 5},
            {5, 2, 0, 0, 3, 0, 9, 4, 0},
            {0, 0, 3, 0, 4, 0, 7, 0, 8},
            {0, 8, 2, 0, 5, 0, 0, 0, 0},
            {0, 0, 0, 3, 9, 0, 0, 1, 0},
            {9, 1, 0, 0, 0, 0, 0, 0, 7},
            {7, 0, 8, 0, 1, 0, 0, 0, 0},
            {0, 4, 0, 7, 0, 0, 0, 8, 0},
            {0, 5, 1, 0, 2, 0, 0, 0, 0}}
        }
    }
};

#define N 9

bool isSafe (vector<vector<int>> &arr, int row, int col, int num) {
    for (int i = 0 ; i < N ; i++) {
        if (arr[row][i] == num || arr[i][col] == num) return false;
    }
    int boxR = row - (row % 3);
    int boxC = col - (col % 3);
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            if (arr[i + boxR][j + boxC] == num) return false;
        }
    }
    return true;
}

bool solveBoard (vector<vector<int>> &arr, int row, int col) {
    if (row == N - 1 && col == N - 1) {
        for (int i = 1 ; i <= 9 ; i++) {
            if (isSafe(arr, row, col, i)) {
                arr[row][col] = i;
                break;
            }
        }
        return true;
    }
    if (col == N) {
        row++;
        col = 0;
    }
    if (arr[row][col] != 0) return solveBoard(arr, row, col + 1);
    for (int i = 1 ; i <= 9 ; i++) {
        if (isSafe(arr, row, col, i)) {
            arr[row][col] = i;
            if (solveBoard(arr, row, col + 1)) return true;
            arr[row][col] = 0;
        }
    }
    return false;
}

bool isSolved (vector<vector<int>> &arr) {
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (arr[i][j] == 0) return false;
        }
    }
    return true;
}

void printBoard (vector<vector<int>> &arr) {
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (j == 3 || j == 6) {
                cout << " | ";
            }
            cout << arr[i][j] << " ";
        }
        if (i == 2 || i == 5) {
            cout << endl;
            for (int k = 0 ; k < N ; k++) cout << "---";
        }
        cout << endl;
    }
}

void playSudoku (vector<vector<int>> &arr, vector<vector<int>> soln) {
    int row, col, num;
    while (true) {
        printBoard(arr);
        cout << endl << endl;
        cout << "If you can't solve the board, enter -1 as row, column and number to view the solution." << endl;
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;
        cout << "Number: ";
        cin >> num;
        if (row == -1 || col == -1 || num == -1) {
            cout << endl << "The solved board is:\n";
            printBoard(soln);
            cout << endl;
            return;
        }
        
        if (isSolved(arr)) break;
        row--;
        col--;
        if (arr[row][col] != 0) {
            cout << "You cannot change the number at this position!\nTry another position :)\n";
        }
        else if (!isSafe(arr, row, col, num)) {
            cout << "Invalid try! Try again." << endl;
        }
        else arr[row][col] = num;
    }
    bool solved = true;
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (arr[i][j] == 0) {
                solved = false;
                break;
            }
        }
    }
    if (solved) {
        cout << "Congratulations! you have successfully completed the sudoku board!" << endl;
        printBoard(arr);
    }
    else cout << "Puzzle not solved. Try again." << endl;
}

sudokuBoard getPuzzle (string& diff) {
    srand(static_cast<unsigned int>(time(0)));
    vector<sudokuBoard>& puzzles = sudokuPuzzles[diff];
    int randInd = rand() % puzzles.size();
    return puzzles[randInd];
}

int main () {
    cout << "Welcome to Sudoku Solver!\n";
    int d;
    cout << "Difficulty:\n1. Easy\n2. Medium\n3. Hard\nSelect the difficulty level (1 - 3): " << endl;
    cin >> d;
    string diff;
    if (d == 1) diff = "easy";
    else if (d == 2) diff = "medium";
    else if (d == 3) diff = "hard";
    else {
        cout << "Invalid answer!\nTry again!\n";
        return 0;
    }
    vector<vector<int>> arr = getPuzzle(diff);
    vector<vector<int>> solved = arr;
    bool checker = solveBoard(solved, 0, 0);
    int a = 1;
    while (a) {
        int ans;
        cout << "1. Play game" << endl;
        cout << "2. View solution" << endl;
        cout << "3. Exit" << endl;
        cout << "Select: ";
        cin >> ans;
        cout << endl;
        switch (ans) {
            case 1:
                playSudoku(arr, solved);
                a = 0;
                break;
            case 2:
                if (solveBoard(arr, 0, 0)) {
                    cout << "The solved sudoku is: " << endl;
                    cout << endl << endl;
                    for (int i = 0 ; i < N ; i++) {
                        for (int j = 0 ; j < N ; j++) {
                            if (j == 3 || j == 6) cout << "|";
                            cout << arr[i][j] << " ";
                        }
                        if (i == 2 || i == 5) {
                            cout << endl;
                            for (int k = 0 ; k < N ; k++) {
                                cout << "---";
                            }
                        }
                        cout << endl;
                    }
                }
                else {
                    cout << "No solution!" << endl;
                }
                a = 0;
                break;
            case 3:
                a = 0;
                break;
            default:
                cout << "Invalid choice!" << endl;
                a = 1;
                break;
        }
    }
    return 0;
}