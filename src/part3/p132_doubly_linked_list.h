#include "clrs.h"

struct Node {
  int key;
  Node *prev;
  Node *next;

  explicit Node(int key) : key(key), prev(nullptr), next(nullptr) {}
};

class LinkedList {
 public:
  LinkedList() : head_(nullptr) {}

  Node *head() { return head_; }

  Node *Search(int key) {
    Node *node = head_;
    while (node != nullptr && node->key != key) {
      node = node->next;
    }
    return node;
  }

  void PushFront(int k) {
    Node *node = new Node(k);
    node->prev = nullptr;
    node->next = head_;
    if (head_ != nullptr) {
      head_->prev = node;
    }
    head_ = node;
  }

  void RemoveKey(int k) {
    Node *x = Search(k);
    if (x != nullptr) {
      Remove(x);
    }
  }

  void Remove(Node *node) {
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
    Node *tmp = nullptr;
    Node *current = head_;
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
  Node *head_;
};
