// The description is available at : 
// https://www.hackerrank.com/challenges/knightl-on-chessboard/submissions/code/48117799
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
#include <utility>

using namespace std;

using Cell = pair<int, int>;

Cell move(Cell start, int deltaX, int deltaY) {
    return make_pair(start.first + deltaX, start.second + deltaY);
}

bool isValid(Cell cell, int n) {
    return (cell.first >= 0 && cell.first < n && cell.second >= 0 && cell.second < n);
}

vector<Cell> validDestinations(Cell start, int a, int b, int n) {
    vector<Cell> valid;
    Cell c1 = move(start, +a, +b); if (isValid(c1, n)) { valid.push_back(c1);}
    Cell c2 = move(start, +a, -b); if (isValid(c2, n)) { valid.push_back(c2);}
    Cell c3 = move(start, -a, +b); if (isValid(c3, n)) { valid.push_back(c3);}
    Cell c4 = move(start, -a, -b); if (isValid(c4, n)) { valid.push_back(c4);}
    Cell c5 = move(start, +b, +a); if (isValid(c5, n)) { valid.push_back(c5);}
    Cell c6 = move(start, +b, -a); if (isValid(c6, n)) { valid.push_back(c6);}
    Cell c7 = move(start, -b, +a); if (isValid(c7, n)) { valid.push_back(c7);}
    Cell c8 = move(start, -b, -a); if (isValid(c8, n)) { valid.push_back(c8);}
    return valid;
}

string cell2String( Cell cell) { return to_string(cell.first) + "," + to_string(cell.second);}

int knightL(int a, int b, int n) {
    unordered_map<string, bool> visited;
    unordered_map<string, int> pathSize;
    list<Cell> Que;
    Cell start = {0, 0};
    Cell target = {n - 1, n - 1};
    Que.push_back(start);
    visited[cell2String(start)] = true;
    pathSize[cell2String(start)] = 0;
    while (!Que.empty()) {
        Cell c = Que.front(); Que.pop_front();
        string cStr = cell2String(c);
        if (c == target) {
            return pathSize[cell2String(c)];
        }
        for (auto& next : validDestinations(c, a, b, n)) {
            string nextStr = cell2String(next);
            if (!visited[nextStr]) {
                Que.push_back(next);
                visited[nextStr] = true;
                pathSize[nextStr] = pathSize[cStr] + 1;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    for (int a = 1; a < n; a++) {
        for (int b = 1; b < n; b++) {
            cout << knightL(a, b, n) << ' ' ;
        }
        cout << '\n';
    }
    return 0;
}


