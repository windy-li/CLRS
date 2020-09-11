#include "clrs.h"

class Solution {
 public:
  vector<int> BinaryIntegerAdding(vector<int> &nums_a, vector<int> &nums_b) {
    int n = nums_a.size();
    vector<int> nums_c(n + 1);
    int bit = 0;
    for (int i = n - 1; i >= 0; i--) {
      int y = nums_a[i] + nums_b[i] + bit;
      nums_c[i + 1] = y % 2;
      if (y >= 2) {
        bit = 1;
      } else {
        bit = 0;
      }
    }
    nums_c[0] = bit;
    return nums_c;
  }
};
