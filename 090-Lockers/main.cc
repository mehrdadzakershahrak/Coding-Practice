// Compile as C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    // Read input
    vector<bool> door(101,true);
    for (int i = 2; i <= 100; i++) {
        for (int j = i; j <= 100; j += i){
            door[j] = !door[j];
        }
    }
    int count = 0;
    for (int i = 0; i < 100; i++) {
        if (door[i]) { 
            cout << "door " << i << " is open\n";
            count++;
        }
    }
    cout << count << " doors are open\n";
    return 0;
}
