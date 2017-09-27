#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector<int> & arr) {
    for (int x : arr) {
        cout << x << ' ';
    }
    cout << '\n';
}

void insertionSort(vector <int> & arr) {
    for (int j = 1; j < arr.size(); j++) {
        int e = arr[j];
        bool inserted = false;
        for (int i = j - 1; i >= 0; i--) {
            if (e < arr[i]) {
                arr[i + 1] = arr[i];
            }
            else {
                arr[i + 1] = e;
                inserted = true;
                break;
            }
        }   
        if (!inserted) { arr[0] = e;}
        print(arr);
    }
}
int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }
    insertionSort(_ar);
    return 0;
}
