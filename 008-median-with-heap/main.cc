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

template<class Compare>
class Heap {
    private:
        Compare compareFn;
        vector<int> items;
    public:
        void add(int x) {
            items.push_back(x);
            push_heap(items.begin(), items.end(), compareFn);
        }
    
        void remove() {
            pop_heap(items.begin(), items.end(), compareFn);
            items.pop_back();
        }
        void swapRoot(int value) {
            items[0] = value;
            make_heap(items.begin(), items.end(), compareFn);
        }
        int root() {
            return items[0];
        }
    
        int size() {
            return items.size();
        }

        void print() {
            for (auto x : items) {
                cout << x << " ";
            }
            cout << "\n";
        }
};

using MaxHeap = Heap<less<int>>;
using MinHeap = Heap<greater<int>>;


float medianOfSortedArray(const vector<int>& a) {
    if (a.size() % 2 == 1) {
        return a[a.size() / 2];
    }
    else {
        return (a[a.size() / 2] + a[a.size() / 2 - 1]) / 2.0;
    }
}

float findMedian(MaxHeap& minH, MinHeap& maxH) {
    if (maxH.size() == minH.size()) {
        return (maxH.root() + minH.root()) / 2.0;
    }
    else if (maxH.size() > minH.size()) {
        return maxH.root();
    }
    else
        return minH.root();
}

int main(){
    int n;
    cin >> n;
    MinHeap minH;
    MaxHeap maxH;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (maxH.size() > minH.size()) {
            minH.add(x);
        }
        else {
            maxH.add(x);
        }
        if (maxH.size() > 0 && minH.size() > 0) {
            if (maxH.root() > minH.root()) {
                int a = maxH.root();
                int b = minH.root();
                maxH.remove();
                minH.remove();
                maxH.add(b);
                minH.add(a);
            }
        }
        float median = findMedian(maxH, minH);
        cout.precision(1);
        cout.setf( ios::fixed, ios::floatfield );
        cout << median << "\n";
    }
    return 0;
}
