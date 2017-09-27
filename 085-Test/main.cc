#include <iostream>
#include <vector>
#include "measure_time.h"
#include <algorithm>

using namespace std;

// Hint: this code is to gain deeper understanding of function objects and
// Lambda expressions.

struct TestSort {
    int n;
    void operator()() {
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            a[i] = n - i;
        }
        sort(a.begin(), a.end());
    }
};

// void testSort(int N) {
//     vector<int> a(N);
//     for (int i = 0; i < N; i++){
//         a[i] = N - i;
//     }
//     sort(a.begin(), a.end());
// }

int main() {
    int n = 1000;
    // auto D = MeasureRuntime([&](){
    //     testSort(n);
    // });
    TestSort t{n};
    auto D = MeasureRuntime(t);
    PrintDuration(cout, D);
    cout << "\n";
    return 0;
}
