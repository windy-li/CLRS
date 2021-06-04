#include "part1_foundations/070_permute_by_sorting.h"

Solution solution;

TEST(PermuteBySortingTest, PermuteBySorting) {
  int n = 10;
  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    nums[i] = i;
  }
  solution.PermuteBySorting(nums);
  clrs::PrintVector(nums);
}
