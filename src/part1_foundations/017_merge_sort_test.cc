#include "part1_foundations/017_merge_sort.h"

#include "clrs.h"
#include "gtest/gtest.h"

Solution solution;

TEST(MergeSortTest, MergeSort) {
  std::vector<int> nums = clrs::Random::Vector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  int n = nums.size();
  solution.MergeSort(nums, 0, n - 1);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

TEST(MergeSortTest, MergeSortBySentinels) {
  std::vector<int> nums = clrs::Random::Vector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  int n = nums.size();
  solution.MergeSortBySentinels(nums, 0, n - 1);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
