#include "clrs.h"

class MaxHeap {
 public:
  MaxHeap() : size_(0) {}

  void Sort(std::vector<int>& nums) {
    BuildMaxHeap(nums);
    int n = nums.size();
    for (int i = n - 1; i > 0; i--) {
      std::swap(nums[0], nums[i]);
      size_--;
      IterativeMaxHeapify(nums, 0);
    }
  }

 private:
  int size_;

  void BuildMaxHeap(std::vector<int>& a) {
    int n = a.size();
    size_ = n;
    for (int i = size_ / 2 - 1; i >= 0; i--) {
      IterativeMaxHeapify(a, i);
    }
  }

  void RecursiveMaxHeapify(std::vector<int>& a, int i) {
    int l = Left(i);
    int r = Right(i);
    int largest = i;
    if (l < size_ && a[l] > a[largest]) {
      largest = l;
    }
    if (r < size_ && a[r] > a[largest]) {
      largest = r;
    }
    if (largest != i) {
      std::swap(a[i], a[largest]);
      RecursiveMaxHeapify(a, largest);
    }
  }

  void IterativeMaxHeapify(std::vector<int>& a, int i) {
    while (true) {
      int l = Left(i);
      int r = Right(i);
      int largest = i;
      if (l < size_ && a[l] > a[largest]) {
        largest = l;
      }
      if (r < size_ && a[r] > a[largest]) {
        largest = r;
      }
      if (largest != i) {
        std::swap(a[i], a[largest]);
        i = largest;
      } else {
        return;
      }
    }
  }

  int Left(int i) { return 2 * i + 1; }

  int Right(int i) { return 2 * i + 2; }
};

int main() {
  std::vector<int> nums = {5, 2, 4, 6, 1, 3};
  MaxHeap h;
  h.Sort(nums);
  clrs::PrintVector(nums);
}

/*
 * 1 2 3 4 5 6
 */
