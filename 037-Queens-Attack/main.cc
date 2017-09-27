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

struct position {
    int row;
    int col;
    bool operator == (const position& rhs) const {
        return row == rhs.row && col == rhs.col;
    }
};
namespace std
{
    template <>
    struct hash<position>
    {
        size_t operator()(position const & x) const noexcept
        {
            return (
            (51 + std::hash<int>()(x.row)) * 51
            + std::hash<int>()(x.col));
        }
    };
}

int move (int size, position p, int rowDelta, int colDelta, unordered_set<position>& obs) {
    int count = 0;
    while (true) {
        p = {p.row + rowDelta, p.col + colDelta};
        if (obs.find(p) != obs.end()) {
            break;
        }        
        if (p.row < 1 || p.row > size || p.col < 1 || p.col > size) {
            break;
        }
        count++;
    }
    return count;
}

int queen(int size, int rQueen, int cQueen, vector<position> obs) {
    position start = {rQueen, cQueen};
    unordered_set<position> obstacles(obs.begin(), obs.end());
    return move(size, start, 0, +1, obstacles) + 
           move(size, start, 0, -1, obstacles) +
           move(size, start, +1, 0, obstacles) +
           move(size, start, -1, 0, obstacles) +
           move(size, start, +1, +1, obstacles) +
           move(size, start, +1, -1, obstacles) +
           move(size, start, -1, +1, obstacles) +        
           move(size, start, -1, -1, obstacles);       
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    int rQueen;
    int cQueen;
    vector<position> obstacles(k);
    
    cin >> rQueen >> cQueen;
    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        cin >> rObstacle >> cObstacle;
        obstacles[a0].row = rObstacle;
        obstacles[a0].col = cObstacle;
    }
    cout << queen(n,rQueen, cQueen, obstacles) << '\n';
    return 0;
}

