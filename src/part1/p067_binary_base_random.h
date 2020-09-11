#include "clrs.h"

class Solution {
 public:
  int BinaryBaseRandom(int a, int b) {
    int n = std::ceil(std::log(2) / std::log(b - a + 1));
    std::vector<int> arr(n);
    while (true) {
      for (int i = 0; i < n; i++) {
        arr[i] = clrs::RandomInt(0, 2);
      }
      int val = a;
      for (int i = n - 1; i >= 0; i--) {
        val += arr[i] * (int)(std::pow(2, n - 1 - i));
      }
      if (val <= b) {
        return val;
      }
    }
  }
};
