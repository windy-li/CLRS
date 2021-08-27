#ifndef CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_112_BUCKET_SORT_H_
#define CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_112_BUCKET_SORT_H_

#include "clrs.h"

class Solution {
 public:
  void BucketSort(std::vector<double>& nums) {
    int n = nums.size();
    auto buckets = std::vector<std::list<double>>(n, std::list<double>());
    for (int i = 0; i < n; ++i) {
      buckets[static_cast<int>(n * nums[i])].push_back(nums[i]);
    }
    int p = 0;
    for (int i = 0; i < n; ++i) {
      std::list<double> list = buckets[i];
      list.sort();
      for (double item : list) {
        nums[p++] = item;
      }
    }
  }
};

#endif  // CLRS_SRC_PART2_SORTING_AND_ORDER_STATISTICS_112_BUCKET_SORT_H_
