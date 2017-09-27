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

using namespace std;

string compressed(string str) {
    ostringstream oss;
    int i = 0;
    while (i < str.size()) {
        int count = 0;
        char c = str[i];
        while (i < str.size() && str[i] == c) {
            i++;
            count++;
        }
        if (i != str.size()) {
            i--;
        }
        oss << c << count;
        i++;
    }
    string ans = oss.str();
    return (str.size() < ans.size() ? str : ans);
}

int main(){
    string x;
    cin >> x;
    cout << compressed(x) << endl;
    return 0;
}

