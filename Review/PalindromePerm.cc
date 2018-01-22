// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool palindromePerm(string s) {
    int map[256] = {0};
    
    for (char c : s) {
        c = tolower(c);
        if (c != ' ') {
            map[c]++;
        }
    }
    int odd = 0;
    for (int i = 0; i < 256; i++) {
        if (map[i] % 2 == 1) { odd++; }    
    }
    return odd <= 1;
}

int main () {
    cout << palindromePerm("Tact Coa    ") << "\n";

    return 0;
}
