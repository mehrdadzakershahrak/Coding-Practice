#include <iostream>
#include <stdexcept>
#include <stack>

using namespace std;

struct Node {
    char data;
    Node * next;
};


bool isPalindromeHelper(Node * head, int length, Node * & next) {
  if (head == nullptr || length == 0) {
      next = head;
      return true;
  }
  if (length == 1) {
    next = head->next;
    return true;
  }
  auto restOk = isPalindromeHelper(head->next, length - 2,next);
  if (!restOk) {
    return false;
  }
  if (head->data == next->data) {
    next = next->next;
    return true;
  }
  return false;
}

bool isPalindromeRecursive (Node * head) {
  int size = 0;
  Node * it = head;
  while(it) {
    size++;
    it = it->next;
  }
  Node * next;
  return isPalindromeHelper(head, size, next);

}

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

bool isPalindrome (Node * head) {
  stack<char> s;
  int size = 0;
  Node * it = head;
  while(it) {
    size++;
    it = it->next;
  }
  it = head;
  for (int i = 0; i < size / 2; i++) {
    s.push(it->data);
    it = it->next;
  }
  if(size % 2 == 1) {
    it = it->next;
  }
  while(it) {
    if(s.top() != it->data) {
      return false;
    }
    s.pop();
    it = it->next;
  }
  return true;
}


int main(){
    Node *h1 = readList();
    cout << isPalindromeRecursive(h1) << '\n';
    return 0;
}
