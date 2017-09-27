// Compile as C++11
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

unsigned int pairwiseSwap(unsigned int x)
{
    unsigned int oddBits = (x & 0xAAAAAAAA);
    oddBits >>= 1;
    unsigned int evenBits = (x & 0x55555555);
    evenBits <<= 1;
    return evenBits | oddBits;
}

int main(int argc, char* argv[])
{
    unsigned int x;
    cin >> x;
    auto y = pairwiseSwap(x);
    cout << "x = " << bitset<32>(x) << " " << x << '\n';
    cout << "y = " << bitset<32>(y) << " " << y << '\n';
    return 0;
}
