#include <bits/stdc++.h>

using namespace std;

string solve(vector < int > a){
    int left = 0; int right = 0;
    int i = 0, pos = 0;
    int j = a.size() - 1;
    while (j > i) {
        right += a[j];
        j--;
    }
    while (pos < a.size() - 1) {
        left += a[pos];
        right -= a[pos + 1];
        if (left == right) {
            return "YES";
        }
        pos++;
    }
    return "NO";    
}

int main() {
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        string result = solve(a);
        cout << result << endl;
    }
    return 0;
}

