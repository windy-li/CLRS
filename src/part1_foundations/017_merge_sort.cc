#include "clrs.h"

class Solution {
 public:
  void MergeSort(std::vector<int>& nums, int left_bound, int right_bound) {
    if (left_bound >= right_bound) {
      return;
    }
    int middle = (left_bound + right_bound) / 2;
    MergeSort(nums, left_bound, middle);
    MergeSort(nums, middle + 1, right_bound);
    Merge(nums, left_bound, middle, right_bound);
  }

  void MergeSortBySentinels(std::vector<int>& nums, int left_bound, int right_bound) {
    if (left_bound >= right_bound) {
      return;
    }
    int middle = (left_bound + right_bound) / 2;
    MergeSortBySentinels(nums, left_bound, middle);
    MergeSortBySentinels(nums, middle + 1, right_bound);
    MergeBySentinels(nums, left_bound, middle, right_bound);
  }

 private:
  void Merge(std::vector<int>& nums, int left_bound, int middle, int right_bound) {
    int n1 = middle - left_bound + 1;
    int n2 = right_bound - middle;
    std::vector<int> left(n1);
    std::vector<int> right(n2);
    for (int i = 0; i < n1; ++i) {
      left[i] = nums[left_bound + i];
    }
    for (int i = 0; i < n2; ++i) {
      right[i] = nums[middle + 1 + i];
    }
    int i = 0, j = 0, k = left_bound;
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

  void MergeBySentinels(std::vector<int>& nums, int left_bound, int middle, int right_bound) {
    int n1 = middle - left_bound + 1;
    int n2 = right_bound - middle;
    std::vector<int> left(n1 + 1);
    std::vector<int> right(n2 + 1);
    for (int i = 0; i < n1; ++i) {
      left[i] = nums[left_bound + i];
    }
    left[n1] = std::numeric_limits<int>::max();
    for (int i = 0; i < n2; ++i) {
      right[i] = nums[middle + 1 + i];
    }
    right[n2] = std::numeric_limits<int>::max();
    int i = 0, j = 0;
    for (int k = left_bound; k <= right_bound; ++k) {
      if (left[i] <= right[j]) {
        nums[k] = left[i++];
      } else {
        nums[k] = right[j++];
      }
    }
  }
};

Solution solution;

void TestMergeSort() {
  std::vector<int> nums = {1, 3, 4, 2};
  int n = nums.size();
  solution.MergeSort(nums, 0, n - 1);
  clrs::PrintVector(nums);
}

void TestMergeSortBySentinels() {
  std::vector<int> nums = {1, 3, 4, 2};
  int n = nums.size();
  solution.MergeSortBySentinels(nums, 0, n - 1);
  clrs::PrintVector(nums);
}

int main() {
  TestMergeSort();
  TestMergeSortBySentinels();
}
