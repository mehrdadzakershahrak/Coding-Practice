// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class Graph {
    private:
        unordered_map<int,list<int>> adj_list;
        int n;
        int edgeCount;
    public:
        Graph(int n) {
            this->n = n;
            this->edgeCount = 0;
        }
        void addEdge (int from, int to) {
            adj_list[from].push_back(to);
            edgeCount++;
        }
        list<int> neighbors (int node) {
            list<int> copy(adj_list[node].begin(), adj_list[node].end());
            return copy;
        }
        int getEdgeCount() {
            return edgeCount;
        }
        bool hasEdge(int from, int to) {
            for (auto x : adj_list[from]) {
                if (x == to) {
                    return true;
                }
            }
            return false;
        }
};

bool hasRouteBFS(Graph & g, int u, int v) {
    list<int> Que;
    unordered_map<int,bool> visited;

    visited[u] = true;
    Que.push_back(u);

    while (!Que.empty()) {
        int c = Que.front();
        Que.pop_front();
        if (c == v) {
            return true;
        }
        for (int n : g.neighbors(c)) {
            if (!visited[n]) {
                visited[n] = true;
                Que.push_back(n);
            }
        }
    }
    return false;
}

bool hasRouteDFSHelper(Graph & g, int u, int v, unordered_map<int,bool> & visited) {
    visited[u] = true;
    for (int n : g.neighbors(u)) {
        if (n == v) {
            return true;
        }
        if (!visited[n]) {
            bool route = hasRouteDFSHelper(g, n, v, visited);
            if (route) {
                return true;
            }
        }
    }
    return false;
}

bool hasRouteDFS(Graph & g, int u, int v) {
    unordered_map<int,bool> visited;
    return hasRouteDFSHelper(g, u, v, visited);
}

int main(int argc, char* argv[])
{
    int n,e, u, v;
    cin >> n >> e >> u >> v;
    Graph g(n);
    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from >> to;
        g.addEdge(from, to);
    }
    cout << hasRouteDFS(g, u, v) << '\n';
    return 0;
}
