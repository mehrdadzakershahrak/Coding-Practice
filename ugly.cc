//Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
// Compile as C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxDiv(int n, int m) {
    while (n%m == 0) {
        n = n / m;
    }
    return n;
}


bool isUgly(int n) {
    n = maxDiv(n, 2);
    n = maxDiv(n, 3);
    n = maxDiv(n, 5);
    return (n == 1) ? true : false;
}

int getUgly(int n) {
    int i = 1;
    int count = 1;

    while (n > count) {
        i++;
        if (isUgly(i)) {
            count++;
        }
    }
    return i;
}


int main(int argc, char* argv[])
{
    // Read input
    int n;
    cin >> n;
    cout << n << "th Ugly number is: " << getUgly(n) << "\n";
    return 0;
}
