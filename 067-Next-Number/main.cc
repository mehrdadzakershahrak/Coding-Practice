// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

void bruteForce(int x) {
    int i = x + 1;
    int bitcount = bitset<32>(x).count();
    while (i > 0) {
        bitset<32> b(i);
        if (b.count() == bitcount) {
            break;
        }
        i++;
    }
    cout << "next = " << i << " = "<< bitset<32>(i) << '\n';
    i = x - 1;
    while (i > 0) {
        bitset<32> b(i);
        if (b.count() == bitcount) {
            break;
        }
        i--;
    }
    cout << "previous = " << i  << " = " << bitset<32>(i) << '\n';
}

int clearBit(int x, int i) {
    int mask = ~(1 << i);
    return x & mask;
}

int setBit( int x, int i) {
    int mask = (1 << i);
    return x | mask;
}

void nextBit (int x) {
    int n = x;
    int i = 0;
    int right = 0;
    while (n > 0 && (n & 1) == 0) {
        n >>= 1;
        i++;
    }
    int zeros = i + 1;
    while (n > 0 && (n & 1) == 1) {
        n >>= 1;
        right += (1 << i);
        i++;
    }
    if ((n & 1) == 1) {
        cout << "There is no possibility" << '\n';
        return;
    }
    n = setBit(x, i) - right;
    int next = n + (right >> zeros);
    cout << "next = " << next << " = " << bitset<32>(next) << '\n';
}

void prevBit(int x) {
    int n = x;
    int i = 0;
    int right = 0;
    while (n > 0 && (n & 1) == 1) {
        n >>= 1;
        right += (1 << i);
        i++;
    }
    int ones = i;
    while (n > 0 && (n & 1) == 0) {
        n >>= 1;
        i++;
    }
    if ((n & 1) == 0) {
        cout << "There is no possibility" << '\n';
        return;
    }
    n = clearBit(x, i) - right;
    right = right + (1 << ones);
    int prev = n + (right << (i - ones - 1));
    cout << "prev = " << prev << " = " << bitset<32>(prev) << '\n';
}

int main(int argc, char* argv[])
{
    int x;
    cin >> x;
    cout << "x = " << bitset<32>(x) << '\n';
    nextBit(x);
    prevBit(x);
    cout << '\n';
    //bruteForce(x);
    return 0;
}
