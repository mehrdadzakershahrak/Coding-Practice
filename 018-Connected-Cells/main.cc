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
#include <unordered_set>

using namespace std;

struct Position {
    int row;
    int col;
    bool operator == (const Position& rhs) const {
        return row == rhs.row && col == rhs.col;
    }
};
namespace std
    {
    template <>
    struct hash<Position>
    {
        size_t operator()(Position const & x) const noexcept
        {
            return (
            (51 + std::hash<int>()(x.row)) * 51
            + std::hash<int>()(x.col));    
        }
    };
}
struct Grid {
    vector< vector<int> > grid;
    int n;
    int m;
    
    bool isValid(Position p) {
        return (p.row >= 0) && (p.row < n) && (p.col >= 0) && (p.col < m);
    }
    
    vector<Position> getValidNeighbors(int r, int c) {
        vector<Position> neighbors = {
            {r - 1, c - 1},
            {r, c - 1},
            {r - 1, c},
            {r + 1, c},
            {r, c + 1},
            {r + 1, c + 1},
            {r - 1, c + 1},
            {r + 1, c - 1},    
        };
        vector<Position> validNeighbors;
        for (auto p : neighbors) {
            if (isValid(p)) {
                validNeighbors.push_back(p);
            }
        }
        return validNeighbors;
    }
        
    int reachableFrom(int r, int c,unordered_map<Position, int>& memo) {
        if (grid[r][c] == 0) {
            return 0;
        }
        Position pos{r, c};
        if (memo.find(pos) != memo.end()) {
            return memo[pos];
        }
        unordered_set<Position> visited;
        list<Position> que;
        que.push_back({r, c});
        while (!que.empty()) {
            Position next = que.front();
            que.pop_front();
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                auto vn = getValidNeighbors(next.row, next.col);
                for (auto p :vn) {
                    if (grid[p.row][p.col] == 1) {
                        que.push_back(p);
                    }
                }
            }
        }
        for (auto x : visited) {
            memo[x] = visited.size();
        }
        return visited.size();
    }
    int getBiggestRegion() {
        unordered_map<Position, int> memo; 
        int maxR = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                maxR = max(maxR,reachableFrom(r, c, memo));
            }
        }
        return maxR;
    }
};


int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    Grid g{grid,n,m};
    cout << g.getBiggestRegion() << endl;
    return 0;
}

