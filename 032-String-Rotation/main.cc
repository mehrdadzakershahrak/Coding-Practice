#include <stack>
#include <iostream>
#include <string>
using namespace std;


bool isSubstr(string s1, string s2) {
    // Checks if s2 is substr of s1
    return s1.find(s2) != string::npos;
}

bool isRotation(string s1, string s2) {
    return s1.size() == s2.size() && isSubstr(s1+s1, s2);
}


int main(){
  string  m, n;
  cin >> m >> n;
  cout << isRotation(m, n) << '\n';
  return 0;
}
