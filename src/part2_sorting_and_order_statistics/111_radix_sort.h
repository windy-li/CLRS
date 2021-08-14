#ifndef CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_111_RADIX_SORT_H_
#define CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_111_RADIX_SORT_H_

#include "clrs.h"

class Solution {
 public:
  void RadixSort(std::vector<int>& nums) {
    // Find the maximum number to know number of digits
    int max = *std::max_element(nums.begin(), nums.end());

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
      CountingSort(nums, exp);
    }
  }

 private:
  void CountingSort(std::vector<int>& nums, int exp) {
    int n = nums.size();
    int k = 9;
    int count[k + 1];
    int output[k + 1];
    for (int i = 0; i <= k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      count[(nums[i] / exp) % 10]++;
    }
    // Change count[i] so that count[i] now contains
    // actual position of this digit in output[]
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
      int x = (nums[i] / exp) % 10;
      output[count[x] - 1] = nums[i];
      count[x]--;
    }
    // Copy the output array to nums[], so that nums[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; ++i) {
      nums[i] = output[i];
    }
  }
};

#endif  // CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_111_RADIX_SORT_H_
