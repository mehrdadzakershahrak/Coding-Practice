// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

void sortedMerge (vector<int> & a, vector<int> & b, int realSizeA) {
    if (a.size() != b.size() + realSizeA) {
        throw runtime_error("wrong size!");
    }

    int i = a.size() - 1;
    int aIdx = realSizeA - 1;
    int bIdx = b.size() - 1;
    while (aIdx >= 0 && bIdx >= 0) {
        if (a[aIdx] > b[bIdx]) {
            a[i] = a[aIdx];
            aIdx--;
        }
        else {
            a[i] = b[bIdx];
            bIdx--;
        }
        i--;
    }
    while (bIdx >= 0) {
        a[i] = b[bIdx];
        bIdx--;
    }
}

int main(int argc, char* argv[])
{
    vector<int> A{2, 3, 4, 9, 18, 30, 57, 88, 96,0,0,0,
        0, 0, 0, 0, 0, 0, 0};
    vector<int> B {5, 7, 11, 19, 35, 65, 76, 84, 92, 100};
    sortedMerge(A, B, 9);
    for (int a : A) {
        cout << a << " ";
    }
    cout << "\n";
    return 0;
}
