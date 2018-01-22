// Compile as C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isUnique(string s) {
    int map[256] = {0};
    
    for (int i = 0; i < s.size(); i++) {
        map[s[i]]++;
        if (map[s[i]] > 1) { return false; } 
    }
    return true;
}

bool isUnique(string s) {
    int map[256] = {0};
    for (char c : s) {
        map[c]++;
        if (map[c] > 1) { return false; }
    }
    return true;
}
