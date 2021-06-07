#include "clrs.h"

class Deque {
 public:
  explicit Deque(int capacity) : nums_(std::vector<int>(capacity)), capacity_(capacity), head_(-1), tail_(0) {}

  bool Empty() const { return head_ == -1; }

  bool Full() const { return (head_ == tail_ + 1) || (head_ == 0 && tail_ == capacity_ - 1); }

  void PushFront(int key) {
    if (Full()) {
      throw std::overflow_error("deque overflow");
    }
    if (head_ == -1) {
      head_ = 0;
      tail_ = 0;
    } else if (head_ == 0) {
      head_ = capacity_ - 1;
    } else {
      head_--;
    }
    nums_[head_] = key;
  }

  void PushBack(int key) {
    if (Full()) {
      throw std::overflow_error("deque overflow");
    }
    if (head_ == -1) {
      head_ = 0;
      tail_ = 0;
    } else if (tail_ == capacity_ - 1) {
      tail_ = 0;
    } else {
      tail_++;
    }
    nums_[tail_] = key;
  }

  int PopFront() {
    if (Empty()) {
      throw std::underflow_error("deque underflow");
    }
    int res = nums_[head_];
    if (head_ == tail_) {
      head_ = -1;
    } else if (head_ == capacity_ - 1) {
      head_ = 0;
    } else {
      head_++;
    }
    return res;
  }

  int PopBack() {
    if (Empty()) {
      throw std::underflow_error("deque underflow");
    }
    int res = nums_[tail_];
    if (head_ == tail_) {
      head_ = -1;
    } else if (tail_ == 0) {
      tail_ = capacity_ - 1;
    } else {
      tail_--;
    }
    return res;
  }

 private:
  std::vector<int> nums_;
  int capacity_;
  int head_;
  int tail_;
};

void TestDeque() {
  Deque q(5);
  q.PushBack(5);
  q.PushBack(10);
  std::cout << q.PopBack() << std::endl;
  q.PushFront(15);
  std::cout << q.PopFront() << std::endl;
  std::cout << q.PopFront() << std::endl;
}

int main() { TestDeque(); }

// 10
// 15
// 5
