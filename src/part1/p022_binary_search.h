#include "clrs.h"

class Solution {
 public:
  int BinarySearch(const vector<int> &a, int k) {
    int n = a.size();
    int low = 0;
    int high = n - 1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (k == a[mid]) {
        return mid;
      } else if (k < a[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return -(low + 1);
  }

  int RecursiveBinarySearch(const vector<int> &nums, int key, int low, int high) {
    if (low <= high) {
      int mid = (low + high) / 2;
      if (key == nums[mid]) {
        return mid;
      } else if (key < nums[mid]) {
        return RecursiveBinarySearch(nums, key, low, mid - 1);
      } else {
        return RecursiveBinarySearch(nums, key, mid + 1, high);
      }
    }
    return -(low + 1);
  }
};
