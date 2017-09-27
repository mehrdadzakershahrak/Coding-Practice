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
int stair (int n) {
    int a[] = {1, 2, 4};
    if (n < 4) {
        return a[n - 1];
    }
    for (int i = 3; i < n; i++) {
        int total = a[0] + a[1] + a[2];
        a[0] = a[1];
        a[1] = a[2];
        a[2] = total;
    }
    return a[2];
}

int main(){
    int n;
    cin >> n;
    cout << stair(n) << '\n';

    return 0;
}
