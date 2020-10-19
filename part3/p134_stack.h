#include "p134_singly_linked_list.h"

class Stack {
 public:
  Stack() : q_(new std::deque<int>()) {}

  bool Empty() { return q_->empty(); }

  void Push(int key) { q_->push_back(key); }

  std::tuple<int, clrs::error> Pop() {
    if (Empty()) {
      return {0, 1};
    }
    int ret = q_->back();
    q_->pop_back();
    return {ret, 0};
  }

 private:
  std::deque<int>* q_;
};
