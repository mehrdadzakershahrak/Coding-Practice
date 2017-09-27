// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

const int N = 9;

using namespace std;
using Position = bitset<N*N>;


int bitPosition(int row, int col) {
    return (row - 1) * N + (col - 1);
}


bool hasQueen(const Position & p, int row, int col) {
    return p[bitPosition(row, col)];
}

void printPosition(Position & p) {
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cout << (hasQueen(p, r, c) ? " Q" : " .");
        }
        cout << "\n";
    }
}

Position addQueen(const Position & p, int row, int col) {
    Position q = p;
    q[bitPosition(row, col)] = true;
    return q;
}


bool hasQueen(const Position & p, int row, int col, int dr, int dc) {
    row += dr;
    col += dc;
    while (row > 0 && row < N + 1 && col > 0 && col < N + 1) {
        if (hasQueen(p, row, col)) { return true; }
        row += dr;
        col += dc;
    }
    return false;
}

bool isValid(const Position & p) {

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            if (hasQueen(p,r,c)) {
                if (hasQueen(p, r, c, 0, +1)) { return false;}
                if (hasQueen(p, r, c, 0, -1)) { return false;}
                if (hasQueen(p, r, c, -1, 0)) { return false;}
                if (hasQueen(p, r, c, +1, 0)) { return false;}
                if (hasQueen(p, r, c, -1, +1)) { return false;}
                if (hasQueen(p, r, c, +1, -1)) { return false;}
                if (hasQueen(p, r, c, +1, +1)) { return false;}
                if (hasQueen(p, r, c, -1, -1)) { return false;}
            }
        }
    }
    return true;
}

int CC = 0;

void queenHelper(vector<Position> & valid, int row, Position & start) {
    CC++;
    if(row == 0) {
        if (isValid(start)) {valid.push_back(start); }
        return;
    }
    for (int c = 1; c <= N; c++) {
        Position q = addQueen(start, row, c);
        if (isValid(q)) {
            queenHelper(valid,row - 1, q);
        }
    }
}

vector<Position> queenPosition() {
    vector<Position> pos;
    Position start = 0;
    queenHelper(pos,N, start);
    return pos;
}

int main(int argc, char* argv[])
{
    auto queens = queenPosition();
    cout << "it has " << queens.size() << " solutions" << "\n" ;
    cout << "it has been called " << CC << " times" << "\n";
    return 0;
}
