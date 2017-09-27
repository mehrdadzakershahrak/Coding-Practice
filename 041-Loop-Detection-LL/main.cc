#include <iostream>
#include <stdexcept>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node * next;
};

Node * generateListWithCycle (int n, int x) {
  Node * head = nullptr, * tail = nullptr, * cycle = nullptr;
  for (int i = 0; i < n; i++) {
    Node * node = new Node {i + 1, nullptr};
    if (head == nullptr) {
        head = tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
    if (i + 1 == x) {
      cycle = node;
    }
  }
  tail->next = cycle;
  return head;
}


Node * detectCycle( Node * head) {
  Node * fast = head, * slow = head;
  bool detected = false;
  while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      detected = true;
      break;
    }
  }
  if (detected) {
    slow = head;
    while(slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
  return nullptr;
}


int main(){
  Node *h1 = generateListWithCycle(10,3);
  Node *c = detectCycle(h1);
  if (c != nullptr) {
    cout << "detected cycle @ " << c->data << "\n";
  }
  else {
    cout << "No Cycle" << '\n';
  }
  return 0;
}
