#ifndef CLRS_SRC_PART1_FOUNDATIONS_023_HORNER_RULE_H_
#define CLRS_SRC_PART1_FOUNDATIONS_023_HORNER_RULE_H_

#include "clrs.h"

class Solution {
 public:
  int HornerRule(std::vector<int>& nums, int x) {
    int n = nums.size();
    int y = 0;
    for (int i = n - 1; i >= 0; --i) {
      y = nums[i] + x * y;
    }
    return y;
  }

  int NaivePolynomialEvaluation(std::vector<int>& nums, int x) {
    int n = nums.size();
    int y[n];
    y[0] = 1;
    for (int i = 1; i < n; ++i) {
      y[i] = 1;
      for (int j = 0; j < i; ++j) {
        y[i] *= x;
      }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i] * y[i];
    }
    return sum;
  }
};

#endif  // CLRS_SRC_PART1_FOUNDATIONS_023_HORNER_RULE_H_
