// The desription is available at:
// https://www.hackerrank.com/challenges/hackerland-radio-transmitters
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

int houseCount (vector<int> & city, int i, int range, int last_cover) {
    int count = 0;
    int position = i + 1;
    while (position < city.size() && city[position] - city[i] <= range) {
        count++;
        ++position;
    }
    position = i;
    while (position > last_cover && city[i] - city[position] <= range) {
        count++;
        position--;
    }
    return count;
}

int antenna(vector<int> & city, int range) {
    int i = 0;
    int counter = 0;
    int last_covered = -1;
    while (i < city.size()) {
        int max = 0, max_index = -1;
        for (int j = i; j < city.size() && city[j] - city[i] <= range; j++) {
            int covered = houseCount(city, j, range, last_covered);
            if (max < covered) {
                max = covered;
                max_index = j;
            }
        }
        //cerr << "max = " << max << " max_index: " << max_index << '\n';
        while (i < city.size() && abs(city[i] - city[max_index]) <= range) {
            i++;
        }
        counter++;
        last_covered = i - 1;
    }
    return counter; 
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    set<int> x;
    for(int x_i = 0;x_i < n;x_i++){
       int inp;
       cin >> inp;
       x.insert(inp);
    }
    vector<int> city(x.begin(), x.end());
    cout << antenna(city, k) << '\n';
    return 0;
}

