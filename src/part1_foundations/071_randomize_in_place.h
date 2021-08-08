#ifndef CLRS_SRC_PART1_FOUNDATIONS_071_RANDOMIZE_IN_PLACE_H_
#define CLRS_SRC_PART1_FOUNDATIONS_071_RANDOMIZE_IN_PLACE_H_

#include "clrs.h"

class Solution {
 public:
  void RandomizeInPlace(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      std::swap(nums[i], nums[RandomInt(i, n)]);
    }
  }
};

#endif  // CLRS_SRC_PART1_FOUNDATIONS_071_RANDOMIZE_IN_PLACE_H_
