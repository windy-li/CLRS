#include "clrs.h"

struct Node {
  int key;
  Node* prev;
  Node* next;

  explicit Node(int key) : key(key), prev(nullptr), next(nullptr) {}
};

class LinkedList {
 public:
  LinkedList() : head_(nullptr) {}

  Node* head() { return head_; }

  Node* Search(int key) {
    Node* node = head_;
    while (node != nullptr && node->key != key) {
      node = node->next;
    }
    return node;
  }

  void PushFront(int k) {
    Node* node = new Node(k);
    node->prev = nullptr;
    node->next = head_;
    if (head_ != nullptr) {
      head_->prev = node;
    }
    head_ = node;
  }

  void RemoveKey(int k) {
    Node* x = Search(k);
    if (x != nullptr) {
      Remove(x);
    }
  }

  void Remove(Node* node) {
    if (node->prev != nullptr) {
      node->prev->next = node->next;
    } else {
      head_ = node->next;
    }
    if (node->next != nullptr) {
      node->next->prev = node->prev;
    }
  }

  void Reverse() {
    Node* tmp = nullptr;
    Node* current = head_;
    while (current != nullptr) {
      tmp = current->prev;
      current->prev = current->next;
      current->next = tmp;
      current = current->prev;
    }
    if (tmp != nullptr) {
      head_ = tmp->prev;
    }
  }

 private:
  Node* head_;
};

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
