#include <iostream>
#include <vector>
using namespace std;

int totalSolutions = 0;

void printSolution(const vector<int> &solution, int n) {
    cout << "\nSolution #" << ++totalSolutions << ": [";
    for (int i = 0; i < n; i++)
        cout << solution[i] + 1 << (i < n - 1 ? ", " : "]\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (solution[i] == j ? " Q " : " * ");
        cout << endl;
    }
}

bool isSafe(const vector<int> &solution, int row, int col) {
    for (int i = 0; i < row; i++)
        if (solution[i] == col || abs(solution[i] - col) == row - i) return false;
    return true;
}

void solve(vector<int> &solution, int row, int n) {
    if (row == n) return printSolution(solution, n);
    for (int col = 0; col < n; col++)
        if (isSafe(solution, row, col))
            solution[row] = col, solve(solution, row + 1, n);
}

int main() {
    int n;
    cout << "Enter number of Queens: ";
    cin >> n;

    vector<int> solution(n);
    solve(solution, 0, n);

    cout << "\nTotal solutions = " << totalSolutions << endl;
    return 0;
}
