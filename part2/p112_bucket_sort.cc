#include "clrs.h"

class Solution {
 public:
  void BucketSort(std::vector<double>& nums) {
    int n = nums.size();
    std::vector<double> buckets[n];
    for (int i = 0; i < n; ++i) {
      buckets[(int)(n * nums[i])].push_back(nums[i]);
    }
    int p = 0;
    for (int i = 0; i < n; ++i) {
      std::vector<double> list = buckets[i];
      std::sort(std::begin(list), std::end(list));
      for (double j : list) {
        nums[p++] = j;
      }
    }
  }
};

int main() {
  std::vector<double> nums = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.68};
  Solution s;
  s.BucketSort(nums);
  clrs::PrintVector(nums);
}

/*
 * 0.12 0.17 0.21 0.26 0.39 0.68 0.72 0.78 0.94
 */
