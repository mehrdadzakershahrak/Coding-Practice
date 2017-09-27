#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Trie {
	private:
        unordered_map<char, Trie*> children;
        int count;

    public:
        Trie() {
            count = 0;
        }
        void insert(string str) {
            Trie* node = this;
            for (char c : str) {
                node->count++;
                if (node->children[c] == nullptr) {
                    node->children[c] = new Trie;
                }
                node = node->children[c];
            }
            node->count++;
            if (node->children['*'] == nullptr) {
                node->children['*'] = new Trie;
            }

        }
        Trie* search(string str) {
            Trie* node = this;
            for (char c : str) {
                node = node->children[c];
                if (node ==  nullptr) {
                    break;
                }
            }
            return node;
        }
        int getCount() { return count;  }
};


int main(){
    Trie* T = new Trie;
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        if (op == "add") {
            T->insert(contact);
        }
        else if (op == "find") {
            Trie *S = T->search(contact);
            cout << (S == nullptr ? 0 : S->getCount()) << '\n';
        }
    }
    return 0;
}

