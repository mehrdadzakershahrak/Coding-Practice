// Given a time in -hour AM/PM format, convert it to military (-hour) time.
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;
int main() {
    string time;
    cin >> time;

    string output = time.substr(0, 8);
    string ampm = time.substr(time.size() - 2);
    string hourString = time.substr(0, 2);

    if (ampm == "PM" && hourString != "12") {
        int hour = stoi(hourString);
        hour = (hour + 12);

        stringstream ss;
        ss << hour;

        output[0] = ss.str()[0];
        output[1] = ss.str()[1];
    }
    else if (ampm == "AM" && hourString == "12") {
        output[0] = output[1] = '0';
    }

    cout << output;

    return 0;
}
