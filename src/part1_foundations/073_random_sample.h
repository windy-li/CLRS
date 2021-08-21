#ifndef CLRS_SRC_PART1_FOUNDATIONS_073_RANDOM_SAMPLE_H_
#define CLRS_SRC_PART1_FOUNDATIONS_073_RANDOM_SAMPLE_H_

#include "clrs.h"

class Solution {
 public:
  std::list<int> RandomSample(int m, int n) {
    if (m == 0) {
      return {};
    }
    std::list<int> s = RandomSample(m - 1, n - 1);
    int i = RandomInt(0, n + 1);
    if (!s.empty()) {
      if (std::find(s.begin(), s.end(), i) != s.end()) {
        s.push_back(n);
      } else {
        s.push_back(i);
      }
    }
    return s;
  }

  std::vector<int> ReservoirSample(std::vector<int>& nums, int m) {
    std::vector<int> s(m);
    for (int i = 0; i < nums.size(); ++i) {
      if (i < m) {
        s[i] = nums[i];
      } else {
        int tmp = static_cast<int>(RandomDouble(0, 1) * (i + 1));
        if (tmp < m) {
          s[tmp] = nums[i];
        }
      }
    }
    return s;
  }
};

#endif  // CLRS_SRC_PART1_FOUNDATIONS_073_RANDOM_SAMPLE_H_
