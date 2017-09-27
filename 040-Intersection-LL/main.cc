#include <iostream>
#include <stdexcept>
#include <stack>

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

int calculateSize(Node * head) {
  int count = 0;
  while (head != nullptr) {
    count++;
    head = head->next;
  }
  return count;
}

Node * generateList(int n, int x) {
  Node * head = nullptr, * tail = nullptr;
  for (int i = 0; i < n; i++) {
      append(x * (i + 1), head, tail);
  }
  return head;
}

void printList (Node * head) {
  while (head != nullptr) {
    cout << head->data <<' ';
    head  = head->next;
  }
  cout << '\n';
}

Node * intersection(Node * h1, Node * h2) {
    int s1 = calculateSize(h1);
    int s2 = calculateSize(h2);
    Node * shorter = (s1 < s2 ? h1 : h2);
    Node * longer = (s1 < s2 ? h2 : h1);
    int sizeDiff = (s1 < s2 ? (s2 - s1) : (s1 - s2));
    for (int i = 0; i < sizeDiff; i++) {
      longer = longer->next;
    }
    while (longer != shorter) {
      longer = longer->next;
      shorter = shorter->next;
    }
    return shorter;
}

int main()
{
  Node * h1 = generateList(7,1);
  Node * h2 = generateList(5,10);
  Node * iter = h2;
  while (iter->next != nullptr) iter = iter->next;
  iter->next = h1->next->next->next->next;
  printList(h1);
  printList(h2);
  Node * inter = intersection(h1, h2);
  if (inter != nullptr) {
    cout << "intersection: " << inter->data << '\n';
  }
  else {
    cout << "No intersection " << '\n';
  }
  return 0;
}
