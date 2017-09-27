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
using Hist = unordered_map<string, int>;
Hist histogram(vector<string> input) {
    Hist h;
    for (auto s : input) {
        h[s]++;
    }
    return h;
}


bool ransom_note(vector<string> magazine, vector<string> ransom) {
    Hist h1 = histogram(magazine);
    Hist h2 = histogram(ransom);
    for ( auto it = h2.begin(); it != h2.end(); ++it ) {
        auto word = it->first;
        auto count = it->second;
        if (h1[word] < count) {
            return false;
        }
    }
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

