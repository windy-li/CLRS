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

void TestCanDivide() {
  std::vector<int> a = {8, 1, 4, 6, 9, 5};
  int x1 = 7;
  int x2 = 8;
  Solution s;
  std::cout << s.CanDivide(a, x1) << " " << s.CanDivide(a, x2);
}

int main() { TestCanDivide(); }
