// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

bool oneAway(string s1, string s2) {
    if (abs((int)s1.size() - (int)s2.size()) > 1) { return false;}
    int j = 0;
    bool oneEdit = false;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[j]) {
            j++;
        }
        else {
            if (oneEdit) {
                return false;
            }
            if (s1.size() == s2.size()) { j++;}
            oneEdit = true;
        }
    }
    return true;
}

struct Test {
    string a;
    string b;
    bool result;
};

int main () {
    vector<Test> testCases{{"pale", "ple", true},
                           {"pales", "pale", true},
                           {"pale", "bale", true},
                           {"pale", "bake", false}};
    for (Test tc : testCases) {
        cout << tc.a << ", " << tc.b << " -> " << oneAway(tc.a, tc.b);
        cout << " want " << tc.result << "\n";
    }
    return 0;
}
