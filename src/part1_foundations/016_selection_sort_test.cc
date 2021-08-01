#include "part1_foundations/016_selection_sort.h"

Solution solution;

TEST(SelectionSortTest, SelectionSort) {
  std::vector<int> nums = clrs::DefaultRandomVector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  solution.SelectionSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}
