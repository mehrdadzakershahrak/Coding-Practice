#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

string decomp (string s) {
    string result;
    int i = 0;
    while (i < s.size()) {
        if (!isdigit(s[i])) {
            result += s[i];
            i++;
            continue;
        }
        int number = 0;
        string substr;
        while (isdigit(s[i])) {
            number = number * 10 + (s[i] - '0');
            i++;
        }
        i++;
        int match = 1;
        while (match > 0) {
            if (s[i] == '[') {
                match++;
            }
            if (s[i] == ']') {
                match--;
            }
            substr += s[i];
            i++;
        }
        substr = decomp(substr.substr(0,substr.size()-1));
        for (int repeat = 0; repeat < number; repeat++) {
            result += substr;
        }
    }
    return result;
}

int main()
    string inp;
    cin >> inp;
    cout << decomp(inp) << "\n";
    return 0;
}
