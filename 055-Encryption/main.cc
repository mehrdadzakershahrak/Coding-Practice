// The description is available at :
// https://www.hackerrank.com/challenges/encryption/copy-from/47453979
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

string cipher (string s) {
    string code;
    int row = floor(sqrt(s.size()));
    int col = ceil(sqrt(s.size()));
    if (col == row) {row -= 1;}
    for (int i = 0; i <= row; i++) {
        for (int j = i; j < s.size(); j+=col) {
            code += s[j];
        }
        code += ' ';
    }
    return code;
}

int main(){
    string s;
    cin >> s;
    string output = cipher(s);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i];
    }
    cout << '\n';
    return 0;
}
