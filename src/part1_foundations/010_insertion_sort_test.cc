#include "part1_foundations/010_insertion_sort.h"

#include "clrs.h"
#include "gtest/gtest.h"

Solution solution;

TEST(InsertionSortTest1, TestInsertionSort) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
  std::vector<int> nums = {1, 3, 4, 2};
  solution.InsertionSort(nums);
  clrs::PrintVector(nums);
}

void TestInsertionSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  solution.InsertionSort(nums);
  clrs::PrintVector(nums);
}

void TestRecursiveInsertionSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  int n = nums.size();
  solution.RecursiveInsertionSort(nums, n - 1);
  clrs::PrintVector(nums);
}

void TestNonIncreasingInsertionSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  solution.NonIncreasingInsertionSort(nums);
  clrs::PrintVector(nums);
}

void TestBinaryInsertionSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  solution.BinaryInsertionSort(nums);
  clrs::PrintVector(nums);
}
