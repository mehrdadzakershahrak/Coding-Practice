// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>


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

int height(BSTNode * root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

pair<bool, int> isBalancedPair(BSTNode * root) {
    if (root == nullptr) {
        return make_pair(true,0);
    }
    pair<bool, int> left = isBalancedPair(root->left);
    pair<bool, int> right = isBalancedPair(root->right);
    int height =  1 + max(left.second, right.second);
    return make_pair(left.first && right.first && abs(left.second - right.second) <= 1, height);
}

bool isBalanced(BSTNode * root, int & height) {
    if (root == nullptr) {
        height = 0;
        return true;
    }
    int leftHeight, rightHeight;
    bool leftBalanced = isBalanced(root->left, leftHeight);
    bool rightBalanced = isBalanced(root->right, rightHeight);
    height =  1 + max(leftHeight, rightHeight);
    return leftBalanced && rightBalanced && abs(leftHeight - rightHeight) <= 1 ;
}

bool isBalanced(BSTNode * root) {
    //int height;
    //return isBalanced(root, height);
    pair<bool, int> r = isBalancedPair(root);
    return r.first;
}

int main(int argc, char* argv[])
{
    // int n;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0;i < n; i++) {
    //     cin >> a[i];
    // }
    // //BSTNode * root = createMinTree(a, 0, n - 1);
    BSTNode * root = new BSTNode {10 , nullptr, nullptr};
    BSTNode * n1 = new BSTNode {20 , nullptr, nullptr};
    BSTNode * n2 = new BSTNode {30 , nullptr, nullptr};
    BSTNode * n3 = new BSTNode {40 , nullptr, nullptr};
    BSTNode * n4 = new BSTNode {50 , nullptr, nullptr};
    BSTNode * n5 = new BSTNode {60 , nullptr, nullptr};
    BSTNode * n6 = new BSTNode {70 , nullptr, nullptr};
    root->left = n1;
    n1->left = n2;
    n1->right = n3;
    root->right = n4;
    n4->right = n5;
    n4->left = n6;
    cout << isBalanced(root) << '\n';

    return 0;
}
