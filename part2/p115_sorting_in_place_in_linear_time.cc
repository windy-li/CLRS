#include "clrs.h"

class Solution {
 public:
  void ONAndStable(std::vector<int>& nums, std::vector<int>& output) {
    int n = nums.size();
    int index = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        output[index] = nums[i];
        index++;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 1) {
        output[index] = nums[i];
        index++;
      }
    }
  }

  void ONAndInPlace(std::vector<int>& nums) {
    int n = nums.size();
    int index = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) {
        std::swap(nums[i], nums[index]);
        index++;
      }
    }
  }

  void StableAndInPlace(std::vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
      for (int j = n - 1; j > i; --j) {
        if (nums[j] < nums[j - 1]) {
          std::swap(nums[j], nums[j - 1]);
        }
      }
    }
  }

  void CountingSortInPlace(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> c(k + 1);
    for (int i = 0; i < k; ++i) {
      c[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      c[nums[i]]++;
    }
    for (int i = 1; i <= k; ++i) {
      c[i] += c[i - 1];
    }
    for (int i = 0; i < n; ++i) {
      nums[i] = 0;
    }
    for (int i = k; i > 0; --i) {
      while (c[i] != c[i - 1]) {
        nums[c[i] - 1] = i;
        c[i]--;
      }
    }
  }
};

int main() {}
