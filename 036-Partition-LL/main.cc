#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node * next;
};

Node * partition(Node * head, int pivot) {
    Node * i = head;
    Node * prev = nullptr;
    while (i != nullptr) {
        if (i->data < pivot && prev != nullptr) {
            auto tmp = i->next;
            i->next = head;
            head = i;
            prev->next = tmp;
            i = tmp;
        }
        else {
            prev = i;
            i = i->next;
        }
    }
    return head;
}

void printList(Node * head) {
    while (head != nullptr) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl; 
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
    head = partition(head, k);
    printList(head);
    return 0;
}
