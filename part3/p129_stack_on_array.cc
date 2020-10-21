#include "clrs.h"

class Stack {
 public:
  explicit Stack(int capacity) : nums_(std::vector<int>(capacity)), capacity_(capacity), top_(-1) {}

  bool Empty() { return top_ == -1; }

  bool Full() { return top_ == capacity_ - 1; }

  clrs::error Push(int key) {
    if (Full()) {
      std::cerr << "stack overflow" << std::endl;
      return 1;
    }
    nums_[++top_] = key;
    return 0;
  }

  std::tuple<int, clrs::error> Pop() {
    if (Empty()) {
      std::cerr << "stack underflow" << std::endl;
      return {0, 1};
    }
    return {nums_[top_--], 0};
  }

 private:
  std::vector<int> nums_;
  int capacity_;
  int top_;
};

int main() {
  Stack s(7);
  s.Push(15);
  s.Push(6);
  s.Push(2);
  s.Push(9);
  s.Push(17);
  s.Push(3);
  auto [ret, err] = s.Pop();
  if (!err) {
    std::cout << ret << std::endl;
  }
}
