// Compile as C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool checkPermutation(string s1, string s2) {
    int map[256] = {0};
    for (char c : s1) {
        map[c]++;
    }
    for (char c: s2) {
        map[c]--;
    }
    for (int i = 0; i < 256; i++) {
        if (map[i] != 0) { return false;} 
    }
    return true;
}

int main() {
    cout << checkPermutation("abc", "bca") << "\n";
    cout << checkPermutation("cabcc", "bccca") << "\n";
    cout << checkPermutation("abc", "hello") << "\n";
    return 0;
}
