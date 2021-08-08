#ifndef CLRS_SRC_PART1_FOUNDATIONS_067_BINARY_BASE_RANDOM_H_
#define CLRS_SRC_PART1_FOUNDATIONS_067_BINARY_BASE_RANDOM_H_

#include "clrs.h"

class Solution {
 public:
  int BinaryBaseRandom(int a, int b) {
    int n = std::ceil(std::log(2) / std::log(b - a + 1));
    std::vector<int> nums(n);
    while (true) {
      for (int i = 0; i < n; ++i) {
        nums[i] = RandomInt(0, 2);
      }
      int val = a;
      for (int i = n - 1; i >= 0; --i) {
        val += nums[i] * (int)(std::pow(2, n - 1 - i));
      }
      if (val <= b) {
        return val;
      }
    }
  }
};

#endif  // CLRS_SRC_PART1_FOUNDATIONS_067_BINARY_BASE_RANDOM_H_
