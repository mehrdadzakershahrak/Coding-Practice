// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
// See Cathanaln numbers for more problems related to this

vector<string> validParenHelper(string prefix, int n, int leftCount, int rightCount) {
    if (leftCount == n) {
        while (rightCount < n) {
            prefix += ')';
            rightCount++;
        }
        return {prefix};
    }
    auto p = validParenHelper(prefix + '(', n, leftCount+1, rightCount);
    if (rightCount < leftCount) {
        auto r = validParenHelper(prefix + ')', n, leftCount, rightCount+1);
        p.insert(p.end(), r.begin(), r.end());
    }
    return p;
}

vector<string>validParen(int n) {
    return validParenHelper(" ", n, 0, 0);
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    auto valid = validParen(n);
    for (auto& e : valid) {
        //cout << e << '\n';
    }
    cout << valid.size() << "\n";
    return 0;
}
