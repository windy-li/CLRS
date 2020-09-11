#include "clrs.h"

class Solution {
 public:
  void KSort(std::vector<int>& arr, int k, int p, int r) {
    if (r - p >= k) {
      int q = Partition(arr, p, r);
      KSort(arr, k, p, q - 1);
      KSort(arr, k, q + 1, r);
    }
  }

 private:
  int Partition(std::vector<int>& arr, int p, int r) {
    int i = p - 1;
    for (int j = p; j < r; j++) {
      if (arr[j] <= arr[r]) {
        i++;
        std::swap(arr[i], arr[j]);
      }
    }
    std::swap(arr[i + 1], arr[r]);
    return i + 1;
  }
};
