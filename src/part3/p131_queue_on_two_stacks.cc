#include "clrs.h"

class Queue {
 public:
  Queue() : in_(new std::stack<int>()), out_(new std::stack<int>()) {}

  bool Empty() { return in_->empty() && out_->empty(); }

  void Push(int key) { in_->push(key); }

  int Pop() {
    if (Empty()) {
      throw std::underflow_error("queue underflow");
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
  std::stack<int>* in_;
  std::stack<int>* out_;
};

int main() {
  Queue q;
  q.Push(15);
  q.Push(6);
  q.Push(9);
  q.Push(8);
  q.Push(4);
  std::cout << q.Pop() << std::endl;
}

/*
 * 15
 */
