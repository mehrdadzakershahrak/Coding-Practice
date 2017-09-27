// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int insert(int n, int m, int i, int j) {
    int mask = 1 <<  (j - i + 1);
    mask = (mask - 1) << i;
    mask = ~ mask;
    n = n & mask;
    n = n | (m << i);
    return n;
}

int main(int argc, char* argv[])
{
    int n, m, i, j;
    cin >> n >> m >> i >> j;
    cout << bitset<32>(insert(n, m, i, j)) << '\n';
    return 0;
}
