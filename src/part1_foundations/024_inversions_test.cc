#include "part1_foundations/024_inversions.h"

Solution solution;

TEST(InversionsTest, Inversions) {
  std::vector<int> nums = {2, 3, 8, 6, 1};
  int n = nums.size();
  ASSERT_EQ(solution.Inversions(nums, 0, n - 1), 5);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}
