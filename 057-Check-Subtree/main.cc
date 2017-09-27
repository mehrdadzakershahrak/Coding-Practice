// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <sstream>
#include <unordered_map>


using namespace std;

struct Tree {
    int data;
    Tree * left;
    Tree * right;
};

using SPEC = tuple<int, int , int>;

Tree * makeTreeHelper(int node, unordered_map<int, SPEC> & treeSpec) {
    if (node == 0) {return nullptr;}
    Tree * root = new Tree;
    root->data = get<0>(treeSpec[node]);
    root->left = makeTreeHelper(get<1>(treeSpec[node]), treeSpec);
    root->right = makeTreeHelper(get<2>(treeSpec[node]), treeSpec);
    return root;
}

Tree * readTree() {
    int n;
    unordered_map<int, SPEC> treeSpec;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int data, left, right;
        cin >> data >> left >> right;
        treeSpec[i] = make_tuple(data, left, right);
    }
    return makeTreeHelper(1, treeSpec);
}

void preOrder(Tree * root, ostream & output) {
    if (root == nullptr) {
        output << "* ";
        return;
    }
    output << root->data << ' ';
    preOrder(root->left, output);
    preOrder(root->right, output);
}


int main(int argc, char* argv[])
{
    Tree *  T1 = readTree();
    Tree *  T2 = readTree();
    ostringstream oss1, oss2;
    preOrder(T1, oss1);
    preOrder(T2, oss2);
    string str1 = oss1.str();
    string str2 = oss2.str();
    auto pos = str1.find(str2);
    if (pos == string::npos) {
        cout << "not a subtree! " << '\n';
    }
    else {
        cout << "T2 is a subtree of T1" << '\n';
    }
    return 0;
}
