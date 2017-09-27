// You are given an array of  integers,a0,a1,...,an-1 , and a positive integer,k. Find and print the number of pairs where i < j and ai + aj is divisible by.
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    unordered_map<int,int> map;
    for (auto s : a) {
        map[s % k]++;
    }
    int count = 0;
    int right,left;
    if (k % 2 == 0) {
        count += (map[0] * (map[0] - 1)) / 2;
        count += (map[k/2] * (map[k/2] - 1)) / 2;
        right = k - 1;
        left = 1;
        while (left < right && left + right == k) {
            count += (map[left] * map [right]);
            left++;
            right--;
        }
    }
    else {
        count = (map[0] * (map[0] - 1)) / 2;
        right = k - 1;
        left = 1;
        while (left < right && left + right == k) {
            count += (map[left] * map [right]);
            left++;
            right--;
        }
    }
    cout << count <<'\n';
    return 0;
}

