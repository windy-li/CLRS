#include "clrs.h"

class Solution {
 public:
  bool CanDivide(std::vector<int> &a, int x) {
    int n = a.size();
    std::sort(a.begin(), a.end());
    int i = 0, j = n - 1;
    while (i < j) {
      int sum = a[i] + a[j];
      if (sum == x) {
        return true;
      } else if (sum < x) {
        i++;
      } else {
        j--;
      }
    }
    return false;
  }
};
