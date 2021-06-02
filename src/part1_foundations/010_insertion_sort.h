#ifndef CLRS_SRC_PART1_FOUNDATIONS_010_INSERTION_SORT_H_
#define CLRS_SRC_PART1_FOUNDATIONS_010_INSERTION_SORT_H_

#include "clrs.h"

class Solution {
 public:
  void InsertionSort(std::vector<int>& nums) {
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

  void BinaryInsertionSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int j = 0; j < n; j++) {
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
  int BinarySearch(const std::vector<int>& nums, int left, int right, int key) {
    while (left <= right) {
      int middle = (left + right) / 2;
      if (key == nums[middle]) {
        return middle;
      } else if (key < nums[middle]) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }
    return -(left + 1);
  }
};

#endif  // CLRS_SRC_PART1_FOUNDATIONS_010_INSERTION_SORT_H_
