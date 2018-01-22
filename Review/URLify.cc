// Compile as C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void URLify(string &s, int length) {
    int j = s.size() - 1;
    for (int i = length - 1; i >= 0; i--) {
       if (s[i] != ' ') {
           s[j--] = s[i];
       }
       else {
           s[j--] = '0';
           s[j--] = '2';
           s[j--] = '%';
       }
    }
}

string addGap(string s) {
    int spaces = 0;
    for (char c : s) {
        if (c == ' ') {
            spaces++;
        }
    }
    return s + string(2*spaces, ' ');
}

int main () {
    string s = "Mr John Smith";
    string t = addGap(s);
    cout << "s = '" << s << "'\n";
    cout << "t = '" << t << "'\n";
    URLify(t, s.size());
    cout << "t = '" << t << "'\n";
    return 0;
}
