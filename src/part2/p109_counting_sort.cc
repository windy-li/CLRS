#include "../clrs.h"

class Solution {
 public:
  void CountingSort(std::vector<int>& nums, int len, int k, std::vector<int>& output) {
    int count[k + 1];
    for (int i = 0; i <= k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
      count[nums[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    for (int i = len - 1; i >= 0; --i) {
      int x = nums[i];
      output[count[x] - 1] = x;
      count[x]--;
    }
  }

  int CountingRange(std::vector<int>& arr, int len, int k, int left, int right) {
    int count[k + 1];
    for (int i = 0; i < k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < len; ++i) {
      count[arr[i]]++;
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

void testCountingSort() {
  std::vector<int> arr = {2, 5, 3, 0, 2, 3, 0, 3};
  int n = arr.size();
  int k = 5;
  std::vector<int> output(n);
  Solution s;
  s.CountingSort(arr, n, k, output);
}

void testCountingRange() {
  std::vector<int> arr = {2, 5, 3, 0, 2, 3, 0, 3};
  int n = arr.size();
  int k = 5;
  int left = 2;
  int right = 3;
  Solution s;
  std::cout << s.CountingRange(arr, n, k, left, right);
}

int main() {
  testCountingSort();
  testCountingRange();
}

/*
 * 0 0 2 2 3 3 3 5
 * 5
 */
