// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
using Set = set<int>;

// using DP
vector<Set> powerSetDP(Set::iterator begin, Set::iterator end) {
    if (begin == end) {
        return { {} };
    }
    int e = * begin;
    begin++;
    auto ps = powerSetDP(begin, end);
    int size = ps.size();
    for (int i = 0; i < size; i++) {
        Set subset(ps[i]);
        subset.insert(e);
        ps.push_back(subset);
    }
    return ps;
}

Set subSet(Set & s, long x) {
    Set sub;
    auto itr = s.begin();
    while (x > 0) {
        int bit = (x & 1);
        x >>= 1;
        if (bit) {
            sub.insert(*itr);
        }
        itr++;
    }
    return sub;
}

vector<Set> powerSetBM(Set & s) {
    vector<Set> ps;
    long size = (1LL << s.size());
    for (long i = 0; i < size; i++) {
        ps.push_back(subSet(s, i));
    }
    return ps;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    Set s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    auto ps = powerSetDP(s.begin(), s.end());
    //auto ps = powerSetBM(s);
    for (auto& subset : ps) {
        int count = 0;
        cout << "{";
        for (auto x : subset) {
            if (count > 0) { cout << ", ";}
            cout << x;
            count++;
        }
        cout << "}\n";
    }
    return 0;
}
