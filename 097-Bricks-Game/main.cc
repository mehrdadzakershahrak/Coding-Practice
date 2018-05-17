// The definition of this problem can be found at:
// https://www.hackerrank.com/challenges/play-game/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


long findMaxScore(vector<long> & blocks) {
    if (blocks.size() < 3) {
        long sum = 0;
        for (int i = 0; i < blocks.size(); i++) {
            sum += blocks[i];
        }
        return sum;
    }
    long s = 0;
    vector<long> score(blocks.size(), 0);
    for(int i = 0; i < 3; i++) {
        int pos = blocks.size() - 1 - i;
        s = s + blocks[pos];
        score[pos] = s;
    }
    for (int i = blocks.size()-4; i >= 0; i--) {
        s += blocks[i];
        long m = min(min(score[i+1], score[i+2]), score[i+3]);
        score[i] = s - m;
    }
    return score[0];
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<long> blocks;
        for (int j = 0; j < n; j++) {
            long x;
            cin >> x;
            blocks.push_back(x);
        }
        cout << findMaxScore(blocks) << "\n";
    }
    return 0;
}

