#include "../clrs.h"

class Solution {
 public:
  void KSort(std::vector<int>& nums, int k, int p, int r) {
    if (r - p >= k) {
      int q = Partition(nums, p, r);
      KSort(nums, k, p, q - 1);
      KSort(nums, k, q + 1, r);
    }
  }

 private:
  int Partition(std::vector<int>& nums, int p, int r) {
    int i = p - 1;
    for (int j = p; j < r; ++j) {
      if (nums[j] <= nums[r]) {
        i++;
        std::swap(nums[i], nums[j]);
      }
    }
    std::swap(nums[i + 1], nums[r]);
    return i + 1;
  }
};
