#include "part1_foundations/022_binary_search.h"

Solution solution;

TEST(BinarySearchTest, BinarySearch) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};
  int key1 = 2;
  int key2 = 7;
  ASSERT_EQ(solution.BinarySearch(nums, key1), 1);
  ASSERT_EQ(solution.BinarySearch(nums, key2), -7);
}

TEST(BinarySearchTest, RecursiveBinarySearch) {
  std::vector<int> nums = {1, 2, 3, 4, 5, 6};
  int n = nums.size();
  int key1 = 2;
  int key2 = 7;
  ASSERT_EQ(solution.RecursiveBinarySearch(nums, key1, 0, n - 1), 1);
  ASSERT_EQ(solution.RecursiveBinarySearch(nums, key2, 0, n - 1), -7);
}

RUN_TESTS()
