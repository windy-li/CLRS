#include "clrs.h"

class Solution {
 public:
  void MergeSort(std::vector<int>& nums, int p, int r) {
    if (p < r) {
      int q = (p + r) / 2;
      MergeSort(nums, p, q);
      MergeSort(nums, q + 1, r);
      Merge(nums, p, q, r);
    }
  }

  void MergeSortBySentinels(std::vector<int>& nums, int p, int r) {
    if (p < r) {
      int q = (p + r) / 2;
      MergeSortBySentinels(nums, p, q);
      MergeSortBySentinels(nums, q + 1, r);
      MergeBySentinels(nums, p, q, r);
    }
  }

 private:
  void Merge(std::vector<int>& nums, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> left(n1);
    std::vector<int> right(n2);
    for (int i = 0; i < n1; i++) {
      left[i] = nums[p + i];
    }
    for (int i = 0; i < n2; i++) {
      right[i] = nums[q + 1 + i];
    }
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
      if (left[i] <= right[j]) {
        nums[k++] = left[i++];
      } else {
        nums[k++] = right[j++];
      }
    }
    while (i < n1) {
      nums[k++] = left[i++];
    }
    while (j < n2) {
      nums[k++] = right[j++];
    }
  }

  void MergeBySentinels(std::vector<int>& a, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> left(n1 + 1);
    std::vector<int> right(n2 + 1);
    for (int i = 0; i < n1; i++) {
      left[i] = a[p + i];
    }
    left[n1] = INT_MAX;
    for (int i = 0; i < n2; i++) {
      right[i] = a[q + 1 + i];
    }
    right[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
      if (left[i] <= right[j]) {
        a[k] = left[i++];
      } else {
        a[k] = right[j++];
      }
    }
  }
};
