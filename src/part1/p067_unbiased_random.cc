#include "../clrs.h"

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
    double r = clrs::Random();
    if (r < p) {
      return 0;
    } else {
      return 1;
    }
  }
};
