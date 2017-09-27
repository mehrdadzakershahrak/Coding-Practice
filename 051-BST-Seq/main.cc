// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <list>

using namespace std;


struct BTNode {
    int data;
    BTNode * left;
    BTNode * right;
};

BTNode * createMinTree(const vector<int> & arr, int i, int j);

vector<list<int>> weave(list<int> & first,
    list<int> & second,
    vector<int> & prefix)
{
    vector<list<int>> result;
    if (first.size() == 0 || second.size() == 0) {
        list<int> r;
        r.insert(r.end(), prefix.begin(), prefix.end());
        r.insert(r.end(), first.begin(), first.end());
        r.insert(r.end(), second.begin(), second.end());
        result.push_back(r);
        return result;
    }
    int f = first.front();
    first.pop_front();
    prefix.push_back(f);
    auto wf = weave(first, second, prefix);
    prefix.pop_back();
    first.push_front(f);
    result.insert(result.end(), wf.begin(), wf.end());

    int s = second.front();
    second.pop_front();
    prefix.push_back(s);
    auto ws = weave(first, second, prefix);
    prefix.pop_back();
    second.push_front(s);
    result.insert(result.end(), ws.begin(), ws.end());

    return result;
}

vector<list<int>> allSequences(BTNode * root) {
    if (root == nullptr) {
        return {{}};
    }
    vector<list<int>> all;
    auto left = allSequences(root->left);
    auto right = allSequences(root->right);
    vector<int> prefix;
    prefix.push_back(root->data);
    for (auto & l : left) {
        for (auto & r : right) {
            auto x = weave(l, r, prefix);
            all.insert(all.end(), x.begin(), x.end());
        }
    }
    return all;
}

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0;i < n; i++) {
        cin >> arr[i];
    }
    BTNode * root = createMinTree(arr, 0, n - 1);
    auto all = allSequences(root);
    for (auto & a : all) {
        cout << "[";
        for (int x : a) {
            cout  << " " << x;
        }
        cout << " ]";
        cout << '\n';
    }
    cout << "Found " << all.size() << " possible arrays" << '\n';
    return 0;
}

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
