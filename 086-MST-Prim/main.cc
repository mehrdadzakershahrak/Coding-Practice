#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define MAXN 3001
int n, m , s;
unordered_set<int> adj[MAXN];
int weight[MAXN][MAXN];

int prim () {
    int total = 0;
    unordered_set<int> treeNodes, remainingNodes;
    treeNodes.insert(s);
    for (int i = 1; i <= n; i++) {
        if (i != s) {remainingNodes.insert(i); }
    }
    while(treeNodes.size() < n) {
        int minWeight = 1000000;
        int minU = 0;
        for (int u : remainingNodes) {
            for (int v : adj[u]) {
                if (treeNodes.find(v) != treeNodes.end()) {
                   if (weight[u][v] < minWeight) {
                    minWeight = weight[u][v];
                    minU = u;
                   } 
                }
            }
        }
        total += minWeight;
        treeNodes.insert(minU);
        remainingNodes.erase(minU);
    }
    return total;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        bool hasEdge = adj[x].find(y) != adj[x].end();
        adj[x].insert(y);
        adj[y].insert(x);
        if (hasEdge) {
            r = min(r, weight[x][y]);
        }
        weight[x][y] = r;
        weight[y][x] = r;
    }
    cin >> s;
    cout << prim() << "\n";
    return 0;
}


