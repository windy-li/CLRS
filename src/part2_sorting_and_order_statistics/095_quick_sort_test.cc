#include "part2_sorting_and_order_statistics/095_quick_sort.h"

Solution solution;

TEST(QuickSortTest, TestQuickSort) {
  std::vector<int> nums = RandomIntVector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  int n = nums.size();
  solution.QuickSort(nums, 0, n - 1);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

TEST(QuickSortTest, TestIterativeQuickSort) {
  std::vector<int> nums = RandomIntVector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  int n = nums.size();
  solution.IterativeQuickSort(nums, 0, n - 1);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

TEST(QuickSortTest, TestRandomizedQuickSort) {
  std::vector<int> nums = RandomIntVector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  int n = nums.size();
  solution.RandomizedQuickSort(nums, 0, n - 1);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

RUN_TESTS()
