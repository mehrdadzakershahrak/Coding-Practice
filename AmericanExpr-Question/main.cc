#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> findMax(vector<int> & arr) {
    vector<int> max(3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] > max[i]) {
                max[i] = arr[j];
            }
        }
        vector<int>::iterator itr;
        itr = find(arr.begin(), arr.end(), max[i]);
        arr.erase(itr);
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        arr.push_back(elem);
    }
    vector<int> out = findMax(arr);
    for (int i = 0; i < 3; i++){
        cout << out[i] << " ";
    }
    cout << "\n";
    return 0;
}
