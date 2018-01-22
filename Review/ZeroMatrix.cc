// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void zeroRow(int r, vector<vector<int>> &matrix) {
    int n = matrix[0].size();
    for (int i = 0; i < n; i++) {
        matrix[r][i] = 0;
    }
}

void zero(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool rowOneHasZero = false;
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (matrix[r][c] == 0) {
                if (r == 0) {
                    rowOneHasZero = true;
                } else {
                    matrix[0][c] = 0;
                    zeroRow(r, matrix);
                    break;  // Very important!
                }
            }
        }
    }
    for (int c = 0; c < n; c++) {
        if (matrix[0][c] == 0) {
            for (int r = 0; r < m; r++) {
                matrix[r][c] = 0;
            }
        }
    }
    if (rowOneHasZero) {
        zeroRow(0, matrix);
    }
}

void printMatrix(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    cout << "m = " << m << ", n = " << n << "\n";
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            cout << matrix[r][c] << " ";
        }
        cout << "\n";
    }
}

int main () {
    vector<vector<int>> m1{{0,0,0,5},
                           {1,2,0,3},
                           {4,5,6,7}};
    printMatrix(m1);
    cout << "\n";
    zero(m1);
    printMatrix(m1);
    return 0;
}
