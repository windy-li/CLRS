#include "clrs.h"

class Table {
 public:
  Table() : num_(0), size_(0) {}

  Table(int capacity) : num_(0), slots_(std::vector<int>(capacity)), size_(capacity) {}

  std::vector<int> slots() { return slots_; }

  void Insert(int key) {
    if (size_ == 0) {
      slots_ = std::vector<int>(1);
      size_ = 1;
    }
    if (num_ == size_) {
      std::vector<int> tmp(2 * size_);
      for (int i = 0; i < size_; ++i) {
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
  std::vector<int> slots_;
  int size_;
};

void TestTable() {
  auto* table = new Table();
  table->Insert(8);
  table->Insert(3);
  std::cout << table->slots()[0] << " " << table->slots()[1];
}

int main() { TestTable(); }

/*
 * 8
 * 3
 */
