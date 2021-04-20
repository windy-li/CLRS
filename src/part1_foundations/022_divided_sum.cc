#include "clrs.h"

class Solution {
 public:
  bool CanDivide(std::vector<int>& nums, int x) {
    int n = nums.size();
    std::sort(std::begin(nums), std::end(nums));
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

Solution s;

void TestCanDivide() {
  std::vector<int> nums = {8, 1, 4, 6, 9, 5};
  int x1 = 7;
  int x2 = 8;
  std::cout << s.CanDivide(nums, x1) << " " << s.CanDivide(nums, x2);
}

int main() { TestCanDivide(); }
