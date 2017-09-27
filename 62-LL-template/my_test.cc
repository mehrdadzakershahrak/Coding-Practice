#include <iostream>
#include "my_list.h"
#include <climits>

using namespace std;
int findMax(const List<int> & list) {
    int max = INT_MIN;
    for (int x : list) {
        if (x > max) {
            max = x;
        }
    }
    return max;
}

int main() {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    for (auto itr = list.begin(); itr != list.end(); ++itr) {
        cout << *itr << '\n';
    }
    return 0;
}
