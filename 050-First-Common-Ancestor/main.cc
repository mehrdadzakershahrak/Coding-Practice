// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;


struct BTNode {
    int data;
    BTNode * left;
    BTNode * right;
};

BTNode * createMinTree(const vector<int> & arr, int i, int j) {
    if (i == j) {
        return new BTNode {arr[i], nullptr, nullptr};
    }
    if (i > j) {
        return nullptr;
    }
    int mid = (i + j) / 2;
    BTNode * root = new BTNode {arr[mid],nullptr, nullptr};
    root->left = createMinTree(arr,i, mid - 1);
    root->right = createMinTree(arr,mid + 1, j);
    return root;
}
pair<BTNode *, bool> findLCA_Helper (BTNode * root, int a, int b) {
    if (root == nullptr) { return {nullptr, false}; }
    if (root->data == a && root->data == b) { return {root, true}; }
    auto lx = findLCA_Helper(root->left, a, b);
    if (lx.second) {
        return lx;
    }
    auto rx = findLCA_Helper(root->right, a, b);
    if (rx.second) {
        return rx;
    }
    if (lx.first != nullptr && rx.first != nullptr) {
        return {root, true};
    }
    else if (root->data == a || root->data == b) {
        return {root, (rx.first != nullptr || lx.first != nullptr)};
    }
    else {
        return {(lx.first != nullptr ? lx.first : rx.first), false};
    }
}
// This solution finds if the query node is in the tree or not
// Then it recursively returns a pair of node and a boolean
BTNode * findLCA(BTNode * root, int a, int b) {
    auto r = findLCA_Helper(root, a, b);
    if (r.second) {
        return r.first;
    }
    return nullptr;
}

int main(int argc, char* argv[])
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0;i < n; i++) {
        cin >> arr[i];
    }
    BTNode * root = createMinTree(arr, 0, n - 1);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        BTNode * lca = findLCA(root, a, b);
        if (lca == nullptr) {
            cout << "LCA not found" << '\n';
        }
        else {
            cout << "LCA(" << a << "," << b << ") = " << lca->data << '\n';
        }
    }
    return 0;
}
