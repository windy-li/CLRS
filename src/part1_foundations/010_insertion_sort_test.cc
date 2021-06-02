#include "part1_foundations/010_insertion_sort.h"

#include "clrs.h"
#include "gtest/gtest.h"

Solution solution;

TEST(InsertionSortTest, InsertionSort) {
  std::vector<int> nums = {1, 3, 4, 2};
  solution.InsertionSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

TEST(InsertionSortTest, RecursiveInsertionSort) {
  std::vector<int> nums = {1, 3, 4, 2};
  int n = nums.size();
  solution.RecursiveInsertionSort(nums, n - 1);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

TEST(InsertionSortTest, NonIncreasingInsertionSort) {
  std::vector<int> nums = {1, 3, 4, 2};
  solution.NonIncreasingInsertionSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end(), [](int a, int b) { return b <= a; }));
}

TEST(InsertionSortTest, BinaryInsertionSort) {
  std::vector<int> nums = {1, 3, 4, 2};
  solution.BinaryInsertionSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}
