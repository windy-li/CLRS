#include "p132_doubly_linked_list.h"

void PrintNode(Node* node) {
  if (node == nullptr) {
    std::cout << "null" << std::endl;
    return;
  }
  std::cout << "{ key: " << node->key;
  if (node->prev != nullptr) {
    std::cout << ", prev: " << node->prev->key;
  }
  if (node->next != nullptr) {
    std::cout << ", next: " << node->next->key;
  }
  std::cout << " }";
}

void PrintLinkedList(LinkedList* l) {
  Node* node = l->head();
  while (node != nullptr) {
    std::cout << node->key;
    if (node->next != nullptr) {
      std::cout << " -> ";
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
  Node* x1 = l.Search(4);
  if (x1 != nullptr) {
    PrintNode(x1);
  } else {
    std::cout << "null" << std::endl;
  }
  PrintLinkedList(&l);
  l.Reverse();
  PrintLinkedList(&l);
  l.RemoveKey(4);
  Node* x2 = l.Search(4);
  if (x2 != nullptr) {
    PrintNode(x2);
  } else {
    std::cout << "null" << std::endl;
  }
  PrintLinkedList(&l);
}

int main() { TestLinkedList(); }
