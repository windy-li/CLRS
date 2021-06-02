#include "clrs.h"

class Solution {
 public:
  void RandomizeInPlace(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      std::swap(nums[i], nums[clrs::RandomInt(i, n)]);
    }
  }
};

Solution solution;

void TestRandomizeInPlace() {
  int n = 10;
  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    nums[i] = i;
  }
  solution.RandomizeInPlace(nums);
  clrs::PrintVector(nums);
}

int main() { TestRandomizeInPlace(); }
