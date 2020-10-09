#include "clrs.h"

class Solution {
 public:
  bool CanDivide(std::vector<int>& nums, int x) {
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    int i = 0, j = n - 1;
    while (i < j) {
      int sum = nums[i] + nums[j];
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
