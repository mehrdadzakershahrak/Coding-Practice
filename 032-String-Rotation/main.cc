#include <stack>
#include <iostream>
#include <string>
using namespace std;


bool isSubstr(string s1, string s2) {
    // Checks if s2 is substr of s1
    int len_isSub = s2.size();
    int count = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[count]) {
            count++;
        }
        if (count == len_isSub) {
            return true;
        }
    }
    return false;
}

bool isRotation(string s1, string s2) {
    int len = s1.size();
    if (len = s2.size() && len > 0) {
    string combined = s1 + s1;
    return isSubstr(combined, s2);
    }
    return false;
}


int main(){
  string  m, n;
  cin >> m >> n;
  cout << isRotation(m, n) << '\n';
  return 0;
}
