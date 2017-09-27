#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Matrix {
    private:
        vector<vector<int>> data;
    public:
        size_t rows;
        size_t cols;

        Matrix(size_t m, size_t n)
            : data{m, vector<int>(n,0)}, rows{m}, cols{n}
       {
        }
        int& operator()(int row, int col) {
            return data[row][col];
        }
        const int& operator()(int row, int col) const {
            return data[row][col];
        }
};

void zeroMatrix(Matrix& matrix) {
    vector<bool> zeroCols(matrix.cols, false);
    for (int r = 0; r < matrix.rows; r++) {
        bool hasZero = false;
        for (int c = 0; c < matrix.cols; c++) {
            if (matrix(r, c) == 0) {
                zeroCols[c] = true;
                hasZero = true;
            }
        }
        if (hasZero) {
            for (int c = 0; c < matrix.cols; c++) {
                matrix(r, c) = 0;
            }
        }
    }
    for (int c = 0; c < matrix.cols; c++) {
        if (zeroCols[c]) {
            for (int r = 0; r < matrix.rows; r++) {
                matrix(r,c) = 0;
            }
        }
    }
}

void zeroRow(Matrix& matrix, int row) {
    for (int c = 0; c < matrix.cols; c++) {
        matrix(row, c) = 0;
    }
}

void zeroCol(Matrix& matrix, int col) {
    for (int r = 0; r < matrix.rows; r++) {
        matrix(r, col) = 0;
    }
}

void zeroMatrix2(Matrix& matrix) {
    bool firstRowHasZero = false;
    for (int r = 0; r < matrix.rows; r++) {
        bool hasZero = false;
        for (int c = 0; c < matrix.cols; c++) {
            if (matrix (r, c) == 0) {
                hasZero = true;
                matrix(0, c) = 0;
            }
        }
        if (hasZero) {
            if (r == 0) {
                firstRowHasZero = true;
            }
            else {
                zeroRow(matrix, r);
            }
        }
    }
    for (int c = 0; c < matrix.cols; c++) {
        if (matrix(0, c) == 0) {
            zeroCol(matrix, c);
        }
    }
    if (firstRowHasZero) {
        zeroRow(matrix, 0);
    }
}

int main(){
  int m,n;
  cin >> m >> n;
  stack<unsigned long> scores;
  Matrix matrix(m, n);
  for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> matrix(i, j);
      }
  }
  zeroMatrix(matrix);
  for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << matrix(i, j) << ' ';
      }
      cout << endl;
  }
  return 0;
}
