#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

class Graph {
    private:
        int n;
        unordered_map<int, vector<int>> adj;
    public:
        Graph(int n_): n{n_} { }
    
        void add_edge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        bool hasEdge(int u, int v) {
            auto& a = adj[u];
            return find(a.begin(), a.end(), v)!= a.end();
        }
    
        vector<int> shortest_reach(int start) {
            vector<int> shortest(n, -1);
            unordered_set<int> visited;
            list<int> Q;
            Q.push_back(start);
            shortest[start] = 0;
            while(!Q.empty()) {
                int node = Q.front();
                Q.pop_front();
                if (visited.find(node) == visited.end()) {
                    visited.insert(node);
                    for (int x : adj[node]) {
                        Q.push_back(x);
                        if (shortest[x] == -1) {
                          shortest[x]  =  shortest[node] + 6;   
                        }
                    }
                }
            }
            return shortest;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}

