#include "clrs.h"

class Queue {
 public:
  Queue() : in_stack_(new std::stack<int>()), out_stack_(new std::stack<int>()) {}

  bool Empty() const { return in_stack_->empty() && out_stack_->empty(); }

  void Push(int key) { in_stack_->push(key); }

  int Pop() {
    if (Empty()) {
      throw std::underflow_error("queue underflow");
    }
    if (out_stack_->empty()) {
      while (!in_stack_->empty()) {
        int x = in_stack_->top();
        in_stack_->pop();
        out_stack_->push(x);
      }
    }
    int ret = out_stack_->top();
    out_stack_->pop();
    return ret;
  }

 private:
  std::stack<int>* in_stack_;
  std::stack<int>* out_stack_;
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
