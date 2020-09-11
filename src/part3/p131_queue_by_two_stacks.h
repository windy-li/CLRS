#include "clrs.h"

class Queue {
 public:
  Queue() : in_(new stack<int>()), out_(new stack<int>()) {}

  bool Empty() { return in_->empty() && out_->empty(); }

  void Push(int key) { in_->push(key); }

  int Pop() {
    if (Empty()) {
      throw underflow_error("queue underflow");
    }
    if (out_->empty()) {
      while (!in_->empty()) {
        int x = in_->top();
        in_->pop();
        out_->push(x);
      }
    }
    int ret = out_->top();
    out_->pop();
    return ret;
  }

 private:
  stack<int> *in_;
  stack<int> *out_;
};
