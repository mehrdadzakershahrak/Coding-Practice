#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


void urlify(string& str, int len) {
    int extraSpace = str.size() - len;
    int j = str.size() - 1;
    for (int i = len - 1; i >= 0; i--) {
        if(str[i] != ' ') {
            str[j--] = str[i];
        }
        else {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
    }
}

int main(){
    char input[256];
    cin.getline(input,256);
    string str(input);
    int count = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            break;
        }
        count++;
    }
    int real_length = str.size() - count;
    urlify(str, real_length);
    cout << str << '\n';
    return 0;
}

