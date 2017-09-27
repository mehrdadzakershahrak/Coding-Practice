// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>


using namespace std;
struct BSTNode {
    int data;
    BSTNode * left;
    BSTNode * right;
};

BSTNode * createMinTree(const vector<int> & arr, int i, int j) {
    if (i == j) {
        return new BSTNode {arr[i], nullptr, nullptr};
    }
    if (i > j) {
        return nullptr;
    }
    int mid = (i + j) / 2;
    BSTNode * root = new BSTNode {arr[mid],nullptr, nullptr};
    root->left = createMinTree(arr,i, mid - 1);
    root->right = createMinTree(arr,mid + 1, j);
    return root;
}

int listDepth(BSTNode * root, unordered_map<int,list<BSTNode * >> & lists) {
    if (root == nullptr) {
        return 0;
    }
    int left = listDepth(root->left, lists);
    int right = listDepth(root->right, lists);
    int h = 1 + max(left, right);
    lists[h].push_back(root);
    return h;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n; i++) {
        cin >> a[i];
    }
    BSTNode * root = createMinTree(a, 0, n - 1);
    unordered_map<int, list<BSTNode * >> lists;
    int height = listDepth(root, lists);
    for (auto kv : lists) {
        cout <<" @ depth " << height - kv.first << ": ";
        for (auto node : kv.second) {
            cout << node->data << ' ';
        }
        cout << '\n';
    }

    return 0;
}
