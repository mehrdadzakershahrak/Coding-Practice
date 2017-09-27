// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>


using namespace std;

vector<string> permutationsNoDup(string s) {
    if (s.size() <= 1) { return { s };}
    auto p = permutationsNoDup(s.substr(1));
    char c = s[0];
    vector<string> q;
    for (int i = 0; i < p.size(); i++) {
        for (int j = 0; j <= p[i].size(); j++) {
            string copy = p[i];
            copy.insert(copy.begin() + j, c);
            q.push_back(copy);
        }
    }
    return q;
}

unordered_set<string> permutationsDup(string s) {
    if (s.size() <= 1) { return { s };}
    unordered_set<string> q;
    for (auto& p : permutationsDup(s.substr(1))) {
        for (int j = 0; j <= p.size(); j++) {
            string copy = p;
            copy.insert(copy.begin() + j, s[0]);
            q.insert(copy);
        }
    }
    return q;
}

int main(int argc, char* argv[])
{
    string input;
    cin >> input;
    //auto p = permutationsNoDup(input);
    auto p = permutationsDup(input);
    for (auto& s : p) {
        cout << s << '\n';
    }
    return 0;
}
