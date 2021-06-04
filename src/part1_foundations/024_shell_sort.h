#ifndef CLRS_SRC_PART1_FOUNDATIONS_024_SHELL_SORT_H_
#define CLRS_SRC_PART1_FOUNDATIONS_024_SHELL_SORT_H_

#include "clrs.h"

class Solution {
 public:
  void ShellSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
      for (int j = gap; j < n; ++j) {
        int key = nums[j];
        int i = j - gap;
        while (i >= 0 && nums[i] > key) {
          nums[i + gap] = nums[i];
          i -= gap;
        }
        nums[i + gap] = key;
      }
    }
  }
};

#endif  // CLRS_SRC_PART1_FOUNDATIONS_024_SHELL_SORT_H_
