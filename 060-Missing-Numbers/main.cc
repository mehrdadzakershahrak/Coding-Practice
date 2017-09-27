// Numeros, the Artist, had two lists A and B, such that B was a permutation of A. Numeros was
// very proud of these lists. Unfortunately, while transporting them from one exhibition
// to another, some numbers were left out of A. Can you find the missing numbers?
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, int> initMap(int limit, unordered_map<int, int> & map) {
    
    for (int i = 0; i < limit; i++) {
        int list;
        cin >> list;
        map[list]++;
    }
    return map;
}

unordered_map<int, int> updateMap(int limit, unordered_map<int, int> & map) {

    for (int i = 0; i < limit; i++) {
        int list;
        cin >> list;
        map[list]--;
    }
    return map;
}

vector<int> missing(unordered_map<int, int> & a) {
    vector<int> result;
    for (auto it = a.begin(); it != a.end(); it++) {
       if (it->second != 0) {
           result.push_back(it->first);
       }
    }
    sort(result.begin(), result.end());
    return result;
}

void printVector(vector<int> & a) {
    for (auto x : a) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int n;
    unordered_map<int, int> listA;
    cin >> n;
    listA = initMap(n,listA);
    int m;
    cin >> m;
    listA = updateMap(m,listA);
    vector<int> ans = missing(listA);
   //cout << "answer size is " << ans.size() << '\n';
    printVector(ans);
    return 0;
}


