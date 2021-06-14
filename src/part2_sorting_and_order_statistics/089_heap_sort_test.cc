#include "part2_sorting_and_order_statistics/089_heap_sort.h"

#include <algorithm>

#include "clrs.h"
#include "gtest/gtest.h"

TEST(HeapSortTest, HeapSort) {
  std::vector<int> nums = {5, 2, 4, 6, 1, 3};
  MaxHeap h;
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  h.Sort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}
