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
#include <unordered_set>

using namespace std;

bool HasPairWithSums(vector<int> arr, int sum) {
unordered_set<int> comp;
for (int value : arr) {
    if (comp.find(value) != comp.end())
        return true;
    comp.insert(sum - value);
}
return false;

}

int main() {
    int sum;
    int m;
    cin >> sum >> m;
    vector<int> arr(m);
    
    for (int arr_i = 0;arr_i < arr.size(); arr_i++) {
        cin >> arr[arr_i];            

    }
 cout<< HasPairWithSums(arr, sum)<< '\n';
    return 0;
}
