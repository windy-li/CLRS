#include "clrs.h"

class Solution {
 public:
  int Minimum(std::vector<int>& nums) {
    int min = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      if (min > nums[i]) {
        min = nums[i];
      }
    }
    return min;
  }

  std::tuple<int, int> MinimumAndMaximum(std::vector<int>& nums) {
    int n = nums.size();
    int min, max, start;
    if (n % 2 == 1) {
      min = max = nums[0];
      start = 1;
    } else {
      if (nums[0] < nums[1]) {
        min = nums[0];
        max = nums[1];
      } else {
        min = nums[1];
        max = nums[0];
      }
      start = 2;
    }
    for (int i = start; i < n; i += 2) {
      if (nums[i] < nums[i + 1]) {
        if (min > nums[i]) {
          min = nums[i];
        }
        if (max < nums[i + 1]) {
          max = nums[i + 1];
        }
      } else {
        if (min > nums[i + 1]) {
          min = nums[i + 1];
        }
        if (max < nums[i]) {
          max = nums[i];
        }
      }
    }
    return {min, max};
  }
};

void TestMinimum() {
  auto nums = std::vector<int>{2, 8, 7, 1, 3, 5, 6, 4};
  auto s = Solution();
  std::cout << "min = " << s.Minimum(nums) << std::endl;
}

void TestMinimumAndMaximum() {
  auto nums = std::vector<int>{2, 8, 7, 1, 3, 5, 6, 4};
  auto s = Solution();
  auto [min, max] = s.MinimumAndMaximum(nums);
  std::cout << "min = " << min << ", max = " << max << std::endl;
}

int main() {
  TestMinimum();
  TestMinimumAndMaximum();
}
