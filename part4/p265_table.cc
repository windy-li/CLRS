#include "clrs.h"

class Table {
 public:
  Table() {
    num_ = 0;
    size_ = 0;
  }

  int *slots() { return slots_; }

  Table(int capacity) {
    num_ = 0;
    slots_ = new int[capacity];
    this->size_ = capacity;
  }

  void insert(int key) {
    if (size_ == 0) {
      slots_ = new int[1];
      size_ = 1;
    }
    if (num_ == size_) {
      int *tmp = new int[2 * size_];
      for (int i = 0; i < size_; i++) {
        tmp[i] = slots_[i];
      }
      slots_ = tmp;
      size_ *= 2;
    }
    slots_[num_] = key;
    num_++;
  }

 private:
  int num_;
  int *slots_;
  int size_;
};

int main() {
  auto *self = new Table();
  self->insert(8);
  self->insert(3);
  std::cout << self->slots()[0] << " " << self->slots()[1];
}

/*
 * 8
 * 3
 */
