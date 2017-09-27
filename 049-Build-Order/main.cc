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
        int nodeCount() {return n;}
        int outDegree (int node) {
            return adj_list[node].size();
        }
};

int findLastNode(int start, Graph & g, unordered_map<int,bool> & visited, unordered_map<int, bool> & selected) {
    visited[start] = true;
    bool allVisitedorSelected = true;
    for (int n : g.neighbors(start)) {
        if (!visited[n]) {
            allVisitedorSelected = false;
            break;
        }
    }
    if (allVisitedorSelected && !g.neighbors(start).empty()) {
        cout << "Found a cycle" << '\n';
        return -1;
    }
    for (int n : g.neighbors(start)) {
        if (!selected[n]) {
            return findLastNode(n, g, visited, selected);
        }
    }
    return start;
}

vector<int> buildOrder(Graph & g) {
    vector<int> order(g.nodeCount());
    unordered_map<int, bool> selected;
    int index = g.nodeCount() - 1;
    while (index >= 0) {
        int chosen = -1;
        for (int i = 1; i <= g.nodeCount(); i++) {
            if (!selected[i]) {
                chosen = i;
                break;
            }
        }
        if (chosen == -1) {
            cout << "No node to choose" << '\n';
            return {};
        }
        unordered_map<int, bool> visited;
        int yechizi = findLastNode(chosen, g, visited, selected);
        if (yechizi == -1) {
            return {};
        }
        order[index] = yechizi;
        index--;
        selected[yechizi] = true;
    }
    return order;
}

int main(int argc, char* argv[])
{
    int n,e;
    cin >> n >> e;
    Graph g(n);
    for (int i = 0; i < e; i++) {
        int from, to;
        cin >> from >> to;
        g.addEdge(from, to);
    }
    auto bo = buildOrder(g);
    for (auto x : bo) { cout << x << ' ';}
    cout << '\n';
    return 0;
}
