#include <map>
#include <set>
#include <list>
#include <cctype>
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

bool isPalindrome(string str) {
   vector<bool> map(26, false);
   for (char c : str) {
       c = tolower(c);
       if (isalpha(c)) {
           int key = c - 'a';
           map[key] = !map[key]; 
       }
   }
   int countTrue = 0;
   for (bool b : map) {
       if (b) {
        countTrue++;
       }
   }
   return countTrue <= 1;

}

int main(){
    char buf[256];
    cin.getline(buf, 256);
    string str(buf);
    cout << isPalindrome(str) << endl;
    return 0;
}

