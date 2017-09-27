#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string nextLex(string & inp) {
    const int size = inp.size();
    int i = size;
    while(i-1 >= 0) {
        if (inp[i] > inp[i-1]){
            break;
        }
        i--;
    }
    if (i == 0) { return "no answer";}
    int minIdx = i;
    char minC = inp[i];
    for (int j = i; j < size; j++) {
        if (inp[j] < minC && inp[j] > inp[i-1]) {
            minC = inp[j];
            minIdx = j;
        }
    }
    swap(inp[i-1], inp[minIdx]);
    sort(inp.begin()+i, inp.end());
    return inp;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string inp;
        cin >> inp;
        cout << nextLex(inp) << "\n";
    }
    return 0;
}


