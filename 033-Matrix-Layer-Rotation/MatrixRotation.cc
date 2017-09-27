#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void rotateLayerOnce(vector<vector<int>>& a, int m, int n, int layer) {
    int tmp = a[layer][layer];
    for (int j = layer + 1; j < n - layer; j++) {
        a[layer][j - 1] = a[layer][j];
    }
    for (int i = layer + 1; i < m - layer; i++) {
        a[i - 1][n - 1 - layer] = a[i][n - 1 - layer];
    }
    for (int j = n - 1 - layer; j >= layer + 1; j--) {
        a[m - 1 - layer][j] = a[m - 1 - layer][j - 1];
    }
    for (int i = m - 1 - layer; i >= layer + 1; i--) {
        a[i][layer] = a[i - 1][layer];
    }
    a[layer + 1][layer] = tmp;
}

void rotate(vector<vector<int>>& a, int m, int n, int r) {
    for (int layer = 0; layer < min(m, n) / 2; layer++) {
        int size = 2 * (m + n - 2 - 4 * layer);
        int rot = r % size;
        for (int i = 0; i < rot; i++) {
            rotateLayerOnce(a, m, n, layer);
        }
    }
}

int main() {
    int m, n, r;
    cin >> m >> n >> r;
    vector<vector<int>> a(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    rotate(a, m, n, r);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
