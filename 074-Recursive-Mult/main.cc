// Compile as C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned long multiply(unsigned long x, unsigned long y) {
    if (y == 0) { return 0;}
    if (y == 1) { return x;}
    int lsb = (y & 1);
    return (multiply(x, y >> 1) << 1) + (lsb ? x : 0);
}

int main(int argc, char* argv[])
{
    unsigned long x, y;
    cin >> x >> y;
    cout <<"    x * y = " << multiply(x, y) << '\n';
    return 0;
}
