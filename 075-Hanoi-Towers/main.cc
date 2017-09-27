// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void init(stack<int> & tower, int n) {
    while (n > 0) {
        tower.push(n);
        n--;
    }
}

void print(stack<int> tower[3]) {
    for (int t = 0; t < 3; t++) {
        cout << "tower[" << t << "] = { ";
        stack<int> temp;
        while (!tower[t].empty()) {
            int x = tower[t].top();
            tower[t].pop();
            cout << x << ' ';
            temp.push(x);
        }
        cout << "}\n";
        while (!temp.empty()) {
            int x = temp.top();
            temp.pop();
            tower[t].push(x);
        }
    }
}
int moveCount = 0;

void moveTopDisk (stack<int> tower[3], int src, int dest) {
    int x = tower[src].top(); tower[src].pop();
    tower[dest].push(x);
    cout << " Moving " << x << " from " << src << " to " << dest<< '\n';
    moveCount++;
}

void moveDisks(int n, stack<int> tower[3], int src, int dest, int buffer) {
    if (n <= 0) { return; }
    moveDisks(n - 1, tower, src, buffer, dest);
    moveTopDisk(tower, src, dest);
    moveDisks(n - 1, tower, buffer, dest, src);
}

void hanoi(int n) {
    stack<int> tower[3];
    init(tower[0], n);
    moveDisks(n, tower, 0, 2, 1);
    print(tower);
    cout << "finished in " << moveCount << " moves" <<'\n';
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    hanoi(n);
    return 0;
}
