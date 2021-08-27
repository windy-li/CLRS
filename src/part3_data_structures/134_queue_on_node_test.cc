#include "clrs.h"

struct Node {
  int key;
  Node* next;

  explicit Node(int key) : key(key), next(nullptr) {}
};

class Queue {
 public:
  Queue() : head_(nullptr), tail_(nullptr) {}

  bool Empty() { return head_ == nullptr; }

  void Push(int key) {
    auto node = new Node(key);
    if (Empty()) {
      head_ = node;
      tail_ = node;
    } else {
      tail_->next = node;
      tail_ = node;
    }
  }

  int Pop() {
    if (Empty()) {
      throw std::underflow_error("queue underflow");
    }
    int ret = head_->key;
    head_ = head_->next;
    return ret;
  }

 private:
  Node* head_;
  Node* tail_;
};

int main() {
  auto q = Queue();
  q.Push(15);
  q.Push(6);
  q.Push(9);
  q.Push(8);
  q.Push(4);
  std::cout << q.Pop();
}

/*
 * 15
 */
