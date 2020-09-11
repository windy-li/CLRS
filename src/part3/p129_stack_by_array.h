#include "clrs.h"

class Stack {
 public:
  explicit Stack(int capacity) : nums_(vector<int>(capacity)), capacity_(capacity), top_(-1) {}

  bool Empty() { return top_ == -1; }

  bool Full() { return top_ == capacity_ - 1; }

  error Push(int key) {
    if (Full()) {
      cerr << "stack overflow" << endl;
      return 1;
    }
    nums_[++top_] = key;
    return 0;
  }

  tuple<int, error> Pop() {
    if (Empty()) {
      cerr << "stack underflow" << endl;
      return {0, 1};
    }
    return {nums_[top_--], 0};
  }

 private:
  vector<int> nums_;
  int capacity_;
  int top_;
};
