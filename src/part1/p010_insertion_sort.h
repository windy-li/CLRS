#include "clrs.h"

class Solution {
 public:
  void InsertionSort(std::vector<int> &nums) {
    int n = nums.size();
    for (int j = 1; j < n; j++) {
      int key = nums[j];
      int i = j - 1;
      while (i >= 0 && nums[i] > key) {
        nums[i + 1] = nums[i];
        i--;
      }
      nums[i + 1] = key;
    }
  }

  void RecursiveInsertionSort(std::vector<int> &nums, int j) {
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

  void NonIncreasingInsertionSort(std::vector<int> &nums) {
    int n = nums.size();
    for (int j = 1; j < n; j++) {
      int key = nums[j];
      int i = j - 1;
      while (i >= 0 && nums[i] < key) {
        nums[i + 1] = nums[i];
        i--;
      }
      nums[i + 1] = key;
    }
  }

  void BinaryInsertionSort(std::vector<int> &nums) {
    int n = nums.size();
    for (int j = 0; j < n; j++) {
      int key = nums[j];
      int i = j - 1;
      int location = std::abs(BinarySearch(nums, 0, j, key) + 1);
      while (i >= location) {
        nums[i + 1] = nums[i];
        i--;
      }
      nums[i + 1] = key;
    }
  }

 private:
  int BinarySearch(std::vector<int> &nums, int low, int high, int key) {
    while (low <= high) {
      int mid = (low + high) / 2;
      if (key == nums[mid]) {
        return nums[mid];
      } else if (key < nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -(low + 1);
  }
};
