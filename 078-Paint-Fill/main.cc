// Compile as C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void fillHelper(vector<vector<char>> & screen, int pr, int pc,
                char fillColor, char originalColor)
{
    if (screen[pr][pc] != originalColor) { return; }
    if (originalColor == fillColor) { return; }
    screen[pr][pc] = fillColor;
    if (pc + 1 < screen[pr].size()) { fillHelper (screen, pr, pc + 1, fillColor, originalColor); }
    if (pc - 1 >= 0) { fillHelper (screen, pr, pc - 1, fillColor, originalColor); }
    if (pr + 1 < screen.size()) { fillHelper (screen, pr + 1, pc, fillColor, originalColor); }
    if (pr - 1 >= 0) { fillHelper (screen, pr - 1, pc, fillColor, originalColor); }
}

void fill(vector<vector<char>> & screen, int pr, int pc, char fillColor) {
    char originalColor = screen[pr][pc];
    fillHelper(screen, pr, pc, fillColor, originalColor);
}

int main(int argc, char* argv[])
{
    int row, col;
    cin >> row >> col;
    cin.ignore(100, '\n');
    vector<vector<char>> screen(row, vector<char>(col, ' '));
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cin.get(screen[r][c]);
        }
        cin.ignore(1); // Ignore the \n character
    }
    int pr, pc;
    cin >> pr >> pc;
    cin.ignore(100, '\n');
    char color;
    cin.get(color);
    fill(screen, pr, pc, color);
    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            cout << screen[r][c];
        }
        cout << '\n';
    }
    return 0;
}
