// Compile as C++11
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BSTNode {
    int data;
    BSTNode * left;
    BSTNode * right;
    BSTNode * parent;
};

BSTNode * getSuccessor (BSTNode * node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right != nullptr) {
        BSTNode * cursor = node->right;
        while (cursor->left != nullptr) {
            cursor = cursor->left;
        }
        return cursor;
    }
    if (node->parent == nullptr) {
        return nullptr;
    }
    BSTNode * cursor = node;
    while (cursor->parent != nullptr && cursor->parent->right == cursor) {
        cursor = cursor->parent;
    }
    return cursor->parent;
}

BSTNode * createMinTree(const vector<int> & arr, int i, int j) {
    if (i == j) {
        return new BSTNode {arr[i], nullptr, nullptr, nullptr};
    }
    if (i > j) {
        return nullptr;
    }
    int mid = (i + j) / 2;
    BSTNode * root = new BSTNode {arr[mid],nullptr, nullptr, nullptr};
    root->left = createMinTree(arr,i, mid - 1);
    root->right = createMinTree(arr,mid + 1, j);

    if (root->left != nullptr) {
        root->left->parent = root;
    }
    if (root->right != nullptr) {
        root->right->parent = root;
    }
    return root;
}

void inorder (BSTNode * root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->right);
    BSTNode * s = getSuccessor(root);
    cout << "Successor of " << root->data << " is " << (s == nullptr ? "NULL" : to_string(s->data)) << '\n';
    inorder(root->left);
}

int main(int argc, char* argv[])
{
    // Read input
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n; i++) {
        cin >> a[i];
    }
    BSTNode * root = createMinTree(a, 0, n - 1);
    inorder(root);

    return 0;
}
