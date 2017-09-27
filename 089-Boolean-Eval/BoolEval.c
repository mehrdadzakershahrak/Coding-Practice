// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>


using namespace std;

bool applyOperator(char op, bool left, bool right) {
    switch (op) {
        case '&': return left && right;
        case '|': return left || right;
        case '^': return left ^ right;
        default : throw runtime_error("This should not happen!");
    }
}

vector<bool> countEval(string expr, unordered_map<string, vector<bool>> & memo) {
    if (expr.size() == 1) { return {expr[0] == '1'}; }
    if (memo.find(expr) != memo.end()) { return memo[expr]; }
    vector<bool> v;
    for (int k = 0; k <= expr.size(); k++) {
        if (expr[k] == '&' || expr[k] == '^' || expr[k] == '|') {
            auto left = countEval(expr.substr(0,k), memo);
            auto right = countEval(expr.substr(k+1), memo);
            for (bool x: left) {
                for (bool y : right) {
                    v.push_back(applyOperator(expr[k], x, y));
                }
            }
        }
    }
    memo[expr] = v;
    return v;
}

int countEval(string expr, bool result) {
    unordered_map<string, vector<bool>> memo;
    auto v = countEval(expr, memo);
    int count = 0;
    for (bool x : v) {
        if (x == result) {
            count++;
        }
    }
    return count;
}

int main(int argc, char* argv[])
{
    string expr;
    cin >> expr;
    bool result;
    cin >> result;
    cout << countEval(expr, result) << "\n";
    return 0;
}
