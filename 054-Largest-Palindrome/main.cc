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

bool palindrome (int n) {
    if (n < 100000) {
        return false;
    }
    int num = n;
    int digit[3];
    int i = 0;
    while (i < 3) {
        digit[i] = num % 10;
        num = num / 10;
        i++;
    }
    int x = digit[0] * 100 + digit[1] * 10 + digit[2];
    return x == num;
}

set<int> preProcess() {
    set<int> ans;
    for (int i = 100; i < 999; i++) {
        for (int j = i + 1; j < 1000; j++) {
            if (palindrome(i * j)) {
                ans.insert(i * j);
            }
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    set<int> ans = preProcess();
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        auto it = ans.lower_bound(n);
        it--;
        cout << *it << '\n';
    }
    return 0;
}

