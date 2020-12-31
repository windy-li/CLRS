#include "clrs.h"

class MaxPriorityQueue {
 public:
  explicit MaxPriorityQueue(int capacity)
      : heap_size_(0), capacity_(capacity), items_(std::vector<int>(capacity)) {}

  void Insert(int key) {
    if (heap_size_ == capacity_) {
      throw std::overflow_error("heap overflow");
    }
    heap_size_++;
    items_[heap_size_ - 1] = INT_MIN;
    IncreaseKey(heap_size_ - 1, key);
  }

  int ExtractMax() {
    if (heap_size_ == 0) {
      throw std::underflow_error("heap overflow");
    }
    int max = items_[0];
    items_[0] = items_[heap_size_ - 1];
    heap_size_--;
    MaxHeapify(0);
    return max;
  }

  void Remove(int i) {
    IncreaseKey(i, INT_MAX);
    items_[0] = items_[heap_size_ - 1];
    heap_size_--;
    MaxHeapify(0);
  }

  int Maximum() { return items_[0]; }

 private:
  std::vector<int> items_;
  int heap_size_;
  int capacity_;

  void IncreaseKey(int i, int key) {
    if (key < items_[i]) {
      throw std::invalid_argument("new key can not be less than current key");
    }
    while (i > 0 && items_[Parent(i)] < key) {
      items_[i] = items_[Parent(i)];
      i = Parent(i);
    }
    items_[i] = key;
  }

  void MaxHeapify(int i) {
    int l = Left(i);
    int r = Right(i);
    int largest = i;
    if (l < heap_size_ && items_[l] > items_[largest]) {
      largest = l;
    }
    if (r < heap_size_ && items_[r] > items_[largest]) {
      largest = r;
    }
    if (largest != i) {
      std::swap(items_[largest], items_[i]);
      MaxHeapify(largest);
    }
  }

  int Left(int i) { return 2 * i + 1; }

  int Right(int i) { return 2 * i + 2; }

  int Parent(int i) { return (i - 1) / 2; }
};

int main() {
  std::vector<int> keys = {5, 2, 4, 6, 1, 3};
  int n = keys.size();
  MaxPriorityQueue q(n);
  for (int key : keys) {
    q.Insert(key);
  }
  for (int i = 0; i < n; ++i) {
    std::cout << q.ExtractMax() << " ";
  }
}

/*
 * 6 5 4 3 2 1
 */
