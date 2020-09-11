#include "p130_queue_by_array.h"

class Stack {
 public:
  explicit Stack(int capacity) : q1_(new Queue(capacity)), q2_(new Queue(capacity)) {}

  Queue *active() { return q1_->Empty() ? q2_ : q1_; }

  Queue *inactive() { return q1_->Empty() ? q1_ : q2_; }

  bool isEmpty() { return active()->Empty(); }

  bool isFull() { return active()->Full(); }

  void push(int key) {
    if (isFull()) {
      throw overflow_error("Stack overflow");
    }
    active()->Push(key);
  }

  int pop() {
    if (isEmpty()) {
      throw underflow_error("Stack underflow");
    }
    Queue *out = active();
    Queue *in = inactive();
    while (true) {
      int tmp = out->Pop();
      if (out->Empty()) {
        return tmp;
      } else {
        in->Push(tmp);
      }
    }
  }

 private:
  Queue *q1_;
  Queue *q2_;
};
