// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <sstream>

using namespace std;

struct BinaryTree {
    int data;
    BinaryTree * left;
    BinaryTree * right;
};

using SPEC = tuple<int, int , int>;

BinaryTree * makeTreeHelper(int node, unordered_map<int, SPEC> & treeSpec) {
    if (node == 0) {return nullptr;}
    BinaryTree * root = new BinaryTree;
    root->data = get<0>(treeSpec[node]);
    root->left = makeTreeHelper(get<1>(treeSpec[node]), treeSpec);
    root->right = makeTreeHelper(get<2>(treeSpec[node]), treeSpec);
    return root;
}

BinaryTree * readTree() {
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

int pathWithSumHelper(BinaryTree * root, int targetSum,
                unordered_map<int, int> & withSum,
                int runningSum)
{
    if (root == nullptr) { return 0; }
    int count = 0;
    runningSum += root->data;
    count +=withSum[runningSum - targetSum];
    withSum[runningSum]++;
    count += pathWithSumHelper(root->left, targetSum, withSum, runningSum);
    count += pathWithSumHelper(root->right, targetSum, withSum, runningSum);
    withSum[runningSum]--;
    return count;
}

int pathWithSum(BinaryTree * root, int targetSum) {
    unordered_map<int, int> withSum;
    withSum[0] = 1;
    return pathWithSumHelper(root, targetSum, withSum, 0);
}

int countSubsequenceWithSums(vector<int> & arr, int targetSum) {
    unordered_map<int, int> withSum;
    int runningSum = 0, count = 0;
    withSum[0] = 1;
    for (int i = 0; i < arr.size(); i++) {
        runningSum += arr[i];
        count += withSum[runningSum - targetSum];
        withSum[runningSum]++;
    }
    return count;
}

int bruteForce(vector<int> & arr, int targetSum) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i; j < arr.size(); j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }
            if (sum == targetSum) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char* argv[])
{

    BinaryTree * T = readTree();
    int sum;
    cin >> sum;
    int count = pathWithSum(T, sum);
    cout << "found " << count << " paths with sum" << '\n';
    return 0;
}
