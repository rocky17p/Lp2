#include <bits/stdc++.h>
using namespace std;

int N;
int totalSolutions = 0;
vector<int> board; // board[row] = column
vector<int> oneSolution;

// Check if safe to place queen
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        int c = board[i];
        if (c == col || abs(c - col) == abs(i - row))
            return false;
    }
    return true;
}

// Backtracking
void solve(int row) {
    if (row == N) {
        totalSolutions++;

        // store first solution
        if (oneSolution.empty())
            oneSolution = board;

        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

// Print board
void printBoard(vector<int> &sol) {
    cout << "\nOne Solution:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (sol[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter N (<=14): ";
    cin >> N;

    board.resize(N);

    solve(0);

    cout << "\nTotal Solutions = " << totalSolutions << endl;

    if (!oneSolution.empty()) {
        printBoard(oneSolution);
    } else {
        cout << "No solution exists\n";
    }
}
