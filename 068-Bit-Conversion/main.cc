// Compile as C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int bitDiff(unsigned int a, unsigned int b) {

    int count = 0;
    for (unsigned int c = a ^ b; c > 0;c = c & (c - 1)) {
        // c & (c - 1) only counts the 1s in the whole bitset
        // Therefore, the iteration will be done depending on
        // the number of 1s in the bitset. Fastest Solution!
        count++;
    }
    // while (result != 0) {
    //     if ((result & 1) == 1) { count++;        }
    //     result >>= 1;
    // }
    return count;
}

int main(int argc, char* argv[])
{
    unsigned int a, b;
    cin >> a >> b;
    cout << "a = " << a << " " << "b = " << b <<'\n';
    cout << bitDiff(a, b) << '\n';
    return 0;
}
