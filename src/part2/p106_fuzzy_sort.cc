#include "p106_fuzzy_sort.h"

void PrintIntervals(std::vector<Interval>& a, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << "[" << a[i].left << ", " << a[i].right << "] ";
  }
  std::cout << std::endl;
}

void TestFuzzySort() {
  std::vector<std::vector<int>> keys = {{1, 3}, {1, 2}, {3, 4}, {7, 8}, {5, 8}, {3, 5}};
  int n = keys.size();
  std::vector<Interval> intervals(n, Interval(0, 0));
  for (int i = 0; i < n; i++) {
    intervals[i] = Interval(keys[i][0], keys[i][1]);
  }
  Solution s;
  PrintIntervals(intervals, n);
  s.FuzzySort(intervals, 0, n - 1);
  PrintIntervals(intervals, n);
}

int main() { TestFuzzySort(); }

/*
 * [1, 3] [1, 2] [3, 4] [7, 8] [5, 8] [3, 5]
 * [1, 3] [1, 2] [3, 4] [3, 5] [5, 8] [7, 8]
 */
