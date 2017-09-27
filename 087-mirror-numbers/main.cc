#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include "custom_base.h"

using namespace std;

int digitize(long n, int k) {
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans = n % 10;
        n = n / 10;
    }
    return ans;
}

bool mirrorCheck(long n, int d, int digits) {
    if (digits % 2 == 0 && d > (digits/2)){
        return true;
    }
    if (digits % 2 == 1 && d == (digits/2) + 1){
        int value = digitize(n,d);
        return (value == 0 || value == 1 || value == 8);
    }
    int last = digitize(n,d);
    int first = digitize(n,digits-d+1);
    if ((first == last && (first == 1 || first == 8 || (first == 0 && d > 1) )) ||
        (first == 6 && last == 9) ||
        (first == 9 && last == 6)) {
        return mirrorCheck(n, d+1, digits);
    }
    return false;
}

vector<long> turnInt(int k) {
    initializer_list<char> symbols{'0','1','6','8','9'};
    vector<long> results;
    if (k == 0) { return {}; }
    if (k == 1) { return {0, 1, 8}; }
    Base<5> start{"1" + string(k-1,'0'),symbols};
    Base<5> stop{"1" + string(k,'0'),symbols};
    while(start < stop) {
        string s = start.toString();
        long i = stol(s);
        if (mirrorCheck(i,1,k)) {
            results.push_back(i);
        }
        start++;
    }
    return results;
}

vector<long> turnInt2(int k) {
    vector<long> results;
    if (k == 0) { return {}; }
    if (k == 1) { return {0, 1, 8}; }
    long start = pow(10,k-1);
    long stop = pow(10,k);
    while(start < stop) {
        if (mirrorCheck(start,1,k)) {
            results.push_back(start);
        }
        start++;
    }
    return results;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        auto mirrored = turnInt2(i);
        cout << "Found " << mirrored.size() << " for size " << i << "\n";
        for (int x : mirrored) {
            cout << x << "\n";
        }
    }
    return 0;
}
