// Compile as C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findMagic(vector<int> & v, int begin, int end) {
    if (begin > end) { return -1; }
    int mid = (begin + end) / 2;
    if (v[mid] == mid) { return mid;}
    if (v[mid] < mid) { return findMagic(v, mid + 1, end); }
    return findMagic(v, begin, mid - 1);
}

int findMagic (vector<int> & v) {
    return findMagic(v, 0, v.size() - 1);
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout <<  findMagic(v) << '\n';
    return 0;
}
