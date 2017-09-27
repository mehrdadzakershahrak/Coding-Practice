// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int BestTime(vector<int> & price) {
    int size = price.size();
    vector<int> buy(size,0);
    vector<int> sell(size,0);
    buy[0] = -1 * price[0];
    buy[1] = max(-1 * price[0], -1 * price[1]);
    sell[1] = max(0, price[1] - price[0]);
    for (int i = 2; i < price.size(); i++) {
        buy[i] = max(buy[i-1], sell[i-2] - price[i]);
        sell[i] = max(sell[i-1], buy[i-1] + price[i]);
    }
    return sell[size-1];
}

int main(int argc, char* argv[])
{
    int p;
    cin >> p;
    vector<int> price(p,0);
    for (int i = 0; i < p; i++) {
        int pr;
        cin >> pr;
        price[i] = pr;
    }
    cout << BestTime(price) << "\n" ;
    return 0;
}
