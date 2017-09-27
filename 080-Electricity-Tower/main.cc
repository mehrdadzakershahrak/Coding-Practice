#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int minTowers(int k, const vector<bool> & hasTower) {
    const int n = hasTower.size();
    int t = 0;
    int towerCount = 0;
    while (t < n) {
        int ti = min(t + k - 1, n - 1);
        int higher = max(0, t - k + 1);
        bool found = false;
        while (ti >= higher) {
            if (hasTower[ti]) {
                found = true;
                break;
            }
            ti--;
        }
        if (!found) { return -1;}
        towerCount++;
        t = ti + k;
    }
    return towerCount;
}

int main() {
    int k, n;
    cin >> n >> k;
    vector<bool> hasTower(n);
    for (int i = 0; i < n; i++) {
        int tower;
        cin >> tower;
        hasTower[i] = tower;
    }
    cout << minTowers(k, hasTower) << "\n";
    return 0;
}


