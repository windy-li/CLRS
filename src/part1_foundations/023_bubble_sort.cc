#include "clrs.h"

class Solution {
 public:
  void BubbleSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      for (int j = n - 1; j > i; --j) {
        if (nums[j] < nums[j - 1]) {
          std::swap(nums[j], nums[j - 1]);
        }
      }
    }
  }
};

Solution s;

void TestBubbleSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  s.BubbleSort(nums);
  clrs::PrintVector(nums);
}

int main() { TestBubbleSort(); }
