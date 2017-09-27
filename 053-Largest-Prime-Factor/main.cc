#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

vector<long> primeList(int n) {
    vector<bool> numbers(n + 1, true);
    for (int i = 2; i <= sqrt(n); i++) {
        if (numbers[i]) {
            for (int j = i * i; j <= n; j+=i) {
                numbers[j] = false;
            }
        }
    }
    vector<long> primes;
    for (int i = 2; i <= n; i++) {
        if (numbers[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

long smallestPrimefactor(long n, vector<long> primes) {
    
    for (auto p : primes) {
        if (n % p == 0) {
            return p;
        }
    }
    return n;
}

long largestPrimefactor(long n, vector<long> primes) {
    long small = smallestPrimefactor(n, primes);
    if (n == small) {
        return n;
    }
    return largestPrimefactor(n / small , primes);
 }

int main(){
    int t;
    cin >> t;
    vector<long> primes = primeList(1000005);
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        cout << largestPrimefactor(n, primes) << '\n';
    }
    return 0;
}

