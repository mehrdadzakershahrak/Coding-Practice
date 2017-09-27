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


long long mergeHalves(vector<int>& arr,vector<int>& tmp, int start, int end) {
    int mid = (start + end) / 2;
    int rightStart = mid + 1;
    int leftStart = start;
    int rightEnd = end;
    int leftEnd = mid;
    
    long long count = 0;
    
    int L = leftStart;
    int R = rightStart;
    int i = start;
    while (L <= leftEnd && R <= rightEnd) {
        if (arr[L] <= arr[R]) {
            tmp[i] = arr[L];
            L++;
        }
        else {
            tmp[i] = arr[R];
            count += (R - i);
            R++;
        }
        i++;
    }
    while(L <= leftEnd) {
        tmp[i] = arr[L];
        i++;
        L++;
    }
    while(R <= rightEnd) {
        tmp[i] = arr[R];
        i++;
        R++;
    }
    for (i = start; i <= end; i++) {
        arr[i] = tmp[i];
    }
    return count;
}


long long merge_sort(vector<int>& arr, vector<int>& tmp, int start, int end) {
   if (start >= end) {
       return 0;
   }
   int mid = (start + end) / 2;
   auto c1 = merge_sort(arr, tmp, start, mid);
   auto c2 = merge_sort(arr, tmp, mid + 1, end);
   auto ans = mergeHalves(arr, tmp, start, end);
   return c1 + c2 + ans;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0;arr_i < n;arr_i++){
           cin >> arr[arr_i];
        }
        vector<int> tmp(arr.size(),0);
        cout << merge_sort(arr, tmp, 0,arr.size() - 1) << endl;
    }
    return 0;
}

