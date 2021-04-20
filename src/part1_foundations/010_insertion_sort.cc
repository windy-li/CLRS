#include "clrs.h"

class Solution {
 public:
  void InsertionSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int j = 1; j < n; ++j) {
      int key = nums[j];
      int i = j - 1;
      while (i >= 0 && nums[i] > key) {
        nums[i + 1] = nums[i];
        i--;
      }
      nums[i + 1] = key;
    }
  }

  void RecursiveInsertionSort(std::vector<int>& nums, int j) {
    if (j >= 1) {
      RecursiveInsertionSort(nums, j - 1);
      int key = nums[j];
      int i = j - 1;
      while (i >= 0 && nums[i] > key) {
        nums[i + 1] = nums[i];
        i--;
      }
      nums[i + 1] = key;
    }
  }

  void NonIncreasingInsertionSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int j = 1; j < n; ++j) {
      int key = nums[j];
      int i = j - 1;
      while (i >= 0 && nums[i] < key) {
        nums[i + 1] = nums[i];
        i--;
      }
      nums[i + 1] = key;
    }
  }

  void BinaryInsertionSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int j = 0; j < n; ++j) {
      int key = nums[j];
      int i = j - 1;
      int insert_position = std::abs(BinarySearch(nums, 0, j, key) + 1);
      while (i >= insert_position) {
        nums[i + 1] = nums[i];
        i--;
      }
      nums[i + 1] = key;
    }
  }

 private:
  int BinarySearch(const std::vector<int>& nums, int left_bound, int right_bound, int key) {
    while (left_bound <= right_bound) {
      int middle = (left_bound + right_bound) / 2;
      if (key == nums[middle]) {
        return nums[middle];
      } else if (key < nums[middle]) {
        right_bound = middle - 1;
      } else {
        left_bound = middle + 1;
      }
    }
    return -(left_bound + 1);
  }
};

Solution s;

void TestInsertionSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  s.InsertionSort(nums);
  clrs::PrintVector(nums);
}

void TestRecursiveInsertionSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  int n = nums.size();
  s.RecursiveInsertionSort(nums, n - 1);
  clrs::PrintVector(nums);
}

void TestNonIncreasingInsertionSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  s.NonIncreasingInsertionSort(nums);
  clrs::PrintVector(nums);
}

void TestBinaryInsertionSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  s.BinaryInsertionSort(nums);
  clrs::PrintVector(nums);
}

int main() {
  TestInsertionSort();
  TestRecursiveInsertionSort();
  TestNonIncreasingInsertionSort();
  TestBinaryInsertionSort();
}
