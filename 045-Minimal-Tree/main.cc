// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "cobjectgraph.h"
#include <fstream>
#include "tree.h"
#include "treeGraph.h"


using namespace std;

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

void inorder (BSTNode * root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->right);
    cout << root->data << '\n';
    inorder(root->left);
}

int height(BSTNode * root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
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
//    inorder(root);
//    cout << "height = " << height(root) << '\n';
    GenerateObjectGraph(root, cout);
    return 0;
}
