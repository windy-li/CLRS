#include "part1_foundations/016_selection_sort.h"

#include "clrs.h"
#include "gtest/gtest.h"

Solution solution;

TEST(SelectionSortTest, SelectionSort) {
  std::vector<int> nums = clrs::Random::Vector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  solution.SelectionSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}
