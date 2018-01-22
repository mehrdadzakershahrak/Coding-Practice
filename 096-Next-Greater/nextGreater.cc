#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void printStack(stack<int> s){
    cout << "stack = ";
    while(!s.empty()) {
        int x = s.top(); s.pop();
        cout << x << " ";
    }
    cout << "\n";
}

void nextGreater(vector<int> arr)
{
    stack<int> s;
    s.push(arr[0]);
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        int next = arr[i];
        cout << "next = " << next << " ";
        printStack(s);
        if (!s.empty()) {
            int element = s.top();
            s.pop();
            while (element < next) {
                cout << element << " --> " << next << "\n";
                if (s.empty() == true)
                   break;
                element = s.top();
                s.pop();
            }
            if (element > next)  { s.push(element); }
        }
        s.push(next);
    }
    
    while (!s.empty())
    {
        cout << s.top() << " --> " << -1 << "\n";
        s.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    nextGreater(arr);
    return 0;
}
