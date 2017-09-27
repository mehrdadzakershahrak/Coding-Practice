#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector<int> & A, int lo, int hi) {
    int pivot = A[hi];
    int i = lo-1;
    for (int j = lo; j <= hi-1; j++) {
        if (A[j] < pivot) {
            i = i+1;
            swap(A[i], A[j]);
        }
    }
    if (A[hi] < A[i+1]) { swap(A[i+1], A[hi]); }
    for (int j = 0; j < A.size(); j++) {
        cout << A[j] << " ";
    }
    cout << "\n";
    return i+1;
}

void quickSort(vector<int> & arr, int lo, int hi) {
    if (lo < hi) {
        auto p = partition(arr, lo, hi);
        quickSort(arr, lo, p-1);
        quickSort(arr, p+1, hi);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, arr.size()-1);
    return 0;
}


