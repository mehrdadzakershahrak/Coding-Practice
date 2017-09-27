// Given an array of integers, find and print the maximum number of integers you can select from the array such that the absolute difference between any two of the chosen integers is less than or equal to one.

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
int solve(vector<int> arr) {
    vector<int> counts(100);
    
    for (int number : arr) {
			counts[number]++;
    }
    int result = *max_element(begin(counts), end(counts));
    
    for(int i = 0; i + 1 < counts.size(); i++){
       result = max(result, counts[i] + counts[i + 1]);
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    cout << solve(a) << endl;
    return 0;
}

