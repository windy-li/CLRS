#ifndef CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_095_QUICK_SORT_H_
#define CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_095_QUICK_SORT_H_

#include "clrs.h"

class Solution {
 public:
  void QuickSort(std::vector<int>& nums, int p, int r) {
    if (p < r) {
      int q = Partition(nums, p, r);
      QuickSort(nums, p, q - 1);
      QuickSort(nums, q + 1, r);
    }
  }

  void IterativeQuickSort(std::vector<int>& nums, int p, int r) {
    int stack[r - p + 1];
    int top = -1;
    stack[++top] = p;
    stack[++top] = r;
    while (top >= 0) {
      r = stack[top--];
      p = stack[top--];
      int pivot = Partition(nums, p, r);
      if (pivot - p > 1) {
        stack[++top] = p;
        stack[++top] = pivot - 1;
      }
      if (r - pivot > 1) {
        stack[++top] = pivot + 1;
        stack[++top] = r;
      }
    }
  }

  void RandomizedQuickSort(std::vector<int>& nums, int p, int r) {
    if (p < r) {
      int q = RandomizedPartition(nums, p, r);
      RandomizedQuickSort(nums, p, q - 1);
      RandomizedQuickSort(nums, q + 1, r);
    }
  }

  void HoareQuickSort(std::vector<int>& nums, int p, int r) {
    if (p < r) {
      int q = HoarePartition(nums, p, r);
      HoareQuickSort(nums, p, q);
      HoareQuickSort(nums, q + 1, r);
    }
  }

  void TailRecursiveQuickSort(std::vector<int>& nums, int p, int r) {
    while (p < r) {
      int q = Partition(nums, p, r);
      TailRecursiveQuickSort(nums, p, q - 1);
      p = q + 1;
    }
  }

  void ModifiedTailRecursiveQuickSort(std::vector<int>& nums, int p, int r) {
    while (p < r) {
      int q = Partition(nums, p, r);
      if (q < (r - p) / 2) {
        ModifiedTailRecursiveQuickSort(nums, p, q - 1);
        p = q + 1;
      } else {
        ModifiedTailRecursiveQuickSort(nums, q + 1, r);
        r = q - 1;
      }
    }
  }

  void MedianOfThreeQuickSort(std::vector<int>& nums, int p, int r) {
    if (p < r) {
      int q = MedianOfThreePartition(nums, p, r);
      MedianOfThreeQuickSort(nums, p, q - 1);
      MedianOfThreeQuickSort(nums, q + 1, r);
    }
  }

  void ThreeWayQuickSort(std::vector<int>& nums, int p, int r) {
    if (p < r) {
      std::vector<int> pivots = ThreeWayPartition(nums, p, r);
      ThreeWayQuickSort(nums, p, pivots[0]);
      ThreeWayQuickSort(nums, pivots[1], r);
    }
  }

 private:
  int Partition(std::vector<int>& nums, int p, int r) {
    int i = p - 1;
    for (int j = p; j < r; ++j) {
      if (nums[j] <= nums[r]) {
        i++;
        std::swap(nums[i], nums[j]);
      }
    }
    std::swap(nums[i + 1], nums[r]);
    return i + 1;
  }

  int RandomizedPartition(std::vector<int>& nums, int p, int r) {
    int i = RandomInt(p, r);
    std::swap(nums[i], nums[r]);
    return Partition(nums, p, r);
  }

  int HoarePartition(std::vector<int>& nums, int p, int r) {
    int x = nums[p];
    int i = p - 1;
    int j = r + 1;
    while (true) {
      do {
        i++;
      } while (nums[i] < x);
      do {
        j--;
      } while (nums[j] > x);
      if (i < j) {
        std::swap(nums[i], nums[j]);
      } else {
        return j;
      }
    }
  }

  int MedianOfThreePartition(std::vector<int>& nums, int p, int r) {
    int a = p + RandomInt(0, r - p);
    int b = p + RandomInt(0, r - p);
    int c = p + RandomInt(0, r - p);
    int m = MedianOfThree(nums, a, b, c);
    std::swap(nums[m], nums[r]);
    return Partition(nums, p, r);
  }

  int MedianOfThree(std::vector<int>& nums, int i, int j, int k) {
    if (nums[i] < nums[j]) {
      if (nums[j] < nums[k]) {
        return j;
      } else if (nums[i] < nums[k]) {
        return k;
      } else {
        return i;
      }
    } else {
      if (nums[j] > nums[k]) {
        return j;
      } else if (nums[i] > nums[k]) {
        return k;
      } else {
        return i;
      }
    }
  }

  std::vector<int> ThreeWayPartition(std::vector<int>& nums, int p, int r) {
    int lt = p - 1;
    int gt = r;
    int i = p;
    int pivot = nums[r];
    while (i < gt) {
      if (nums[i] < pivot) {
        lt++;
        std::swap(nums[i], nums[lt]);
        i++;
      } else if (nums[i] > pivot) {
        gt--;
        std::swap(nums[i], nums[gt]);
      } else {
        i++;
      }
    }
    std::swap(nums[r], nums[gt]);
    return std::vector<int>{lt, gt + 1};
  }
};

#endif  // CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_095_QUICK_SORT_H_
