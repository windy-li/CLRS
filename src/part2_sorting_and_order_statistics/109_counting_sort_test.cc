#include "part2_sorting_and_order_statistics/109_counting_sort.h"

Solution solution;

TEST(CountingSortTest, TestCountingSort) {
  int k = 8;
  std::vector<int> nums = RandomIntVector(0, k, 1000);
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  std::vector<int> result = solution.CountingSort(nums, k);
  ASSERT_TRUE(std::is_sorted(result.begin(), result.end()));
}

TEST(CountingSortTest, TestCountingRange) {
  std::vector<int> nums = {2, 5, 3, 0, 2, 3, 0, 3};
  int k = *std::max_element(nums.begin(), nums.end());
  int left = 2;
  int right = 3;
  ASSERT_EQ(solution.CountingRange(nums, k, left, right), 5);
}

RUN_TESTS()
