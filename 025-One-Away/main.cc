#include <map>
#include <set>
#include <list>
#include <cctype>
#include <cmath>
#include <ctime>
#include <deque>
#include <cstdlib>
#include <iostream>


using namespace std;

bool isOneAway(string x, string y) {
    int sizeDiff = abs(x.size() - y.size());
    if (sizeDiff > 1) {
        return false;

    }
    int i = 0, j = 0;
    int edits = 0;
    while (i < x.size() && j < y.size()) {
        if (x[i] == y[j]) {
            i++;
            j++;
        }
        else {
            edits++;
            if (sizeDiff == 0) { // This is a Change 
                i++;
                j++;
            }
            else {
                if (x.size() > y.size()) {
                    i++;
                }
                else {
                    j++;
                }
            }
        }
    }
    return (edits <= 1);
}


int main(){
    string x,y;
    cin >> x >> y;
    cout << isOneAway(x,y) << endl;
    return 0;
}

