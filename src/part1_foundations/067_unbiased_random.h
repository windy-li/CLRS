#ifndef CLRS_SRC_PART1_FOUNDATIONS_067_UNBIASED_RANDOM_H_
#define CLRS_SRC_PART1_FOUNDATIONS_067_UNBIASED_RANDOM_H_

#include "clrs.h"

class Solution {
 public:
  int UnbiasedRandom() {
    while (true) {
      int x = BiasedRandom();
      int y = BiasedRandom();
      if (x != y) {
        return x;
      }
    }
  }

 private:
  int BiasedRandom() {
    double p = 0.4;
    double r = RandomDouble(0, 1);
    if (r < p) {
      return 0;
    } else {
      return 1;
    }
  }
};

#endif  // CLRS_SRC_PART1_FOUNDATIONS_067_UNBIASED_RANDOM_H_
