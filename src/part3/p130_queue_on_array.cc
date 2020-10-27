#include "../clrs.h"

class Queue {
 public:
  explicit Queue(int capacity)
      : nums_(std::vector<int>(capacity)), capacity_(capacity), head_(0), tail_(0) {}

  bool Empty() { return head_ == tail_; }

  bool Full() { return (head_ == tail_ + 1) || (head_ == 0 && tail_ == capacity_ - 1); }

  void Push(int key) {
    if (Full()) {
      throw std::overflow_error("queue overflow");
    }
    nums_[tail_] = key;
    if (tail_ == capacity_ - 1) {
      tail_ = 0;
    } else {
      tail_++;
    }
  }

  int Pop() {
    if (Empty()) {
      throw std::underflow_error("queue underflow");
    }
    int ret = nums_[head_];
    if (head_ == capacity_ - 1) {
      head_ = 0;
    } else {
      head_++;
    }
    return ret;
  }

 private:
  std::vector<int> nums_;
  int capacity_;
  int head_;
  int tail_;
};

int main() {
  Queue q(12);
  q.Push(15);
  q.Push(6);
  q.Push(9);
  q.Push(8);
  q.Push(4);
  std::cout << q.Pop();
}
