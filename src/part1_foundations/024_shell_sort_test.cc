#include "part1_foundations/024_shell_sort.h"

Solution solution;

TEST(ShellSortTest, ShellSort) {
  std::vector<int> nums = RandomIntVector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  solution.ShellSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

RUN_TESTS()
