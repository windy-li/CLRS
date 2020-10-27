#include "../clrs.h"

struct Node {
  int key;
  Node* next;

  explicit Node(int key) : key(key), next(nullptr) {}
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

  void PushFront(int key) {
    Node* node = new Node(key);
    node->next = head_;
    head_ = node;
  }

  void PopFront(Node* node) {
    if (node == head_) {
      head_ = head_->next;
    } else {
      Node* temp = head_;
      while (temp->next != node) {
        temp = temp->next;
      }
      temp->next = node->next;
    }
  }

  void Remove(int key) {
    Node* node = Search(key);
    if (node != nullptr) {
      PopFront(node);
    }
  }

  void Reverse() {
    Node* prev = nullptr;
    Node* current = head_;
    while (current != nullptr) {
      Node* tmp = current->next;
      current->next = prev;
      prev = current;
      current = tmp;
    }
    head_ = prev;
  }

 private:
  Node* head_;
};

int main() {
  LinkedList list;
  list.PushFront(1);
  list.PushFront(4);
  list.PushFront(16);
  list.PushFront(9);
  list.PushFront(25);
  std::cout << list.Search(1) << std::endl;
  list.Remove(4);
  std::cout << list.Search(4) << std::endl;
}

/*
 * 0x7fd71c400680
 * 0x0
 */
