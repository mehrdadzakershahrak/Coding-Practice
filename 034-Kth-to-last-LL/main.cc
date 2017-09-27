#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node * next;
};

int kToLast(Node * head, int k) {
    if (head == nullptr) {
        throw runtime_error("LL can't be empty");
    }
    Node * p1 = head;
    Node * p2 = head;
    int count = 0;
    while (p2 != nullptr) {
        p2 = p2->next;
        count++;
        if (count > k && p2 != nullptr) {
            p1 = p1->next;
        }
    }
    if (k > count - 1) {
        throw runtime_error("k > size of LL");
    }
    return p1->data;
}


int main(){
    
    int n,k;
    cin >> n >> k;
    Node * head = nullptr, * tail = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node * node = new Node {x, nullptr};
        if (head == nullptr) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;

        }
    }
    cout << kToLast(head, k) << endl;
    return 0;
}
