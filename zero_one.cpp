#include <bits/stdc++.h>
using namespace std;

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack(int capacity, vector<int> &weights, vector<int> &values, int n, vector<int> &selected) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Backtrack to find selected items
    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--) {
        // Check if the item was included by comparing values
        if (dp[i][w] != dp[i - 1][w]) {
            selected[i - 1] = 1; // Mark this item as selected
            w -= weights[i - 1]; // Reduce remaining weight
        }
    }

    return dp[n][capacity]; // Maximum value for the given capacity
}

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n), values(n), selected(n, 0); // Initialize selected with 0s

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int maxValue = knapsack(capacity, weights, values, n, selected);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;
    cout << "Items selected (1 means selected, 0 means not selected): (";
    for (int i = 0; i < n; ++i) {
        cout << selected[i];
        if (i != n - 1) cout << ", ";
    }
    cout << ")" << endl;

    return 0;
}
