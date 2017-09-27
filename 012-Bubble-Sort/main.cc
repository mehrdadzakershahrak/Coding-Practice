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

int bubbleSort(vector<int>& arr) {
    int total = 0;
    int n = arr.size();
    while (true) {
        int numberOfSwaps = 0;

        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                numberOfSwaps++;
            }
        }

        if (numberOfSwaps == 0) {
            break;
        }
        n--;
        total += numberOfSwaps;
    }
    return total;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    int result;
    result = bubbleSort(a);
    cout << "Array is sorted in " << result << " swaps."<<'\n';
    cout << "First Element: " << a[0] << '\n';
    cout << "Last Element: " << a[a.size() - 1] << '\n';
    
    return 0;
}

