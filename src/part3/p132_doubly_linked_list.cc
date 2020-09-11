#include "p132_doubly_linked_list.h"

void PrintNode(Node *node) {
  if (node == nullptr) {
    cout << "null" << endl;
    return;
  }
  cout << "{ key: " << node->key;
  if (node->prev != nullptr) {
    cout << ", prev: " << node->prev->key;
  }
  if (node->next != nullptr) {
    cout << ", next: " << node->next->key;
  }
  cout << " }";
}

void PrintLinkedList(LinkedList *l) {
  Node *node = l->head();
  while (node != nullptr) {
    cout << node->key;
    if (node->next != nullptr) {
      cout << " -> ";
    }
    node = node->next;
  }
}

void TestLinkedList() {
  LinkedList l;
  l.PushFront(1);
  l.PushFront(4);
  l.PushFront(16);
  l.PushFront(9);
  l.PushFront(25);
  Node *x1 = l.Search(4);
  if (x1 != nullptr) {
    PrintNode(x1);
  } else {
    cout << "null" << endl;
  }
  PrintLinkedList(&l);
  l.Reverse();
  PrintLinkedList(&l);
  l.RemoveKey(4);
  Node *x2 = l.Search(4);
  if (x2 != nullptr) {
    PrintNode(x2);
  } else {
    cout << "null" << endl;
  }
  PrintLinkedList(&l);
}

int main() {
  TestLinkedList();
}
