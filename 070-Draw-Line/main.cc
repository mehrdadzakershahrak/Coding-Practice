// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
using byte = unsigned char;

class Screen {
public:
    Screen(int w, int h) {
        this->s = new byte[h * (w / 8)];
        this->w = w;
        this->h = h;
    }
    ~Screen() {
    delete[] s;
    }
    void print() {
        for (int y = 0; y < h; y++) {
            cout << setfill(' ') << setw(3) << y << ": ";
            for (int x = 0; x < w; x++) {
                cout << (pixel(x, y) ? '.' : ' ');
            }
            cout << '\n';
        }
    }
    void drawline(int x1, int x2, int y) {
        if (x1 > x2) { swap(x1, x2); }
        int byteX1 = bytePos(x1, y);
        int byteX2 = bytePos(x2, y);
        int bitX1 = bitPos(x1);
        int bitX2 = bitPos(x2);
        if (byteX1 == byteX2) {
            byte mask1 = (1 << (bitX1 + 1)) - 1;
            byte mask2 = ~((1 << bitX2) - 1);
            byte mask = mask1 & mask2;
            s[byteX1] |= mask;
        } else {
            byte mask1 = (1 << (bitX1 + 1)) - 1;
            s[byteX1] |= mask1;
            for (int i = x1 + bitX1 + 1; i <  x2 - (7 - bitX2 + 1); i++) {
                s[bytePos(i, y)] = 255;
            }
            byte mask2 = ~((1 << bitX2) - 1);
            s[byteX2] |= mask2;
        }
    }

private:
    byte * s;
    int w, h;

    int bytePos(int x, int y) {
        return y * w / 8 + x / 8;
    }
    int bitPos(int x) {
        return 7 - (x % 8);
    }
    bool pixel (int x, int y) {
        int B = bytePos(x, y);
        int b = bitPos(x);
        byte n = s[B];
        byte mask = (1 << b);
        return (n & mask) > 0;
    }
};

int main(int argc, char* argv[])
{
    int width, height;
    cin >> width >> height;
    Screen s(width, height);
    int x1, x2, y;
    cin >> x1 >> x2 >> y;
    s.drawline(x1,x2, y);
    s.print();
    return 0;
}
