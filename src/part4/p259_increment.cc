#include "../clrs.h"

class Solution {
 public:
  void Increment(std::vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while (i < n - 1 && nums[n - 1 - i] == 1) {
      nums[n - 1 - i] = 0;
      i++;
    }
    if (i < n) {
      nums[n - 1 - i] = 1;
    }
  }
};

int main() {
  std::vector<int> nums(8);
  Solution s;
  for (int i = 1; i <= 16; ++i) {
    s.Increment(nums);
  }
}
