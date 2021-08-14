#ifndef CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_112_BUCKET_SORT_H_
#define CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_112_BUCKET_SORT_H_

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
      std::vector<double> vec = buckets[i];
      std::sort(vec.begin(), vec.end());
      for (double item : vec) {
        nums[p++] = item;
      }
    }
  }
};

#endif  // CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_112_BUCKET_SORT_H_
