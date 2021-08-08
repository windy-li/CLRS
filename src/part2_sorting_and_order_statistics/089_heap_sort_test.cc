#include "part2_sorting_and_order_statistics/089_heap_sort.h"

TEST(HeapSortTest, HeapSort) {
  std::vector<int> nums = RandomIntVector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  MaxHeap heap;
  heap.SortHeap(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

RUN_TESTS()
