#include "clrs.h"

class DiversityHeap {
 public:
  DiversityHeap(int capacity, int d) : nums_(std::vector<int>(capacity)), d_(d), heap_size_(0) {}

  void Insert(int key) {
    heap_size_++;
    nums_[heap_size_ - 1] = std::numeric_limits<int>::min();
    IncreaseKey(heap_size_ - 1, key);
  }

  int ExtractMax() {
    if (heap_size_ < 1) {
      throw std::underflow_error("heap underflow");
    }
    int max = nums_[0];
    nums_[0] = nums_[heap_size_ - 1];
    heap_size_--;
    MaxHeapify(0);
    return max;
  }

 private:
  std::vector<int> nums_;
  int d_;
  int heap_size_;

  void MaxHeapify(int i) {
    while (true) {
      int l = Left(i);
      int r = Right(i);
      int largest = i;
      for (int j = l; j <= r; ++j) {
        if (j < heap_size_ && nums_[j] > nums_[largest]) {
          largest = j;
        }
      }
      if (largest != i) {
        std::swap(nums_[largest], nums_[i]);
        i = largest;
      } else {
        return;
      }
    }
  }

  void IncreaseKey(int i, int new_key) {
    if (new_key < nums_[i]) {
      throw std::invalid_argument("new key should not be lower than current key");
    }
    while (i > 0 && nums_[Parent(i)] < new_key) {
      nums_[i] = nums_[Parent(i)];
      i = Parent(i);
    }
    nums_[i] = new_key;
  }

  int Left(int i) { return d_ * i + 1; }

  int Right(int i) { return d_ * i + d_; }

  int Parent(int i) { return (i - 1) / d_; }

  int Child(int i, int k) { return d_ * i + 1 + k; }
};

void TestDiversityHeap() {
  std::vector<int> keys = {2, 8, 7, 1, 3, 5, 6, 4};
  int n = keys.size();
  DiversityHeap heap(n, 3);
  for (int key : keys) {
    heap.Insert(key);
  }
  for (int i = 0; i < n; ++i) {
    std::cout << heap.ExtractMax() << " ";
  }
}

int main() { TestDiversityHeap(); }

/*
 * 8 7 6 5 4 3 2 1
 */
