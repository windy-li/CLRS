#ifndef CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_106_FUZZY_SORT_H_
#define CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_106_FUZZY_SORT_H_

#include "clrs.h"

struct Interval {
  int left;
  int right;

  Interval(int left, int right) : left(left), right(right) {}
};

class Solution {
 public:
  void FuzzySort(std::vector<Interval*>& intervals, int p, int r) {
    if (p < r) {
      std::vector<int> pivots = Partition(intervals, p, r);
      FuzzySort(intervals, p, pivots[0] - 1);
      FuzzySort(intervals, pivots[1] + 1, r);
    }
  }

 private:
  static std::vector<int> Partition(std::vector<Interval*>& intervals, int p, int r) {
    auto pivot = Interval(intervals[r]->left, intervals[r]->right);
    int i = p;
    int j = p;
    int k = r;
    while (j < k) {
      if (intervals[j]->right <= pivot.left) {
        std::swap(intervals[i], intervals[j]);
        i++;
        j++;
      } else if (intervals[j]->left >= pivot.right) {
        std::swap(intervals[j], intervals[k]);
        k--;
      } else {
        pivot.left = std::max(intervals[j]->left, pivot.left);
        pivot.right = std::min(intervals[j]->right, pivot.right);
        j++;
      }
    }
    return std::vector<int>{i, k};
  }
};

#endif  // CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_106_FUZZY_SORT_H_
