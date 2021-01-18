#include "clrs.h"

class Solution {
 public:
  void RadixSort(std::vector<int>& nums) {
    // Find the maximum number to know number of digits
    int max = *std::max_element(nums.begin(), nums.end());

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
      CountingSort(nums, exp);
    }
  }

 private:
  void CountingSort(std::vector<int>& nums, int exp) {
    int n = nums.size();
    int k = 9;
    int count[k + 1];
    int output[k + 1];
    for (int i = 0; i <= k; ++i) {
      count[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      count[(nums[i] / exp) % 10]++;
    }
    // Change count[i] so that count[i] now contains
    // actual position of this digit in output[]
    for (int i = 1; i <= k; ++i) {
      count[i] += count[i - 1];
    }
    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
      int x = (nums[i] / exp) % 10;
      output[count[x] - 1] = nums[i];
      count[x]--;
    }
    // Copy the output array to nums[], so that nums[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; ++i) {
      nums[i] = output[i];
    }
  }
};

int main() {
  std::vector<int> nums = {73, 22, 93, 43, 55, 14, 28, 65, 39, 81};
  Solution s;
  s.RadixSort(nums);
}

/*
 * 81 22 73 93 43 14 55 65 28 39
 * 14 22 28 39 43 55 65 73 81 93
 * 14 22 28 39 43 55 65 73 81 93
 */
