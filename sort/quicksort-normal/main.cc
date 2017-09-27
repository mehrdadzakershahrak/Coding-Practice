#include <bits/stdc++.h>
using namespace std;

void quickSort(vector <int> &arr) {
    int size = arr.size();
    if (size < 2) {
        return;
    }
    
    vector<int> leftArray, rightArray;
    
    int pivot = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] <= pivot) {
            leftArray.push_back(arr[i]);
        }
        else {
            rightArray.push_back(arr[i]);
        }
    }
    quickSort(leftArray);
    quickSort(rightArray);
    
    int i = 0;
    for (auto x : leftArray) {
        arr[i++] = x;
        cout << x << ' ';
    }
    arr[i++] = pivot;
    cout << pivot << ' ';
    for (auto x : rightArray) {
        arr[i++] = x;
        cout << x << ' ';
    }
    cout << '\n';
}

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr);

    return 0;
}


