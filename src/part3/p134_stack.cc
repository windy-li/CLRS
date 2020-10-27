#include "../clrs.h"

class Stack {
 public:
  Stack() : dq_(new std::deque<int>()) {}

  bool Empty() { return dq_->empty(); }

  void Push(int key) { dq_->push_back(key); }

  std::tuple<int, clrs::error> Pop() {
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
  Stack self;
  self.Push(15);
  self.Push(6);
  self.Push(2);
  self.Push(9);
  self.Push(17);
  self.Push(3);
  auto [result, err] = self.Pop();
  std::cout << result << std::endl;
}

/*
 * 3
 */
