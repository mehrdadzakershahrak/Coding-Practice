#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
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

using namespace std;

vector<int> primeList(int n) {
    vector<bool> numbers(n + 1, true);
    for (int i = 2; i <= sqrt(n); i++) {
        if (numbers[i]) {
            for (int j = i * i; j <= n; j+=i) {
                numbers[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (numbers[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}


int main(){
    int t;
    cin >> t;
    vector<int> primes = primeList(104730);
    cerr << "size of prime list is: " << primes.size() << '\n';
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout << primes[n - 1] << '\n';
    }
    
    
    return 0;
}

