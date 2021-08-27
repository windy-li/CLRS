#ifndef CLRS_SRC_PART1_FOUNDATIONS_024_INVERSIONS_H_
#define CLRS_SRC_PART1_FOUNDATIONS_024_INVERSIONS_H_

#include "clrs.h"

class Solution {
 public:
  int Inversions(std::vector<int>& nums, int p, int r) {
    if (p >= r) {
      return 0;
    }
    int q = (p + r) / 2;
    return Inversions(nums, p, q) + Inversions(nums, q + 1, r) + Merge(nums, p, q, r);
  }

 private:
  int Merge(std::vector<int>& nums, int p, int q, int r) {
    int count = 0;
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
        count += n1 - i;
        for (int s = i; s < n1; ++s) {
          printf("%d %d \n", left[s], right[j]);
        }
        nums[k++] = right[j++];
      }
    }
    while (i < n1) {
      nums[k++] = left[i++];
    }
    while (j < n2) {
      nums[k++] = right[j++];
    }
    return count;
  }
};

#endif  // CLRS_SRC_PART1_FOUNDATIONS_024_INVERSIONS_H_
