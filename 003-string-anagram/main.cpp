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
using Histogram = unordered_map<char,int>;

Histogram histogram(string input) {
    Histogram h;
    for (char c : input) {
        h[c]++;
    }
    return h;
}
int number_needed(string a, string b) {
    Histogram hist1 = histogram(a);
    Histogram hist2 = histogram(b);
    int diff = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        diff += abs(hist1[c] - hist2[c]);
    }
    return diff;
    
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}

