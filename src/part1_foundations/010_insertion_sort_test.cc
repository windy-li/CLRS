#include "part1_foundations/010_insertion_sort.h"

#include "clrs.h"

Solution solution;

TEST(InsertionSortTest, InsertionSort) {
  std::vector<int> nums = clrs::Random::Vector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  solution.InsertionSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

TEST(InsertionSortTest, RecursiveInsertionSort) {
  std::vector<int> nums = clrs::Random::Vector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  int n = nums.size();
  solution.RecursiveInsertionSort(nums, n - 1);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

TEST(InsertionSortTest, NonIncreasingInsertionSort) {
  std::vector<int> nums = clrs::Random::Vector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end(), [](int a, int b) { return b < a; }));
  solution.NonIncreasingInsertionSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end(), [](int a, int b) { return b < a; }));
}

TEST(InsertionSortTest, BinaryInsertionSort) {
  std::vector<int> nums = clrs::Random::Vector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  solution.BinaryInsertionSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
