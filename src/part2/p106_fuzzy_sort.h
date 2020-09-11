#include "clrs.h"

struct Interval {
  int left;
  int right;

  Interval(int left, int right) : left(left), right(right) {}
};

class Solution {
 public:
  void FuzzySort(std::vector<Interval>& a, int p, int r) {
    if (p < r) {
      std::vector<int> pivots = Partition(a, p, r);
      FuzzySort(a, p, pivots[0] - 1);
      FuzzySort(a, pivots[1] + 1, r);
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
