#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>


using namespace std;

void rotate_matrix(vector<vector<int>>& matrix, int m, int n, int r) {
    vector<vector<int>> dup = duplicate_matrix(matrix);
    for (int layer = 0; layer < min(m, n) / 2; layer++) {
        int size = 2 * (m + n - 2 - 4 * layer);
        int rot = r % size;
    }
}

void print_matrix(vector<vector < int > >& matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    int m,n,r;
    cin >> m >> n >> r;
    vector <vector<int>> matrix(m,vector<int>(n,0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << '\n';
    print_matrix(matrix, m, n);
    cout << '\n';
    rotate_matrix(matrix, m, n , r);
    print_matrix(matrix, m, n);
	cout << '\n';
}
