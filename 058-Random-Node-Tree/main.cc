// Compile as C++11
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <random>
#include <unordered_map>

using namespace std;

enum Child { LEFT, RIGHT};

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine RNG (seed);

struct BinaryTree {
    int data;
    BinaryTree * left;
    BinaryTree * right;
    BinaryTree * parent;
    int size;

    explicit BinaryTree(int data_)
    : data{data_}, left{nullptr}, right{nullptr}, parent{nullptr}, size{1}
    {
    }

    ~BinaryTree() {
        cerr << "Deleting node " << data << '\n';

        if (left != nullptr) {
            left->parent = nullptr;
            delete left;
            left = nullptr;
        }
        if (right != nullptr) {
            right->parent = nullptr;
            delete right;
            right = nullptr;
        }
        BinaryTree * p = parent;
        while (p) {
            p->size -= size;
            p = p->parent;
        }
        if (parent != nullptr) {
            if (parent->right == this) {
                parent->right = nullptr;
            }
            if (parent->left == this) {
                parent->left = nullptr;
            }
        }
    }

    BinaryTree * Insert(int data, Child child) {
        if (child == LEFT && left != nullptr) { return nullptr; }
        if (child == RIGHT && right != nullptr) { return nullptr; }
        BinaryTree * node = new BinaryTree(data, this);
        if (child == LEFT) {
            left = node;
        }
        else {
            right = node;
        }
        size++;
        BinaryTree * p = parent;
        while (p) {
            p->size++;
            p = p->parent;
        }
        return node;
    }

    BinaryTree * Find(int x) {
        if (data == x) {
            return this;
        }
        if (left != nullptr) {
            auto lp = left->Find(x);
            if (lp != nullptr) { return lp; }
        }
        if (right != nullptr) {
            return right->Find(x);
        }
        return nullptr;
    }

    BinaryTree * getRandomNode() {
        uniform_int_distribution<int> distribution(1,size);
        int x = distribution(RNG);
        return getNode(x);
    }

private:
    BinaryTree * getNode(int index) {
        int leftSize = 0;
        if (left != nullptr) { leftSize = left->size; }
        if (index <= leftSize) {
            return left->getNode(index);
        } else if (index < size) {
            return right->getNode(index - leftSize);
        }
        return this;
    }

    BinaryTree(int data_, BinaryTree * parent_)
    : data{data_}, left{nullptr}, right{nullptr}, parent{parent_}, size{1}
    {
    }
};

int main(int argc, char* argv[])
{
    BinaryTree * root = new BinaryTree(1);
    BinaryTree * n1 = root->Insert(2,LEFT);
    BinaryTree * n2 = root->Insert(3,RIGHT);
    BinaryTree * n3 = n1->Insert(4,LEFT);
    BinaryTree * n4 = n1->Insert(5,RIGHT);
    BinaryTree * n5 = n2->Insert(6,LEFT);
    BinaryTree * n6 = n2->Insert(7,RIGHT);
    n4->Insert(8,LEFT);
    n5->Insert (9, LEFT);
    n5->Insert (10, RIGHT);
    unordered_map<int,int> freq;
    //delete n1;
    for (int i = 0; i < 10000; i++) {
        BinaryTree * r = root->getRandomNode();
        freq[r->data]++;
    }
    for (auto kvp : freq) {
        cout << "freq[" << kvp.first << "]" << "=" << kvp.second << '\n';
    }
    return 0;
}
