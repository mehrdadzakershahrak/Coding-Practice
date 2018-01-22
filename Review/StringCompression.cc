// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string compress(string s) {
    string result;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        int repeat = 0;
        while (s[i] == c && i < s.size()) {
            i++;
            repeat++;
        }
        i--;
        result += c + to_string(repeat);
    }
    return (result.size() > s.size() ? s : result);
}

struct Test {
    string input;
    string want;
};

int main () {
    vector<Test> testCases{{"aabcccccaaa", "a2b1c5a3"},
                           {"pales", "pales"},
                           {"hhaacccdd", "h2a2c3d2"},
                           {"hhaacd", "hhaacd"}};
    for (Test tc : testCases) {
        auto got = compress(tc.input);
        cout << (tc.want == got ? "OK " : "Failed ");
        cout << tc.input << " -> " << got << "\n";
    }
    return 0;
}
