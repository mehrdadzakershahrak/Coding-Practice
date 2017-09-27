// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

int main(int argc, char* argv[])
{
    double x;
    cin >> x;
    bitset<32> b;
    for (int i = 31; i >= 0 && x > 0; i--) {
        x = x * 2;
        if (x >= 1) {
            b[i] = true;
            x -= 1;
        }
    }
    if (x > 0) {
        cout << "ERROR" << '\n';
    }
    else {
        cout << "0." << b << '\n';
    }
    return 0;
}
