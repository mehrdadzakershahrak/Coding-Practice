#include <bits/stdc++.h>

using namespace std;

void miniMax(vector<int>& a) {
    long int sum = 0;
    for (int i : a) {
        cout << "i = " << i << "a[i] =" << a[i] << '\n';
    }
}
int main() {
    vector<int> arr(5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
       cin >> arr[arr_i];
    }
    miniMax(arr);
    return 0;
}

