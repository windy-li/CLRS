#include "clrs.h"

class Stack {
 public:
  Stack() : q1_(new std::queue<int>()), q2_(new std::queue<int>()) {}

  bool Empty() { return Active()->empty(); }

  void Push(int key) { Active()->push(key); }

  int Pop() {
    if (Empty()) {
      throw std::underflow_error("Stack underflow");
    }
    std::queue<int>* out = Active();
    std::queue<int>* in = Inactive();
    while (true) {
      int tmp = out->front();
      out->pop();
      if (out->empty()) {
        return tmp;
      } else {
        in->push(tmp);
      }
    }
  }

 private:
  std::queue<int>* q1_;
  std::queue<int>* q2_;

  std::queue<int>* Active() { return q1_->empty() ? q2_ : q1_; }

  std::queue<int>* Inactive() { return q1_->empty() ? q1_ : q2_; }
};

int main() {
  auto s = Stack();
  s.Push(15);
  s.Push(6);
  s.Push(2);
  s.Push(9);
  s.Push(17);
  s.Push(3);
  std::cout << s.Pop() << std::endl;
}
