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
using MinHeap = priority_queue<int, vector<int>, greater<int>>;

void genList(int a, int b, int n) {
    MinHeap h;
    h.push(0);
    int count = 0;
    int last = -1;
    while (count < n) {
        int candidate = h.top();
        h.pop();
        if (last != candidate) {
            cout << candidate << '\n';
            count++;
            last = candidate;
            h.push(candidate + a);
            h.push(candidate + b);
        }
    }
}



int main(){
     int a,b,n;
     cin >> a;
     cin >> b;
     cin >> n;
     genList(a,b,n);
      
     return 0;
 }
