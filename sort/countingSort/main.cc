#include <bits/stdc++.h>


using namespace std;

vector <int> countingSort(vector <int> arr) {
    vector<int> result(100);
    vector<int> main_res;
    int count;
    for (int range = 0; range < 100; range++) {
        count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (range == arr[i]) {
                count++;
            }
        }
        result[range] = count;
    }
    for (int i = 0; i < result.size(); i++) {
        if (result[i] > 0) {
            for (int j = 0; j < result[i]; j++){
                main_res.push_back(i);
            }
        }
    }
    return main_res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <int> result = countingSort(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}

