#include <bits/stdc++.h>
using namespace std;
// Function to solve 0/1 Knapsack Problem
void knapSack(int C, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(C + 1));

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wt[i] <= j)
                dp[i][j] = max(val[i] + dp[i - 1][j - wt[i]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << "Maximum value in Knapsack = " << dp[n][C] << endl;
}

int main() {
         //wt=10,20,30
    //p=60, 100, 120
    //C=50
    int n, C;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);
    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> C;

    // Calling the knapsack function
    knapSack(C, weights, values);

    return 0;
}
