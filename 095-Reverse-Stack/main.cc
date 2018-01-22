// Compile as C++11
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
stack<int> s;

int reverse_insert(int x) {
    if (s.size() == 0) { s.push(x); }
    else {
        int elem = s.top(); s.pop();
        reverse_insert(x);
        s.push(elem);
    }
}

int reverse_helper() {
    if (s.size() > 0)
    {
        int x = s.top(); s.pop();
        reverse_helper();
        reverse_insert(x);
    }
}

int main() {
    stack<int> mystack;
    mystack.push(10);
    mystack.push(9);
    mystack.push(8);
    mystack.push(7);
    mystack.push(6);
    mystack.push(5);

    reverse_helper();
    vector<int> output;

    while (!mystack.empty()) {
        output.push_back(mystack.top());
        mystack.pop();
    }

    for (int e : output) {
        cout << e << " ";
    }
    cout << "\n";
    return 0;
}
