#include "clrs.h"

class MaxHeap {
 public:
  MaxHeap() : heap_size_(0) {}

  void Sort(std::vector<int>& nums) {
    BuildMaxHeap(nums);
    int n = nums.size();
    for (int i = n - 1; i > 0; --i) {
      std::swap(nums[0], nums[i]);
      heap_size_--;
      IterativeMaxHeapify(nums, 0);
    }
  }

 private:
  int heap_size_;

  void BuildMaxHeap(std::vector<int>& nums) {
    int n = nums.size();
    heap_size_ = n;
    for (int i = heap_size_ / 2 - 1; i >= 0; --i) {
      IterativeMaxHeapify(nums, i);
    }
  }

  void RecursiveMaxHeapify(std::vector<int>& nums, int i) {
    int l = Left(i);
    int r = Right(i);
    int largest = i;
    if (l < heap_size_ && nums[l] > nums[largest]) {
      largest = l;
    }
    if (r < heap_size_ && nums[r] > nums[largest]) {
      largest = r;
    }
    if (largest != i) {
      std::swap(nums[i], nums[largest]);
      RecursiveMaxHeapify(nums, largest);
    }
  }

  void IterativeMaxHeapify(std::vector<int>& nums, int i) {
    while (true) {
      int l = Left(i);
      int r = Right(i);
      int largest = i;
      if (l < heap_size_ && nums[l] > nums[largest]) {
        largest = l;
      }
      if (r < heap_size_ && nums[r] > nums[largest]) {
        largest = r;
      }
      if (largest != i) {
        std::swap(nums[i], nums[largest]);
        i = largest;
      } else {
        return;
      }
    }
  }

  int Left(int i) { return 2 * i + 1; }

  int Right(int i) { return 2 * i + 2; }
};

void TestHeapSort() {
  std::vector<int> nums = {5, 2, 4, 6, 1, 3};
  MaxHeap h;
  h.Sort(nums);
  clrs::PrintVector(nums);
}

int main() { TestHeapSort(); }

/*
 * 1 2 3 4 5 6
 */
