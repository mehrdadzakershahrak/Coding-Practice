#include <map>
#include <set>
#include <list>
#include <cctype>
#include <cmath>
#include <stack>
#include <deque>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void rotate_matrix_cc(vector<vector<int> >& matrix, int n) {
    for (int row = 0; row < n / 2; row++) {
        for (int col = row; col < n - row - 1; col++){
            int tmp = matrix[row][col];
            matrix[row][col] = matrix[col][n - 1 - row];
            matrix[col][n - 1 - row] = matrix[n - 1 - row][n - 1 - col];
            matrix[n - 1 - row][n - 1 - col] = matrix[n - 1 - col][row];
            matrix[n - 1 - col][row] = tmp;
        }
    }
}


void rotate_matrix_c(vector<vector<int> >& matrix, int n) {
    for (int row = 0; row < n / 2; row++) {
        for (int col = row; col < n - row - 1; col++){
            int tmp = matrix[row][col];
            matrix[row][col] = matrix[n - 1 - col][row];
            matrix[n - 1 - col][row] = matrix[n - 1 - row][n - 1 - col] ;
            matrix[n - 1 - row][n - 1 - col] = matrix[col][n - 1 - row] ;
            matrix[col][n - 1 - row] = tmp;
        }
    }
}

void print_matrix(vector<vector < int > >& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    int n;
    cin >> n;
    vector <vector<int> > matrix(n,vector<int>(n,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << '\n';
    print_matrix(matrix, n);
    cout << '\n';
//    rotate_matrix_cc(matrix, n);
  //  print_matrix(matrix, n);
    rotate_matrix_c(matrix, n);
    cout << '\n';
    print_matrix(matrix, n);
    return 0;
}
