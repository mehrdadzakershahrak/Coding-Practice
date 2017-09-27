#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int next_element(const vector<int>& arr, unsigned i) {
    i++;
    while (i < arr.size() && arr[i] < 0) { i++; }
    return (i < arr.size() ? arr[i] : 1);
}

int prev_element(const vector<int>& arr, unsigned i) {
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

int brute_force(vector<int>& arr) {
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
    cout << "max orders:\n";
    for (auto& mo : maxOrders) {
        for (int i : mo) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return maxCoins;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << brute_force(arr) << "\n";
    return 0;
}
