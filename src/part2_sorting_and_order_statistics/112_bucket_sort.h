#ifndef CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_112_BUCKET_SORT_H_
#define CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_112_BUCKET_SORT_H_

#include "clrs.h"

class Solution {
 public:
  void BucketSort(std::vector<double>& nums) {
    int n = nums.size();
    std::vector<std::vector<double>> buckets(n, std::vector<double>());
    for (int i = 0; i < n; ++i) {
      buckets[static_cast<int>(n * nums[i])].push_back(nums[i]);
    }
    int p = 0;
    for (int i = 0; i < n; ++i) {
      std::vector<double> v = buckets[i];
      std::sort(v.begin(), v.end());
      for (double item : v) {
        nums[p++] = item;
      }
    }
  }
};

#endif  // CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_112_BUCKET_SORT_H_
