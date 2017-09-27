#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> RemoveDuplicates(vector<int> input)
{
	vector<int> output;
    unordered_map <int,int> map;
    for (int i = 0; i < input.size(); i++) {
        map[input[i]]++;
        if (map[input[i]] == 1) {
            output.push_back(input[i]);
        }
    }
	return output;
}

int main(int argc, char* argv[])
{
    // Read input
    int n;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        input.push_back(x);
    }
    auto output = RemoveDuplicates(input);
    for (auto x : output) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
