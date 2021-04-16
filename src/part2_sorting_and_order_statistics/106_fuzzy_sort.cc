#include "clrs.h"

struct Interval {
  int left;
  int right;

  Interval(int left, int right) : left(left), right(right) {}
};

class Solution {
 public:
  void FuzzySort(std::vector<Interval>& nums, int p, int r) {
    if (p < r) {
      std::vector<int> pivots = Partition(nums, p, r);
      FuzzySort(nums, p, pivots[0] - 1);
      FuzzySort(nums, pivots[1] + 1, r);
    }
  }

 private:
  std::vector<int> Partition(std::vector<Interval>& a, int p, int r) {
    Interval pivot(a[r].left, a[r].right);
    int i = p;
    int j = p;
    int k = r;
    while (j < k) {
      if (a[j].right <= pivot.left) {
        std::swap(a[i], a[j]);
        i++;
        j++;
      } else if (a[j].left >= pivot.right) {
        std::swap(a[j], a[k]);
        k--;
      } else {
        pivot.left = std::max(a[j].left, pivot.left);
        pivot.right = std::min(a[j].right, pivot.right);
        j++;
      }
    }
    return std::vector<int>{i, k};
  }
};

void PrintIntervals(std::vector<Interval>& a, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << "[" << a[i].left << ", " << a[i].right << "] ";
  }
  std::cout << std::endl;
}

void TestFuzzySort() {
  std::vector<std::vector<int>> keys = {{1, 3}, {1, 2}, {3, 4}, {7, 8}, {5, 8}, {3, 5}};
  int n = keys.size();
  std::vector<Interval> intervals(n, Interval(0, 0));
  for (int i = 0; i < n; ++i) {
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
