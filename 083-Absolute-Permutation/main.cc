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

void perm(int n, int k) {
    if (k == 0) {
        for (int i = 1; i <= n; i++){
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    if (((n/k) % 2 == 1) || (n%k != 0)) { cout << "-1 \n"; return;}
    int step = (n/k);
    for (int i = 0; i < n; i++) {
        if ((i/k) % 2 == 0) {
            cout << i+k+1 <<" ";
        }
        else {
            cout << i-k+1 << " ";
        }
    }
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        perm(n, k);
    }
    return 0;
}
