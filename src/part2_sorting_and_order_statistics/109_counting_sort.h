#ifndef CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_109_COUNTING_SORT_H_
#define CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_109_COUNTING_SORT_H_

#include "clrs.h"

class Solution {
 public:
  std::vector<int> CountingSort(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> b(n);
    std::vector<int> count(k + 1);
    for (int i = 0; i <= k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      count[nums[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
      int x = nums[i];
      b[count[x] - 1] = x;
      count[x]--;
    }
    return b;
  }

  int CountingRange(std::vector<int>& nums, int k, int left, int right) {
    int n = nums.size();
    std::vector<int> count(k + 1);
    for (int i = 0; i < k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      count[nums[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    if (left <= 0) {
      return count[right];
    } else {
      return count[right] - count[left - 1];
    }
  }
};

#endif  // CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_109_COUNTING_SORT_H_
