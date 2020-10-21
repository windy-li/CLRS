#include "clrs.h"

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

int main() {
  auto *self = new Stack();
  self->Push(15);
  self->Push(6);
  self->Push(2);
  self->Push(9);
  self->Push(17);
  self->Push(3);
  std::cout << self->Pop() << std::endl;
  return 0;
}

/*
 * 3
 */
