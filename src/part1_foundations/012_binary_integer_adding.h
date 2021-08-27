#ifndef CLRS_SRC_PART1_FOUNDATIONS_012_BINARY_INTEGER_ADDING_H_
#define CLRS_SRC_PART1_FOUNDATIONS_012_BINARY_INTEGER_ADDING_H_

#include "clrs.h"

class Solution {
 public:
  std::vector<int> BinaryIntegerAdding(const std::vector<int>& a, const std::vector<int>& b) {
    int n = a.size();
    auto c = std::vector<int>(n + 1);
    int bit = 0;
    for (int i = n - 1; i >= 0; --i) {
      int y = a[i] + b[i] + bit;
      c[i + 1] = y % 2;
      if (y >= 2) {
        bit = 1;
      } else {
        bit = 0;
      }
    }
    c[0] = bit;
    return c;
  }
};

#endif  // CLRS_SRC_PART1_FOUNDATIONS_012_BINARY_INTEGER_ADDING_H_
