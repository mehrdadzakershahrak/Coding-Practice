#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> zapas, q;   
        void push(int x) {
            if (q.empty() && zapas.empty()) {
                q.push(x);
            }
            else 
                zapas.push(x);
        }
        void pop() {
            if (q.empty()) {
                while (!zapas.empty()) {
                    q.push(zapas.top());
                    zapas.pop();
                }
            }
            q.pop();
        }

        int front() {
            if (q.empty()) {
                while (!zapas.empty()) {
                    q.push(zapas.top());
                    zapas.pop();
                }
            }
            return q.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
