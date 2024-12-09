#includ<bits/stdc++.h>


using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int capacity, vector<int>& weights, vector<int>& profits, int n) {
    // Create a 2D DP table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], profits[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    // Input number of items and capacity of knapsack
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<int> weights(n), profits(n);

    // Input weights and profits
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    // Solve the knapsack problem
    int maxProfit = knapsack(capacity, weights, profits, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
