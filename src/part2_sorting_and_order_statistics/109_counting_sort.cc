#include "clrs.h"

class Solution {
 public:
  std::vector<int> CountingSort(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> b(n);
    std::vector<int> count(k + 1);
    for (int i = 0; i <= k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      count[nums[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
      int x = nums[i];
      b[count[x] - 1] = x;
      count[x]--;
    }
    return b;
  }

  int CountingRange(std::vector<int>& nums, int k, int left, int right) {
    int n = nums.size();
    std::vector<int> count(k + 1);
    for (int i = 0; i < k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      count[nums[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    if (left <= 0) {
      return count[right];
    } else {
      return count[right] - count[left - 1];
    }
  }
};

Solution solution;

void TestCountingSort() {
  std::vector<int> nums = {2, 5, 3, 0, 2, 3, 0, 3};
  int k = *std::max_element(nums.begin(), nums.end());
  std::vector<int> result = solution.CountingSort(nums, k);
  clrs::PrintVector(result);
}

void TestCountingRange() {
  std::vector<int> nums = {2, 5, 3, 0, 2, 3, 0, 3};
  int k = *std::max_element(nums.begin(), nums.end());
  int left = 2;
  int right = 3;
  std::cout << solution.CountingRange(nums, k, left, right) << std::endl;
}

int main() {
  TestCountingSort();
  TestCountingRange();
}

/*
 * 0 0 2 2 3 3 3 5
 * 5
 */
