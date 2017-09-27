// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cell {
    int row;
    int col;
};

long countWaysDown(int r, int c, vector<cell> & obstacles) {
    vector<vector <long>> DP(r, vector<long>(c, -1));

    for (int i = 0; i < r; i++) {
        DP[i][c - 1] = 1;
    }
    for (int i = 0; i < c; i++) {
        DP[r - 1][i] = 1;
    }
    for (auto& obs : obstacles) {
        DP[obs.row][obs.col] = 0;
        if (obs.row == r - 1 && obs.col == c - 1) {
            return 0;
        }
    }
    for (int i = r - 2; i >= 0; i--) {
        for (int j = c - 2; j >= 0; j--) {
            if (DP[i][j] == -1) {
                DP[i][j] = DP[i][j + 1] + DP[i + 1][j];
            }
        }
    }
    return DP[0][0];
}

bool hasWay(int r, int c, vector<cell> & obstacles) {
    vector<vector <int>> DP(r, vector<int>(c, -1));

    for (int i = 0; i < r; i++) {
        DP[i][c - 1] = 1;
    }
    for (int i = 0; i < c; i++) {
        DP[r - 1][i] = 1;
    }
    for (auto& obs : obstacles) {
        DP[obs.row][obs.col] = 0;
        if (obs.row == r - 1 && obs.col == c - 1) {
            return 0;
        }
    }
    for (int i = r - 2; i >= 0; i--) {
        for (int j = c - 2; j >= 0; j--) {
            if (DP[i][j] == -1) {
                DP[i][j] = min(1, DP[i][j + 1] + DP[i + 1][j]);
            }
        }
    }
    return DP[0][0] > 0;
}

int main(int argc, char* argv[])
{
    int r,c,o;
    cin >> r >> c >> o;
    vector<cell> obstacles;
    for (int i = 0; i < o; i++) {
        int row, col;
        cin >> row >> col;
        obstacles.push_back({row,col});
    }
    cout << countWaysDown(r, c, obstacles) << '\n';
    cout << hasWay(r, c, obstacles) << '\n';
    return 0;
}
