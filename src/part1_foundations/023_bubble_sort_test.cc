#include "part1_foundations/023_bubble_sort.h"

Solution solution;

TEST(BubbleSortTest, BubbleSort) {
  std::vector<int> nums = RandomIntVector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  solution.BubbleSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

RUN_TESTS()
