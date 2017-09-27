#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int next_element(const vector<int>& arr, int i) {
    i++;
    while (i < arr.size() && arr[i] < 0) { i++; }
    return (i < arr.size() ? arr[i] : 1);
}

int prev_element(const vector<int>& arr, int i) {
    i--;
    while (i >= 0 && arr[i] < 0) { i--; }
    return (i >= 0 ? arr[i] : 1);
}

int burst_balloons(vector<int> arr, vector<int> order) {
    int coins = 0;
    for (int i : order) {
        coins += arr[i] * next_element(arr, i) * prev_element(arr, i);
        arr[i] = -1;
    }
    return coins;
}

int brute_force(vector<int> arr, bool printMaxOrders = false) {
    const int n = arr.size();
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }
    int maxCoins = 0;
    vector<vector<int>> maxOrders;
    do {
        int coins = burst_balloons(arr, order);
        if (coins == maxCoins) {
            maxOrders.push_back(order);
        }
        if (coins > maxCoins) {
            maxCoins = coins;
            maxOrders.clear();
            maxOrders.push_back(order);
        }
    } while (next_permutation(order.begin(), order.end()));
    if (printMaxOrders) {
        cout << "max orders:\n";
        for (auto& mo : maxOrders) {
            for (int i : mo) {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
    return maxCoins;
}

int dp_top_down(const vector<int>& arr, int i, int j, vector<vector<int>>& memo) {
    const int n = arr.size();
    if (j < i) { return 0; }
    if (memo[i][j] != -1) { return memo[i][j]; }
    int maxValue = 0;
    for (int k = i; k <= j; k++) {
        int value = arr[k] * (i > 0 ? arr[i-1] : 1) * (j < n-1 ? arr[j+1] : 1);
        value += dp_top_down(arr, i, k-1, memo);
        value += dp_top_down(arr, k+1, j, memo);
        maxValue = max(maxValue, value);
    }
    memo[i][j] = maxValue;
    return maxValue;
}

int dp_top_down(vector<int> arr) {
    const int n = arr.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    return dp_top_down(arr, 0, n-1, memo);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Brute force: " << brute_force(arr, true) << "\n";
    cout << "DP top-down: " << dp_top_down(arr) << "\n";
    return 0;
}
