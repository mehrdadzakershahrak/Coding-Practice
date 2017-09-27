// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int flip2Win(int x) {
    int before = 0, after = 0, longest = 0;
    int i = 31;
    while (x > 0) {
        int b = x % 2;
        x = x / 2;
        if (b) {
            before++;
        } else {
            b = x % 2;
            x = x / 2;
            after = 0;
            while (x > 0 && b) {
                b = x % 2;
                x = x / 2;
                after++;
            }
            if (after + before + 1 > longest) {
                longest = after + before + 1;
            }
            before = after;
        }
    }
    return longest;
}

int main(int argc, char* argv[])
{
    int x;
    cin >> x;
    cout << flip2Win(x) << '\n';
    return 0;
}
