#include "part2_sorting_and_order_statistics/106_fuzzy_sort.h"

void PrintIntervals(std::vector<Interval*>& intervals) {
  for (auto* item : intervals) {
    printf("[%d, %d]", item->left, item->right);
  }
  printf("\n");
}

Solution solution;

TEST(FuzzySortTest, TestFuzzySort) {
  std::vector<std::vector<int>> keys = {{1, 3}, {1, 2}, {3, 4}, {7, 8}, {5, 8}, {3, 5}};
  int n = (int)keys.size();
  std::vector<Interval*> intervals(n, nullptr);
  for (int i = 0; i < n; ++i) {
    intervals[i] = new Interval(keys[i][0], keys[i][1]);
  }
  PrintIntervals(intervals);
  solution.FuzzySort(intervals, 0, n - 1);
  PrintIntervals(intervals);
}

RUN_TESTS()

/*
 * [1, 3] [1, 2] [3, 4] [7, 8] [5, 8] [3, 5]
 * [1, 3] [1, 2] [3, 4] [3, 5] [5, 8] [7, 8]
 */
