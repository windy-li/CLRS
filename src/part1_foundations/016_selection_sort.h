#ifndef CLRS_SRC_PART1_FOUNDATIONS_016_SELECTION_SORT_H_
#define CLRS_SRC_PART1_FOUNDATIONS_016_SELECTION_SORT_H_

#include "clrs.h"

class Solution {
 public:
  void SelectionSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      int min = i;
      for (int j = i + 1; j < n; ++j) {
        if (nums[j] < nums[min]) {
          min = j;
        }
      }
      if (min != i) {
        std::swap(nums[min], nums[i]);
      }
    }
  }
};

#endif  // CLRS_SRC_PART1_FOUNDATIONS_016_SELECTION_SORT_H_
