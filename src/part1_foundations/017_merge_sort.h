#ifndef CLRS_SRC_PART1_FOUNDATIONS_017_MERGE_SORT_H_
#define CLRS_SRC_PART1_FOUNDATIONS_017_MERGE_SORT_H_

#include "clrs.h"

class Solution {
 public:
  void MergeSort(std::vector<int>& nums, int p, int r) {
    if (p >= r) {
      return;
    }
    int q = (p + r) / 2;
    MergeSort(nums, p, q);
    MergeSort(nums, q + 1, r);
    Merge(nums, p, q, r);
  }

  void MergeSortBySentinels(std::vector<int>& nums, int p, int r) {
    if (p >= r) {
      return;
    }
    int q = (p + r) / 2;
    MergeSortBySentinels(nums, p, q);
    MergeSortBySentinels(nums, q + 1, r);
    MergeBySentinels(nums, p, q, r);
  }

 private:
  void Merge(std::vector<int>& nums, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    auto left = std::vector<int>(n1);
    auto right = std::vector<int>(n2);
    for (int i = 0; i < n1; ++i) {
      left[i] = nums[p + i];
    }
    for (int i = 0; i < n2; ++i) {
      right[i] = nums[q + 1 + i];
    }
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
      if (left[i] <= right[j]) {
        nums[k++] = left[i++];
      } else {
        nums[k++] = right[j++];
      }
    }
    while (i < n1) {
      nums[k++] = left[i++];
    }
    while (j < n2) {
      nums[k++] = right[j++];
    }
  }

  void MergeBySentinels(std::vector<int>& nums, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    auto left = std::vector<int>(n1 + 1);
    auto right = std::vector<int>(n2 + 1);
    for (int i = 0; i < n1; ++i) {
      left[i] = nums[p + i];
    }
    left[n1] = std::numeric_limits<int>::max();
    for (int i = 0; i < n2; ++i) {
      right[i] = nums[q + 1 + i];
    }
    right[n2] = std::numeric_limits<int>::max();
    int i = 0, j = 0;
    for (int k = p; k <= r; ++k) {
      if (left[i] <= right[j]) {
        nums[k] = left[i++];
      } else {
        nums[k] = right[j++];
      }
    }
  }
};

#endif  // CLRS_SRC_PART1_FOUNDATIONS_017_MERGE_SORT_H_
