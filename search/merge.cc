// Compile as C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;


template <typename T>
void merge(vector<T>& arr, vector<T>& helper, int low, int middle, int high) {
    for (int i = low; i <= high; i++) {
        helper[i] = arr[i];
    }
    int left = low;
    int right = middle+1;
    int tmp = low;

    while (left <= middle && right <= high) {
        if (helper[left] <= helper[right]) {
            arr[tmp] = helper[left];
            left++;
        }
        else {
            arr[tmp] = helper[right];
            right++;
        }
        tmp++;
    }
    int rest = middle - left;
    for (int i = 0; i <= rest; i++) {
        arr[tmp+i] = helper[left+i];
    }
}

template <typename T>
void mergeSort(vector<T>& arr, vector<T>& helper, int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;
        mergeSort(arr, helper, low, middle);
        mergeSort(arr, helper, middle+1, high);
        merge(arr, helper, low, middle, high);
    }
}

template <typename T>
void mergeSort(vector<T>& arr) {
    vector<T> helper(arr.size());
    mergeSort(arr, helper, 0, arr.size() - 1);
}

template <typename T>
void printArr(vector<T>& arr) {
    for (auto e : arr) {
        cout << e << " ";
    }
    cout << "\n";
}

int main(int argc, char* argv[])
{
    vector<int> a{11, 5, 7, 19, 1, 29};
    mergeSort(a);
    printArr(a);
    return 0;
}
