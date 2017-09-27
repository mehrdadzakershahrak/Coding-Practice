#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node * next;
};

void append(int x, Node * & head, Node * & tail) {
  Node * node = new Node {x, nullptr};
  if (head == nullptr) {
      head = tail = node;
  }
  else {
      tail->next = node;
      tail = node;
  }
}


Node * readList() {
  int n;
  cin >> n;
  Node * head = nullptr, * tail = nullptr;
  for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      append(x, head, tail);
  }
  return head;
}

Node * reverseList(Node * & head) {
  Node * prev = nullptr;
  while(head != nullptr) {
    Node * next = head->next;
    head->next  = prev;
    prev = head;
    head = next;
  }
  head = prev;
  return head;
}


void printRecursive(Node * head) {
  if (head == nullptr) return;
  printRecursive(head->next);
  cout << head->data << " " ;
}
void printList(Node * head) {
  while (head != nullptr) {
    cout << head->data << ' ';
    head = head->next;
    }
    cout << '\n';
}

Node * sumReverse( Node * h1, Node * h2) {
  // Sum two numbers represented by h1 and h2 and they are in
  // reverse order
    int c = 0;
    Node * head = nullptr, * tail = nullptr;
    while (h1 != nullptr || h2 != nullptr) {
      int x = c;
      if (h1 != nullptr) { x += h1->data;}
      if (h2 != nullptr) { x += h2->data;}
      c = x / 10;
      x = x % 10;
      append(x, head, tail);
      h1 = (h1 == nullptr? nullptr :h1->next);
      h2 = (h2 == nullptr? nullptr :h2->next);
    }
    if (c > 0) {
      append(c, head, tail);
    }
    return head;
}

Node * sumHard( Node * h1, Node * h2) {
  // Sum two LL assuming they are stored in forward order.
  Node * r = sumReverse(reverseList(h1), reverseList(h2));
    return reverseList(r);
}

int main(){
    Node *h1 = readList();
    Node *h2 = readList();
    //Node * result = sumReverse(h1, h2);
    Node * result = sumHard(h1, h2);
    printList(result);
    cout << '\n';
    return 0;
}
