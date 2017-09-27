// Compile as C++11
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void sortStack(stack<int> & s) {
    stack<int> zapas;
    while(!s.empty()) {
        int x = s.top();
        s.pop();
        int count = 0;
        while (!zapas.empty() && x < zapas.top()) {
            s.push(zapas.top());
            zapas.pop();
        }
        zapas.push(x);
    }
    while (!zapas.empty()) {
        s.push(zapas.top());
        zapas.pop();
    }
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }
    sortStack(s);
    while (!s.empty()) {
        cout << s.top() << '\n';
        s.pop();
    }
    return 0;
}
