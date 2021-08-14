#include "part2_sorting_and_order_statistics/111_radix_sort.h"

Solution solution;

TEST(RadixSortTest, TestRadixSort) {
  std::vector<int> nums = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  solution.RadixSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

RUN_TESTS()

/*
 * 81 22 73 93 43 14 55 65 28 39
 * 14 22 28 39 43 55 65 73 81 93
 * 14 22 28 39 43 55 65 73 81 93
 */
