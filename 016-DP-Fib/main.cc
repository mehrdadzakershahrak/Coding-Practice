#include <iostream>
#include <vector>

using namespace std;

long fib(int n) {
    vector<long> memo(n+1,0);
    memo[1] = 1;
    memo[0] = 1;

    for (int i = 2; i < n + 1;i++) {
        memo[i] = memo[i - 1] + memo [i - 2];
    }
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    cout << fib(n) << '\n';
    return 0;
}
