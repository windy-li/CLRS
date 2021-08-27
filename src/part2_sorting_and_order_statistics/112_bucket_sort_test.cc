#include "part2_sorting_and_order_statistics/112_bucket_sort.h"

auto solution = Solution();

TEST(BucketSortTest, TestBucketSort) {
  std::vector<double> nums = RandomDoubleVector();
  ASSERT_FALSE(std::is_sorted(nums.begin(), nums.end()));
  solution.BucketSort(nums);
  ASSERT_TRUE(std::is_sorted(nums.begin(), nums.end()));
}

RUN_TESTS()

/*
 * 0.12 0.17 0.21 0.26 0.39 0.68 0.72 0.78 0.94
 */
