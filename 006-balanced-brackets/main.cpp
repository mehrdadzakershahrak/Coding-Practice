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
bool is_opening(char c) {
    switch(c) {
        case '{':
        case '(':
        case '[':
            return true;
        default:
            return false;
    }
}

bool is_matched(char c1, char c2) {
    if (c1 == '{' && c2 == '}') 
        return true;
    if (c1 == '[' && c2 == ']') 
        return true;
    if (c1 == '(' && c2 == ')') 
        return true;
    return false;
}

bool is_balanced(string expression) {
    stack<char> mystack;
    for (auto s: expression) {
       if (is_opening(s)) {
           mystack.push(s);
       }
       else {
           if (mystack.empty()) {
               return false;
           }
           if (is_matched(mystack.top(), s)) {
               mystack.pop();
           }
           else {
               break;
          }
       }
    } 
    return mystack.empty();
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
