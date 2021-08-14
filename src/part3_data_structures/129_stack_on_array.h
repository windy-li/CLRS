#ifndef CLRS_SRC_PART3_DATA_STRUCTURES_129_STACK_ON_ARRAY_H_
#define CLRS_SRC_PART3_DATA_STRUCTURES_129_STACK_ON_ARRAY_H_

#include "clrs.h"

class Stack {
 public:
  explicit Stack(int capacity) : nums_(std::vector<int>(capacity)), capacity_(capacity), top_(-1) {}

  bool Empty() { return top_ == -1; }

  bool Full() { return top_ == capacity_ - 1; }

  int Push(int key) {
    if (Full()) {
      std::cerr << "stack overflow" << std::endl;
      return 1;
    }
    nums_[++top_] = key;
    return 0;
  }

  std::tuple<int, int> Pop() {
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

#endif  // CLRS_SRC_PART3_DATA_STRUCTURES_129_STACK_ON_ARRAY_H_
