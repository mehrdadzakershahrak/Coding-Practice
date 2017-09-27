#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector < int > s, int d, int m){
    
    int ways = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        int j = 0;
        while (j < m) {
            sum += s[i+j];
            j++;
        }
        if (sum == d) {
            ways++;
        }
    }
    
    return ways;
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cin >> d >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}

