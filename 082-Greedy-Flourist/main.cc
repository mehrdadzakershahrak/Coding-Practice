// The description is available at:
// https://www.hackerrank.com/challenges/greedy-florist/problem
#include <bits/stdc++.h>

using namespace std;

int getMinimumCost(int n, int k, vector<int> & cost){
    sort(cost.begin(), cost.end(), greater<int>());
    vector<vector<int>> assignment(k);
    int p = 0;
    for (int c : cost) {
        assignment[p].push_back(c);
        p = (p + 1) % k;
    }
    int totalCost = 0;
    for (auto & elem : assignment) {
        int x = 0;
        for (int c : elem) {
            totalCost += (x + 1) * c;
            x++;
        }
    }
    return totalCost;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    int minimumCost = getMinimumCost(n, k, c);
    cout << minimumCost << endl;
    return 0;
}


