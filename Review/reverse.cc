#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void strrev(string &s) {
    reverse(s.begin(), s.end());
}

int main() {
    string inp;
    cin >> inp;
    strrev(inp);
    cout << inp << "\n";
    return 0;
}
