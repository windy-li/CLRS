#include "clrs.h"

class Solution {
 public:
  void ShellSort(std::vector<int>& nums) {
    int n = nums.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
      for (int j = gap; j < n; ++j) {
        int key = nums[j];
        int i = j - gap;
        while (i >= 0 && nums[i] > key) {
          nums[i + gap] = nums[i];
          i -= gap;
        }
        nums[i + gap] = key;
      }
    }
  }
};

Solution solution;

void TestShellSort() {
  std::vector<int> nums = {2, 3, 8, 6, 1};
  solution.ShellSort(nums);
  clrs::PrintVector(nums);
}

int main() { TestShellSort(); }
