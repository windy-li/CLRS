#include "clrs.h"

class Stack {
 public:
  Stack() : dq_(new std::deque<int>()) {}

  bool Empty() { return dq_->empty(); }

  void Push(int key) { dq_->push_back(key); }

  std::tuple<int, int> Pop() {
    if (Empty()) {
      return {0, 1};
    }
    int ret = dq_->back();
    dq_->pop_back();
    return {ret, 0};
  }

 private:
  std::deque<int>* dq_;
};

int main() {
  auto s = Stack();
  s.Push(15);
  s.Push(6);
  s.Push(2);
  s.Push(9);
  s.Push(17);
  s.Push(3);
  auto [result, err] = s.Pop();
  std::cout << result << std::endl;
}

/*
 * 3
 */
