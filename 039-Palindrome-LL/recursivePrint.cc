#include <iostream>
#include <stdexcept>
#include <stack>

using namespace std;

struct Node {
    char data;
    Node * next;
};

void append(char x, Node * & head, Node * & tail) {
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
      char x;
      cin >> x;
      append(x, head, tail);
  }
  return head;
}

void recurse(Node * head) {
    if (head == nullptr) { return;}

    if (head->next != nullptr) {
        recurse(head->next);
	}
    cout << head->data << '\n';

}

int main(){
    Node *h1 = readList();
    recurse(h1);
    return 0;
}
