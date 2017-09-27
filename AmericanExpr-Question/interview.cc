#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int digitize(int n, int k) {
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans = n % 10;
        n = n / 10;
    }
    return ans;
}

vector<int> turnInt(int k) {
    vector<int> results;
    if (k == 0) { return {}; }
    if (k == 1) { return {0, 1, 8}; }
    const int start = pow(10,k-1);
    const int stop = pow(10,k);
    for (int i = start; i < stop; i++) {
        if (digitize(i,k) == digitize(i,0) && ((digitize(i,k) == 1) || (digitize(i,k) == 8))) {
            turnInt(k - 2);
        }
        else if ((digitize(i,k) == 6) || (digitize(i,k) == 9)) {
            turnInt(k - 2);
        }
    }

}

int main() {
    int n;
    cin >> n;
    auto mirrored = turnInt(n);
    for (int x : mirrored) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
