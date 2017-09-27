#include <iostream>
#include <vector>

using namespace std;

long countWaysToChange(const vector<int>& coins, int money) {
    int C = coins.size();
    // DP[c, m] means the number of ways we can change m only using
    // the first c coins
    vector<vector<long>> DP(C + 1, vector<long>(money + 1, 0));
    for (int c = 0; c <= C; c++) {
        DP[c][0] = 1;
    }
    for (int m = 1; m <= money; m++) {
        for (int c = 1; c <= C; c++) {
            int rem = m - coins[c - 1];
            DP[c][m] = DP[c - 1][m] + (rem < 0 ? 0 : DP[c][rem]);
        }
    }
    return DP[C][money];
}

int main() {
    int money;
    int n;
    cin >> money >> n;
    vector<int> coins;
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        coins.push_back(c);
    }
    cout << countWaysToChange(coins, money) << "\n";
    return 0;
}

